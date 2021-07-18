import itertools

N = 10
card = [93, 181, 245, 214, 315, 36, 185, 138, 216, 295]

print('\n'.join(
    f'{s} {a:{1+a}}{b:{b-a}}{c:{c-b}}'
    for s, a, b, c in sorted(
        (card[a] + card[b] + card[c], a, b, c) for a, b, c in itertools.combinations(range(N), 3)
    )
))
