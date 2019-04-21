def find(tree: tuple, query: str):
    # Early return
    if tree is None:
        return None

    # Invariant: tree = 튜플
    idx, left, right = tree
    key, value = TABLE[idx]

    if key < query:
        # 오른쪽 서브트리를 탐색해야함
        return find(right, query)
    elif key > query:
        # 왼쪽 서브트리를 탐색해야함
        return find(left, query)
    else: # key == query
        return value

def range_query(tree: tuple, lo: str, hi: str) -> list:
    '''
    함수를 쓸때 lo < hi 가 되도록 짜주세요
    '''

    # 조기 반환
    if tree is None:
        return []

    # Invariant:
    #   tree = 튜플
    #   lo < hi
    #   tree는 BST의 성질을 만족한다
    idx, left, right = tree
    key, value = TABLE[idx]

    if key < lo:
        return range_query(right, lo, hi)
    elif key == lo:
        return [(key, value)] + range_query(right, lo, hi)
    elif lo < key < hi:
        return range_query(left, lo, hi) + [(key, value)] + range_query(right, lo, hi)
    elif key == hi:
        return range_query(left, lo, hi) + [(key, value)]
    else: # hi < key
        return range_query(left, lo, hi)


TABLE = [
    ('elephant', '코끼리'),
    ('cat', '고양이'),
    ('bird', '새'),
    ('dog', '개'),
    ('tiger', '호랑이'),
    ('zebra', '지브라'),
]

BST = [
    0,
    [1, [2, None, None], [3, None, None]],
    [4, None, [5, None, None]],
]

#while True:
#    query = input('쿼리를 입력하세요: ')
#    result = find(BST, query)
#    print(repr(result))
#    print()

while True:
    lo = input('하한을 입력하세요: ')
    hi = input('상한을 입력하세요: ')
    result = range_query(BST, lo, hi)
    print(repr(result))
    print()
