state = 1
def getrandom() -> int:
    global state
    state = (state * 1103515245 + 12345) & 0xffffffff
    return (state // 65536) % 32768

def main():
    count = [0] * 32768
    total_count = 10000000
    for _ in range(total_count):
        count[getrandom()] += 1

    # Chi-squared test
    e_i = total_count / 32768
    chi_square = sum((o_i - e_i)**2 / e_i for o_i in count)

    print(f"Chi-squared: {chi_square:.2f}")

if __name__ == "__main__":
    main()
