from os import write
from socket import socket, AF_INET, SOCK_STREAM
from threading import Thread
from time import sleep

sock = socket(AF_INET, SOCK_STREAM)
sock.connect(('127.0.0.1', 8000))

def writer():
	while True:
		sock.send(b';1;;')
		sleep(1)
		sock.send(b';2;;')
		sleep(1)
writer_thread = Thread(target=writer)
writer_thread.start()

while (data := sock.recv(1024)) != b'':
	write(1, data)

writer_thread.join()
