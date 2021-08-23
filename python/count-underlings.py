CORP = {
    1: [2, 3, 4],
    2: [],
    3: [5, 6],
    4: [7, 8, 9],
    5: [],
    6: [10, 11],
    7: [12, 13],
    8: [],
    9: [],
    10: [],
    11: [],
    12: [],
    13: [],
}

def countUnderlings(idx: int) -> int:
    return sum(1 + countUnderlings(member) for member in CORP[idx])

print(f'{countUnderlings(1)=}')
print(f'{countUnderlings(3)=}')
