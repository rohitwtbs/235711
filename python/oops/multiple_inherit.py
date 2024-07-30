

class A:
    def __init__(self):
        return
    def check(self):
        a = 10
        print(a)
class B:
    def __init__(self):
        pass
    def check(self):
        b=11
        print(b)
    
# class C(A,B):
#     def __init__(self):
#         pass
#     def call(self):
#         print("call called")



class C(B,A):
    def __init__(self):
        pass
    def call(self):
        print("call called")
    def check(self):
        print("the call before the super")
        super().check()

class D(C):
    def __init__(self):
        pass

obj_c = C()
obj_c.call()
obj_c.check()

obj_d =D()
obj_d.check()