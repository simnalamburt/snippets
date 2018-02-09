import json
import sys

def foo(options):
    try:
        obj = json.loads(options)
        username = obj['username']
        password = obj['password']
    except (TypeError, json.decoder.JSONDecodeError, KeyError):
        return 'ㄴㄴ'

    return f'username={username}, password={password}'

inputs = [
    None,
    '',
    '{"password":"비번"}',
    '{"username":"유저","password":"비번"}',
]

for input in inputs:
    print(foo(input))
