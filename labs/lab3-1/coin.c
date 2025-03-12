#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 事先建好的 p-value 查表 (這裡只列出部分數值)
typedef struct {
    double chi_square;
    double p_value;
} ChiSquareTable;

ChiSquareTable table[] = {
    {0.000, 1.00000}, {0.500, 0.91889}, {1.000, 0.80125}, {1.500, 0.68227},
    {2.000, 0.57241}, {2.500, 0.47529}, {3.000, 0.39163}, {3.500, 0.32076},
    {4.000, 0.26146}, {4.500, 0.21229}, {5.000, 0.17180}, {5.500, 0.13864},
    {6.000, 0.11161}, {6.500, 0.08966}, {7.000, 0.07190}, {7.500, 0.05756},
    {8.000, 0.04601}, {8.500, 0.03673}, {9.000, 0.02929}, {9.500, 0.02333},
    {10.000, 0.01857}};
const int table_size = sizeof(table) / sizeof(table[0]);

int rand_num(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}

// 自訂翻硬幣
int myflip(int type, int invert) {
    int flip = 0;
    switch (type) {
    case 0:  // 10:0
        flip = 0;
    case 1:  // 9:1
        flip = rand_num(0, 100) > 10 ? 0 : 1;
    case 2:  // 8:2
        flip = rand_num(0, 100) > 10 ? 0 : 1;
    case 4:  // 6:4
        flip = rand_num(0, 100) > 10 ? 0 : 1;
    default:
        flip = rand_num(0, 1);
    }
    return invert ? !flip : flip;
}

// 模擬投擲兩枚硬幣
void toss_coins(int *heads_heads,
                int *heads_tails,
                int *tails_heads,
                int *tails_tails,
                int rounds) {
    for (int i = 0; i < rounds; i++) {
        int coin1 = myflip(-1, 0) % 2;  // 0: Tails, 1: Heads
        int coin2 = myflip(-1, 0) % 2;  // 0: Tails, 1: Heads

        if (coin1 == 1 && coin2 == 1) {
            (*heads_heads)++;
        } else if (coin1 == 1 && coin2 == 0) {
            (*heads_tails)++;
        } else if (coin1 == 0 && coin2 == 1) {
            (*tails_heads)++;
        } else {
            (*tails_tails)++;
        }
        printf("\r%d/%d", i, rounds);
    }
}

// 計算 Chi-Square 值
double calculate_chi_square(int heads_heads,
                            int heads_tails,
                            int tails_heads,
                            int tails_tails,
                            int rounds) {
    double expected = rounds / 4.0;  // 預期次數（均勻分佈）

    double chi_square =
        ((heads_heads - expected) * (heads_heads - expected)) / expected +
        ((heads_tails - expected) * (heads_tails - expected)) / expected +
        ((tails_heads - expected) * (tails_heads - expected)) / expected +
        ((tails_tails - expected) * (tails_tails - expected)) / expected;

    return chi_square;
}

// 查表找 p-value
double get_p_value(double chi_square) {
    for (int i = 0; i < table_size - 1; i++) {
        if (chi_square <= table[i].chi_square) {
            return table[i].p_value;
        }
    }
    return 0.0;  // 若超過範圍，則假設 p-value 極小
}

int main() {
    srand(time(NULL));  // 設定隨機種子

    int heads_heads = 0, heads_tails = 0, tails_heads = 0, tails_tails = 0;
    int rounds;

    printf("請輸入投擲次數: ");
    scanf("%d", &rounds);

    toss_coins(&heads_heads, &heads_tails, &tails_heads, &tails_tails, rounds);

    printf("\n投擲結果:\n");
    printf("正面-正面: %d 次\n", heads_heads);
    printf("正面-反面: %d 次\n", heads_tails);
    printf("反面-正面: %d 次\n", tails_heads);
    printf("反面-反面: %d 次\n", tails_tails);

    double chi_square = calculate_chi_square(heads_heads, heads_tails,
                                             tails_heads, tails_tails, rounds);
    double p_value = get_p_value(chi_square);

    printf("\nChi-Square 值: %.3f\n", chi_square);
    printf("p-value: %.3f\n", p_value);

    // 驗證 p-value 是否低於顯著水準 a = 0.05
    if (p_value < 0.05) {
        printf("結果\033[32m顯著\033[0m (拒絕 H0)\n");
        printf("投擲結果可能是\033[31m不公平\033[0m的\n");
    } else {
        printf("結果\033[31m不顯著\033[0m (無法拒絕 H0)\n");
        printf("投擲結果可能是\033[32m公平\033[0m的\n");
    }

    return 0;
}
