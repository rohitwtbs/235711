# what is a singelton class
# a class which throws the same object on creating 
# new objects also

# lets first try to create an object and then check its address

import gc
class Rappers:
    first_object = None
    def __init__(self,name):
        print("first_object  ")
        print(self.first_object)
        self.name = name
        print(self.first_object == None)
        if(self.first_object == None):
            self.first_object = id(self)
        else:
            print(first_object)
            for obj in gc.get_objects():
                if (id(obj) == first_object):
                    self = obj
        # import pdb
        # pdb.set_trace()

    def print_info(self):
        print(self.name)
        
        
tupac = Rappers("tupac")
snoopdog = Rappers("snoopdog")

# tupac = Rappers()
print(tupac)
tupac.print_info()
print(snoopdog)
snoopdog.print_info()