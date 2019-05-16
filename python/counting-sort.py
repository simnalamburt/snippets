data = [
    (48,'uxorious'),
    (2, 'ganoid'),
    (23,'tauricide'),
    (26,'mirific'),
    (49,'retrad'),
    (56,'bullyrag'),
    (36,'gynaecomania'),
    (0, 'underbreath'),
    (10,'demonography'),
    (46,'philoxenia'),
    (25,'deontic'),
    (13,'bowery'),
    (17,'karst'),
    (17,'lupicide'),
    (63,'gasiform'),
    (48,'nulliverse'),
    (2, 'xenoglossia'),
    (42,'muller'),
    (33,'xenolith'),
    (18,'remora'),
]

buf = [0]*64
for key, _ in data:
    buf[key] += 1
for i in range(1, len(buf)):
    buf[i] += buf[i - 1]

output = [None]*len(data)
for elem in data[::-1]:
    output[buf[elem[0]] - 1] = elem
    buf[elem[0]] -= 1

print(output)
print(output == sorted(data, key=lambda x:x[0]))
