#!/usr/bin/python3

from threading import Thread, Lock
import time
_base = 1
_lock = Lock()
class ComputeSum(Thread):
    def __init__(self, x, y):
        super(ComputeSum, self).__init__()
        self.x = x
        self.y = y
    def run(self):
        result = self._sum(self.x, self.y)
        print("{} + {} + base = {}".format(self.x, self.y, result))
    def _sum(self, x, y):
        print("Compute {} + {}...".format(x, y))
        time.sleep(2.0)
        global _base
        with _lock:
            result = x + y + _base
            _base = result
        return result
threads = [ComputeSum(0,0), ComputeSum(1,1), ComputeSum(2,2)]

start = time.time()
for t in threads:
    t.start()
for t in threads:
    t.join()
print("Total elapsed time {} s".format(time.time() - start))
