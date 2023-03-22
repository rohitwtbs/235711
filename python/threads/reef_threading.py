import sys
import threading

exec(sys.stdin.read())

# f() and g() are now callable
t1 = threading.Thread(name="f",target=f)
t2 = threading.Thread(name="f",target=g)
t1.start()
t2.start()
# t1.join()
# t2.join()
# print(t1.value)
print(max(t1.join(),t2.join() ))  # this is not parallel, so it won't work!





# sample input

please
# please
# please

# do not try to read this
# it is not required to understand it but
# reading through it will take time
# which will decrease your score

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
