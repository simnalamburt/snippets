from decimal import Decimal
from collections.abc import Callable
from typing import Union

Number = Union[float, Decimal]

def newton_method(
    f: Callable[[Number], Number],
    f_: Callable[[Number], Number],
    x0: Number,
    count: int = 20,
) -> Number:
    '''
    Newton's Method

    f   : target function
    f_  : derivative of target function
    x0  : Initial x value
    '''
    x = x0
    print(f'{x=}')
    for _ in range(count):
        x = x - f(x)/f_(x)
        print(f'{x=}')
    return x

def secant_method(
    f: Callable[[Number], Number],
    f_: Callable[[Number], Number],
    x0: Number,
    x1: Number,
    count: int = 20,
) -> Number:
    '''
    Secant Method

    f   : target function
    f_  : derivative of target function
    x0  : First x value
    x1  : Second x value
    '''
    x_prev, x = x0, x1
    print(f'{x=}')
    for _ in range(count):
        delta_f = f(x) - f(x_prev)
        if delta_f == 0:
            break
        x_prev, x = x, x - f(x)*(x - x_prev)/delta_f
        print(f'{x=}')
    return x

newton_method(
    f=lambda x: x**2 - 4,
    f_=lambda x: 2*x,
    x0=Decimal(10),
)
secant_method(
    f=lambda x: x**2 - 4,
    f_=lambda x: 2*x,
    x0=Decimal(10),
    x1=Decimal(9),
)
