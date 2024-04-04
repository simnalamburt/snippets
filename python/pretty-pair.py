# Reference:
#   https://twitter.com/cog25_/status/1775728377477165211
#   https://colab.research.google.com/drive/1DML8q3-BXZ89EmuDxmNuMXn5ZkDmGy3i?usp=sharing

# Treat binary number as a decimal number.
#
# Example:
#   f(0b1010) => 1010
#   f(0b1111) => 1111
#
# 0 <= n <= 0b10_000_000_000_000_000_000
# 0 <= returned value <= 10_000_000_000_000_000_000
def f(n: int) -> int:
    digit = 1
    ret = 0
    while n:
        ret += (n & 1) * digit
        digit *= 10
        n >>= 1
    return ret

N = 0b100000000

print(
    '\n'.join(
        ''.join(
            '#' if f(a) & f(b) == f(a & b) else ' ' for b in range(N)
        ) for a in range(N)
    )
)
