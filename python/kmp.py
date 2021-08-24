from collections.abc import Iterator

def getPI(query: str) -> list[int]:
    length = len(query)
    pi = [0]*length
    begin = 1
    matched = 0
    while begin + matched < length:
        if query[matched] == query[begin + matched]:
            matched += 1
            pi[begin + matched - 1] = matched
        elif matched == 0:
            begin += 1
        else:
            begin = begin + matched - pi[matched - 1]
            matched = pi[matched - 1]
    return pi

def KMP(string: str, query: str) -> Iterator[int]:
    pi = getPI(query)
    begin = 0
    matched = 0
    while begin + matched < len(string):
        if query[matched] == string[begin + matched]:
            matched += 1
            if matched == len(query):
                yield begin
                begin += matched - pi[matched - 1]
                matched = pi[matched - 1]
        elif matched == 0:
            begin += 1
        else:
            begin += matched - pi[matched - 1]
            matched = pi[matched - 1]

P = 'aabaabac'
print(f'{P = }')
print(f'{getPI(P) = }')

print()
print(f'{list(KMP("aabaabac", "a")) = }')
print(f'{list(KMP("aabaabac", "aab")) = }')
