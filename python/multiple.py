class A:
    def abc(self):
        print("a")
class B:
    def abc(self):
        print("b")
class C:
    def abc(self):
        print("c")

class D(B,C):
    def abc(self):
        pass

d=D()
d.abc()
