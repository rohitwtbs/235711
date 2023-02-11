def summation(args):
    print("call in summation")
    return sum(args)

def main(f,args):
    print("call in main")
    return f(args)

if __name__ == "__main__":
    # passing a fucntion as an argument
    print(main(summation, [1,2,3]))
