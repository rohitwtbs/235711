# make class stack which has push,pop and show functionaity
# heavily use oops to do it

class Stack:
    def __init__(self):
        self.stack_of_elements = []
        return None

    def push(self, element):
        self.stack_of_elements.append(element)
        return None

    def pop(self):
        poped_element = self.stack_of_elements.pop()
        print('Element popped from stack ',poped_element)
        return poped_element

    def show(self):
        print('Current stack elements bottom---------> top')
        for i in self.stack_of_elements:
            print(i)
        return None


s = Stack()
s.push(2)
s.push(6)
s.push(56)
s.push(234)
s.show()
s.pop()
s.show()
