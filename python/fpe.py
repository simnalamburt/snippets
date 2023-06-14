from string import ascii_lowercase
from sys import stdin
from re import finditer
from itertools import chain, pairwise

from ff3 import FF3Cipher

c = FF3Cipher.withCustomAlphabet('FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF', 'FFFFFFFFFFFFFF', ascii_lowercase)

for line in stdin:
    plaintext = line[19:-1]
    idxs = chain([0], (m.start() - i for i, m in enumerate(finditer('_', plaintext))), [len(plaintext)])
    ciphertext = c.encrypt(plaintext.replace('_', ''))
    ciphertext_formatted = '_'.join(ciphertext[a:b] for a, b in pairwise(idxs))
    print(f'*RowsEvent\tREDACTED.{ciphertext_formatted}')
