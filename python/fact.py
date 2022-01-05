class Factorial:
    def __init__(self,num):
        self.num = num

    def get_factorial(self):
        fib_num = 1
        for i in range(1,self.num + 1):
            fib_num = fib_num * i;
        return fib_num

f1=Factorial(3)
print(f1.get_factorial())

