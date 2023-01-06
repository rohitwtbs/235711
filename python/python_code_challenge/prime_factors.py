
import math

class Prime:
    def __init__(self):
        pass

    def generates_primes(self,num):
        not_prime = False
        for i in range(2,math.ceil(math.sqrt(num))):
            print(num , i)
            print(num % i)
            if num % i == 0:
                not_prime = True
        if not not_prime:
            print("prime no ",num)


p = Prime().generates_primes(7919)
            


