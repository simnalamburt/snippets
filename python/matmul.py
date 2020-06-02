# 0 ~ 15
# 16 ~ 31
# ...
#
#
# *
#
# 256 ~ 272

print(
    '\n'.join(
        ' '.join(
            f'{a:03}*{b:03}' for (a, b) in
            zip(range(start*16, start*16 + 16), range(256, 272))
        )
        for start in range(16)
    )
)
print()
result = sum(
    sum(
        a*b for (a, b) in
        zip(range(start*16, start*16 + 16), range(256, 272))
    )
    for start in range(16)
)
print(result)
