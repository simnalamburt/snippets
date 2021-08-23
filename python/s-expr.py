from dataclasses import dataclass
from collections.abc import Iterator
from typing import Optional, Union

@dataclass
class BinaryTree:
    data: Optional[tuple[int, 'BinaryTree', 'BinaryTree']] = None

    def __repr__(self) -> str:
        if self.data is None:
            return '.'
        return f'({self.data[0]} {self.data[1]} {self.data[2]})'

class UnexpectedInputError(Exception):
    pass

Token = Union[int, str]

def lex(exp: str) -> Iterator[Token]:
    # '': not reading numbers
    # otherwise: reading numbers
    state: Optional[int] = None

    for ch in exp:
        # Handle number
        if '0' <= ch <= '9':
            if not state:
                state = 0
            state = 10*state + (ord(ch) - ord('0'))
            continue
        # Not number
        if state:
            yield state
            state = None

        if ch == '(' or ch == ')' or ch == '.':
            yield ch
        elif ch == ' ':
            ... # Ignore
        else:
            raise UnexpectedInputError

def parse(tokens: Iterator[Token]) -> BinaryTree:
    '''
    exp ::= '.' | triple
    triple ::= '(' + int + exp + exp + ')'
    '''
    result = expectExp(tokens)
    if next(tokens, None) is not None:
        raise UnexpectedInputError
    return result

def expectExp(tokens: Iterator[Token]) -> BinaryTree:
    token = next(tokens, None)
    if token == '(':
        return expectFirstArg(tokens)
    elif token == '.':
        return BinaryTree()
    else:
        raise UnexpectedInputError

def expectFirstArg(tokens: Iterator[Token]) -> BinaryTree:
    token = next(tokens, None)
    if isinstance(token, int):
        value: int = token
        left: BinaryTree = expectExp(tokens)
        right: BinaryTree = expectExp(tokens)
        if next(tokens, None) != ')':
            raise UnexpectedInputError

        return BinaryTree((value, left, right))
    else:
        raise UnexpectedInputError

expr = '  (10 (20 . .) ( 30 (40 . .) . ))  '

print(f'{expr = }')
print(f'{list(lex(expr)) = }')
print(f'{parse(lex(expr)) = }')
