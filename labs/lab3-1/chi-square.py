import numpy as np
import scipy.stats as stats
import importlib.util
import matplotlib.pyplot as plt


def generate_chi_square_table(df=3, max_chi_square=10, step=0.5):
    chi_values = np.arange(0, max_chi_square + step, step)
    p_values = [1 - stats.chi2.cdf(chi, df) for chi in chi_values]

    print("Chi-Square Value | p-value")
    print("----------------|--------")
    for chi, p in zip(chi_values, p_values):
        print(f"{chi:16.3f} | {p:.5f}")

    # 轉換為 C 陣列格式
    print("\nC Array Format:")
    print("typedef struct {")
    print("    double chi_square;")
    print("    double p_value;")
    print("} ChiSquareTable;")
    print("\nChiSquareTable table[] = {")
    for i, (chi, p) in enumerate(zip(chi_values, p_values)):
        comma = "," if i < len(chi_values) - 1 else ""
        print(f"    {{ {chi:.3f}, {p:.5f} }}{comma}")
    print("};")

    # 檢查是否安裝 matplotlib
    if importlib.util.find_spec("matplotlib"):
        plot_chi_square_distribution(df, max_chi_square)
    else:
        print("matplotlib 未安裝，無法顯示圖表。")


def plot_chi_square_distribution(df, max_chi_square):
    x = np.linspace(0, max_chi_square, 1000)
    y = stats.chi2.pdf(x, df)

    plt.figure(figsize=(8, 5))
    plt.plot(x, y, label=f'Chi-Square Distribution (df={df})', color='blue')
    plt.axvline(df, color='red', linestyle='--',
                label=f'Degree of Freedom (df={df})')
    plt.xlabel("Chi-Square Value")
    plt.ylabel("Probability Density")
    plt.title("Chi-Square Distribution")
    plt.legend()
    plt.grid()
    plt.show()


# 生成自由度 3 的 chi-square 表格
generate_chi_square_table()
