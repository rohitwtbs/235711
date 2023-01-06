import sys

count = 0

for argument in sys.argv:
    print(argument)
    print("count is ", count)
    count = count + 1