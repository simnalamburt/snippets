from os import mkdir
from xml.etree.ElementTree import iterparse

mkdir('output')

def e(name: str) -> str:
    return '{http://www.mediawiki.org/xml/export-0.11/}' + name

NAME = 'wikiteam.xml'
for _, elem in iterparse(NAME, events=['end']):
    if elem.tag != e('page'):
        continue

    # 넘겨주기는 스킵
    if elem.find(e('redirect')) is not None:
        continue

    # 일반 문서에만 관심있음
    if elem.find(e('ns')).text != '0':
        continue

    identifier = elem.find(e('id')).text
    title = elem.find(e('title')).text
    text = elem.find(e('revision')).find(e('text')).text

    filename = f'output/{identifier}.txt'
    content = f'''\
제목: {title}
내용:


{text}
'''
    with open(filename, 'w') as file:
        file.write(content)
    print(title)
