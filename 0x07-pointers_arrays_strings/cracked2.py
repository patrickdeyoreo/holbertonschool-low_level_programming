#!/usr/bin/env python3

import hashlib

target='e99a18c428cb38d5f260853678922e03'

password = '\0'
m = hashlib.md5('\0'.encode())
with open('top1575-probable-v2.txt', 'r') as wordfile:
    while m.hexdigest() != target and password != '':
        password = wordfile.readline().strip()
        print('passwd: {}'.format(password))
        m = hashlib.md5(password.encode())
        print('digest: {}'.format(m.hexdigest()))

if m.hexdigest() == target:
    print('Success!')
    print('Password: {}'.format(password))
else:
    print('Password not found...')
