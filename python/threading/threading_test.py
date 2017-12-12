#!/bin/python


from threading import Thread
import time

def _sum(x, y):
    print("Compute {} + {}...".format(x, y))
    time.sleep(2.0)
    return x+y
def compute_sum(x, y):
    result = _sum(x, y)
    print("{} + {} = {}".format(x, y, result))

start = time.time()    
threads = [
    Thread(target=compute_sum, args=(0,0)),
    Thread(target=compute_sum, args=(1,1)),
    Thread(target=compute_sum, args=(2,2)),
]
for t in threads:
    t.start()
for t in threads:
    t.join()
print("Total elapsed time {} s".format(time.time() - start))

# Do not use Thread
start = time.time()
compute_sum(0,0)
compute_sum(1,1)
compute_sum(2,2)
print("Total elapsed time {} s".format(time.time() - start))
