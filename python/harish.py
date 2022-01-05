# 2) Write a function checkInput() that takes 2 inputs - type (string) and amount (integer) and prints a message.
# Using switch-case is not allowed and do not use more than 3 if-else blocks.


def comparator(numberInput,type,validationArray):
    if numberInput>=validationArray[0] and numberInput<=validationArray[1]:
        print(type +' is Valid')
    else:
        print (type +' is Invalid')


def checkInput(typeInput,numberInput):
    typeDict = dict(hour='Hourly Wage', day='Daily Wage', week='Weekly Wage', month='Monthly Salary',
                    year='Annual Salary')
    validationArrayDict = dict(hour=[10, 100],
                               day=[70, 600],
                               week=[300, 3000],
                               month=[1200, 12000],
                               year=[14000, 140000]
                               )
    comparator(numberInput,typeDict[typeInput.lower()],validationArrayDict[typeInput.lower()])


checkInput('Day',80)
checkInput('DAY', 630)
checkInput('month', 11999)
checkInput('month', 12999)