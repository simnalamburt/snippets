#!/usr/bin/env python3
LEFT_HALF = '' # '▎'

#
# 16 color
#
print('16 color:')
print(
    '\n'.join(
        ''.join(f'\x1b[48;5;{x + 8*y}m  ' for x in range(8)) + '\x1b[0m'
        for y in range(2)
    )
)
print()

#
# 256 color
#
def c8(R: int, G: int, B: int, show: bool) -> str:
    color = 16 + 36*R + 6*G + B
    return (
        f'\x1b[38;5;{246 if color <= 21 else 16};48;5;{color}m' +
        (f' {color:03} ' if show else '     ')
    )
print('256 color:')
print(
    '\n'.join(
        ''.join(
            ''.join(c8(R, g // 3, B, g % 3 == 1) for B in range(6)) + '\x1b[0m '
            for R in range(6)
        )
        for g in range(6*3)
    )
)
print()

#
# 24-bit color
#
def c24(R: int, G: int, B0: int, B1: int) -> str:
    return f'\x1b[38;2;{R};{G};{B0};48;2;{R};{G};{B1}m{LEFT_HALF}'
print('24-bit color:')
print(
    '\n'.join(
        ''.join(
            ''.join(
                c24(256 * r // 6, 256 * g // 18, 256 * b // 60, 256 * (b+1) // 60)
                for b in range(0, 6*5*2, 2)
            ) + '\x1b[0m '
            for r in range(6)
        )
        for g in range(6*3)
    )
)
print()



#
# 16 color
#
print(
    '    16 color: ' +
    ''.join(
        f'\x1b[48;5;{color}m' + count*'     '
        for color, count in [(0, 7), (8, 8), (7, 8), (15, 3)]
    ) +
    '\x1b[0m'
)

#
# 256 color
#
print(
    '   256 color: ' +
    '\x1b[48;5;16m 016 ' +
    ''.join(
        f'\x1b[38;5;{238 if color >= 245 else 249};48;5;{color}m {color:03} '
        for color in range(232, 256)
    ) +
    '\x1b[48;5;231m 231 ' +
    '\x1b[0m'
)

#
# 24-bit color
#
print(
    '24-bit color: ' +
    '\x1b[48;2;0;0;0m ' +
    ''.join(
        f'\x1b[38;2;{g};{g};{g};48;2;{g+1};{g+1};{g+1}m{LEFT_HALF}'
        for g in range(0, 256, 2)
    ) +
    '\x1b[48;2;255;255;255m ' +
    '\x1b[0m'
)
