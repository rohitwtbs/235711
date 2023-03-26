# my questions
# what if the thread takes a lot of time to calculate 
# and before it is able to calculate we try to get the data from the queue

import threading
import queue

def worker(q):
    for i in range(1,10):
        print(i)
    q.put("Hello from the worker thread!")


def worker2(q):
    for i in range(1,10):
        print(i,"worker 2")

q = queue.Queue()

t = threading.Thread(target=worker, args=(q,))
result = q.get()
t2 = threading.Thread(target=worker2, args=(q,))
t.start()
t2.start()

t.join()

print(result)