import sys
import threading
import pdb

def _mysleep(how_long: int):
    # time.sleep is bugged on evalgrounds
    import asyncio
    loop = asyncio.new_event_loop()
    try:
        loop.run_until_complete(asyncio.sleep(how_long))
    finally:
        loop.close()

def f(a=None):
    _mysleep(1)
    return 2

def g(a=None):
    _mysleep(1)
    return 1

t1 = threading.Thread(name="f",target=f)
t2 = threading.Thread(name="f",target=g)
t1.start()
t2.start()
pdb.set_trace()

print(max(t1.join(),t2.join() ))