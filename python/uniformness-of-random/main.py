import random
import secrets
from scipy.stats import chi2

state = 0

def somerand_init(seed: int = 1) -> None:
    global state
    state = seed & 0xffffffff

def somerand_get() -> int:
    global state
    state = (state * 1103515245 + 12345) & 0xffffffff
    return (state // 65536) % 32768

def chi_square_test(rand : callable) -> float:
    bins = [0] * 32768
    sample_num = 10000000
    for _ in range(sample_num):
        bins[rand()] += 1

    # Chi-squared test
    e_i = sample_num / len(bins)  # Expected frequency for each bin
    chi_square = sum((o_i - e_i)**2 / e_i for o_i in bins)
    degrees_of_freedom = len(bins) - 1  # Number of bins - 1
    p_value = chi2.sf(chi_square, degrees_of_freedom)

    return p_value

def main():
    random.seed(1)
    somerand_init(1)

    print(f"""\
           | P-value
-----------|-------------------
random     | {chi_square_test(lambda: random.randrange(32768))}
secrets    | {chi_square_test(lambda: secrets.randbelow(32768))}
somerand() | {chi_square_test(somerand_get)}
""")

if __name__ == "__main__":
    main()
