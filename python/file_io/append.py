import time
filename = "test.txt"
file = open(filename, 'w+') # w+ is to append new lines to the file
while True:
    file.write("time\n")
    print("time\n")
    time.sleep(0.1)