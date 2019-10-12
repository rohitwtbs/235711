# odd sum
# determine the sum of all positive integers till n
def oddSum(n):
    noOfTermInSeries = noOfTerms(n)
    sum = sumOfTerms(noOfTermInSeries)
    print sum


def noOfTerms(n):
    if n & 1 == 0:
        num = n - 1
    else:
        num = n
    noTerm = (num + 1) / 2
    return noTerm


def sumOfTerms(noOfTerm):
    sum = pow(noOfTerm, 2)
    return sum


count = input()
while (count):
    number = input()
    oddSum(number)
    count = count - 1
