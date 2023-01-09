# with open('input.txt') as f:
#     with True:
#         line = f.readline()
#         print(line)
#         if(line ==  "halt"):
#             break

with open('input.txt') as f:
    while True:
        line = f.readline()
        if line == "halt":
            break
        print(line.strip())