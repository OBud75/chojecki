import multiporcessing
import os

name = [1, 2]
print(os.getppid())

def print_hello():
	os.fork()	
	for _ in range(10):
		print(f"hello from process {os.getppid()}")

p1 = multiprocessing.Process(target=print_hello)
p1.start()

def print_hi():
	for _ in range(10):
		print(f"Hi forom process {os.getppid()}")

p2 = multiprocessing.Process(target=print_hi)
p2.start()
