def nthprime(n: int) -> int:
    '''
    Returns nth prime number.

    Reference:
        https://stackoverflow.com/a/48040385/13977061
    '''
    start = 2
    count = 0
    while True:
        if all([start % i for i in range(2, int(start**0.5 + 1))]):
            count += 1
            if count == n:
                return start
        start += 1

print(nthprime(1) == 2)
print(nthprime(2) == 3)
print(nthprime(3) == 5)
print(nthprime(4) == 7)
print(nthprime(5) == 11)
print(nthprime(6) == 13)
print(nthprime(7) == 17)
print(nthprime(8) == 19)
print(nthprime(9) == 23)
print(nthprime(10) == 29)
print(nthprime(100) == 541)
