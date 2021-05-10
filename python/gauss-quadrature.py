from decimal import Decimal
from collections.abc import Callable
from math import exp

def gauss_quadrature_3(f: Callable[[Decimal], Decimal]) -> Decimal:
    return (
        f(Decimal('-0.77459_66692')) * 5/9 +
        f(Decimal(0)) * 8/9 +
        f(Decimal('+0.77459_66692')) * 5/9
    )

print(gauss_quadrature_3(lambda t:2/(1 + (2*t + 3)**2)))
print()
print(gauss_quadrature_3(lambda t:2*exp(6*t+6)))
