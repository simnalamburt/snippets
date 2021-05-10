from decimal import Decimal
from collections.abc import Callable
from typing import TypeVar, Union

Number = Union[float, Decimal]

def euler(
    f: Callable[[Number, Number], Number],
    init: tuple[Number, Number],
    h: Number, n: int,
) -> Number:
    x0, y = init
    for i in range(n):
        x = x0 * i*h
        k1 = h*f(x, y)
        y = y + k1
    return y

def improved_euler(
    f: Callable[[Number, Number], Number],
    init: tuple[Number, Number],
    h: Number, n: int,
) -> Number:
    x0, y = init
    for i in range(n):
        x = x0 + i*h
        k1 = h*f(x,     y)
        k2 = h*f(x + h, y + k1)
        y = y + (k1 + k2)/2
    return y

def rk(
    f: Callable[[Number, Number], Number],
    init: tuple[Number, Number],
    h: Number, n: int,
) -> Number:
    x0, y = init
    for i in range(n):
        x = x0 + i*h
        k1 = h*f(x,         y)
        k2 = h*f(x + h/2, y + k1/2)
        k3 = h*f(x + h/2, y + k2/2)
        k4 = h*f(x + h,     y + k3)
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6
    return y

def rkf(
    f: Callable[[Number, Number], Number],
    init: tuple[Number, Number],
    h: Number, n: int,
) -> Number:
    x0, y = init
    for i in range(n):
        x = x0 + i*h
        k1 = h*f(x, y)
        k2 = h*f(x + h*1/4,     y + k1*1/4)
        k3 = h*f(x + h*3/8,     y + k1*3/32         + k2*9/32)
        k4 = h*f(x + h*12/13,   y + k1*1923/2197    - k2*7200/2197  + k3*7296/2197)
        k5 = h*f(x + h,         y + k1*439/216      - k2*8          + k3*3680/513   - k4*845/4104)
        k6 = h*f(x + h*1/2,     y - k1*8/27         + k2*2          - k3*3544/2565  + k4*1859/4104 - k5*11/40)
        y = y + k1*16/135 + k3*6656/12825 + k4*28561/56430 - k5*9/50 + k6*2/55
    return y

f = lambda x, y: 2*x*y
init = (Decimal(1), Decimal(1))
h = Decimal(0.1)

print(euler(f, init, h=h, n=10))
print(improved_euler(f, init, h=h, n=10))
print(rk(f, init, h=h, n=10))
print(rkf(f, init, h=h, n=10))
