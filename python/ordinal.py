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
