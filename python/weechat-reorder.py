# $PATH에 GNU coreutils와 fd, rg 바이너리가 존재해야한다.
#
# References:
#   https://github.com/BurntSushi/ripgrep
#   https://github.com/sharkdp/fd

import os
import re
import sys

from collections import OrderedDict
from configparser import ConfigParser
from subprocess import check_output

class ConfigParserMultiValues(OrderedDict):
    def __setitem__(self, key, value):
        if isinstance(value, list) and key in self:
            self[key].extend(value)
        else:
            super().__setitem__(key, value)

    @staticmethod
    def getlist(value):
        return value.split(os.linesep)

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


#
# ~/.weechat/weechat.conf 파싱
#
parser = ConfigParser(
    strict=False,
    empty_lines_in_values=False,
    dict_type=ConfigParserMultiValues,
    converters={ 'list': ConfigParserMultiValues.getlist },
)
parser.read(os.path.expanduser('~/.weechat/weechat.conf'))
lines = parser.getlist('layout', 'default.buffer')

p = re.compile(r'irc;(ozinger|uriirc)\.(#\w+?);')
channels = {
    (r.group(1), r.group(2).lower())
    for r in (p.search(e) for e in lines) if r
}


#
# 자주 들어가는 채널 검사
#
out = check_output(r'''
fd -tf '#' ~/.weechat/logs |
    xargs -n 1 -P 8 sh -c 'echo $(rg "^2018.*\t@?(?:지현|지현_)\t" "$0" | wc -l) $0' |
    sort -rn |
    awk '{print $2}'
''', shell=True, encoding='utf-8')
lines = out.split(os.linesep)

p = re.compile(r'irc\.(ozinger|uriirc)\.(#\w+?).weechatlog$')
rank = [
    (r.group(1), r.group(2).lower())
    for r in (p.search(e) for e in lines) if r
]

# 채널 랭킹 중에서 나간 채널 제외
rank = list(filter(channels.__contains__, rank))
set_rank = set(rank)

# 채널 랭킹과 현재 채널 목록이 동일한지 재확인
if channels != set_rank:
    diff = channels.difference(set_rank) | set_rank.difference(channels)

    eprint('현재 채널 목록과 채널 랭킹이 일치하지 않습니다.')
    eprint()
    eprint('두 리스트중 한곳에서만 나타나는 채널 목록:')
    for elem in diff:
        eprint(f'    - {elem}')
    eprint()
    eprint('데이터를 검토해 주세요.')
    sys.exit(1)


#
# 계산
#
msg = os.linesep.join(
    f'/buffer {server}.{channel}{os.linesep}/buffer move {no}'
    for no, (server, channel) in enumerate(rank, 2)
)

print(msg)
