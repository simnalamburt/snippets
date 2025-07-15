def von_neumann_ordinal(n : int) -> frozenset:
    """
    Represents the Von Neumann ordinal 'n' as a set of its predecessors.
    """
    if n == 0:
        return frozenset()
    else:
        return frozenset(von_neumann_ordinal(i) for i in range(n))

def von_neumann_ordinal_str(n : int) -> str:
    """
    String representation version of von_neumann_ordinal(n)
    """
    if n == 0:
        return '{}'
    else:
        return '{' + ', '.join(nat(i) for i in range(n)) + '}'

def n(i : int) -> str:
    """
    Optimized version of von_neumann_ordinal_str(n)
    """
    if i == 0:
        return '{}'
    if i == 1:
        return '{{}}'

    prev = n(i - 1)
    return '%s, %s}' % (prev[:-1], prev)

def l(i : int) -> int:
    """
    l(i)  = len(n(i))

    l(0)     = 2
    l(1)     = 4
    l(i)     = 2 * l(i-1) + 2

    l(i) + 2 = 2 * (l(i-1) + 2) = 2**(i-1) * (l(1) + 2)

    Conclusion:
        lambda i: 3 * 2**i - 2 if i > 0 else 2
    """
    return 3 * 2**i - 2 if i > 0 else 2
