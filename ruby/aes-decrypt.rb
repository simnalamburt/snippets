require 'openssl'
require 'base64'

include OpenSSL


# password
print '비밀번호를 입력하세요 : '
`stty -echo`
password = gets.chomp
`stty echo`

# salt, iv, encrypted
salt      = Base64.decode64('bjIDUMirqn7zE26IAyXrdQ==')
iv        = Base64.decode64('oHdPp9IuEDV6en8A')
auth_tag  = Base64.decode64('mWEz+b13o2Pd6sliZhxzSA==')
encrypted = Base64.decode64(<<BASE64)
GdU2yyTMSLXmygQuPDVEvk3QREodwjBrx2AE5kuHWy9bQeahOQFNeQGnaCX5
7B0ty673EzWDSq+j3oMGtlOKUa1ZUJRfEFoSbQbBZ2TS7R7thDn9t8uZPyQG
7P2j1HsCLwGUzAFng8e3ZSZygYs+yxMlD9LDaGVpEKtecfAWkYaTbGaKz9SD
1Utk2gEy3QGgvppMyL0aoIdkv2bemF3czUkZ4nd33iFXjO6tVTRkqQFhdatM
djOFHM43tUwClWpL47tfuQo4nOvSwdHk1NIr9IhIvXWeYO1jm5gwafGyswDw
cprIjHMkUarWP8l+7yRnigsA8hXhX/SKJ5/OjN/VcgK2xJji/TkvuqZtsWub
l8Eakhd8lfcMDsvFGRefTkSdJFdoOT8MOltJ5QUvgZSdgliMAMJI3AaNpzkb
hYzzMUZZU7CCQf/40bMo/+/aarA6LcLQQxw5sMTxKb+qI0JHWUbTZUzAy9KZ
ESamXbOFq0tvBkjZ7bnfdWAueHNhifSxJHKkMDo4QX2ISFY04pMwUpaPSMvW
R8NjBUjqlNj/sEoR3XC3kDBuhjs9+xXXbvzWLj0TECDTMcQ5CKqGSX9swNw/
x1f9Yd93d/dgka/+t2yB0q8ZqLOS5sHzP+ksCV6D2ZCbQlkyISKE3hK7pNaZ
pf9aw/Lo6kg1EQwN8lp3xyzsZmmOo7lv1RhBY6yNlXo841Perj1pPJfh4Zw0
JLQ6Au1Wv1YEnQt6/HxAmyVPBOsG4N4Dl32NCoB7oHcdc720bhvBd+kgrsxU
4ImIFKtpUwUDhJIyD4Xq/64roeF05dryaN0tzxaFwl6ICZQW0urB31Msz2g9
XqYxXUrnZFzcM5o8lGa6xuUaZjV6QczyPvBXGcCMtzU8vT5CnM+npQ0vdoRh
J9m3ir2062R8nB2GQFudt55obp1GEWv4bdeieEGt
BASE64

# decrypt
decipher = Cipher.new('aes-256-gcm')
decipher.decrypt
decipher.key       = PKCS5.pbkdf2_hmac_sha1(password, salt, 20000, 32)
decipher.iv        = iv
decipher.auth_tag  = auth_tag
decipher.auth_data = ''

plain = decipher.update(encrypted) + decipher.final

puts ''
puts ''
puts '------------------------'
puts plain
puts '------------------------'
