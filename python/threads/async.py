from threading import *


def new():
    for x in range(6):
        print "child executing"
t1 = Thread(target=new)
t1.start()
print "bye"
print "bye"
print "bye"