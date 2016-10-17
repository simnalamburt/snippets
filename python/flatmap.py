# Python 3
from itertools import chain

def flatmap(func, *iterable):
    '''
    Map a function over a collection and flatten the result by one-level
    '''
    return chain.from_iterable(map(func, *iterable))


A = [1, 2, 3, 4, 5]
B = ['a', 'b', 'c']

result = flatmap(
    lambda a: ('{}{}'.format(a, b) for b in B),
    A
)

print(list(result))
