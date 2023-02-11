from abc import ABC
class Abstract(ABC):
    @abstractmethod
    def exec(self):
        return


class InheritfromAbstract(Abstract):
    def __init__(self):
        print("call in inheritancefromabstract")
        return
    
