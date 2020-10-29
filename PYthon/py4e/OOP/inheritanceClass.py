from classSimple import Test # thuc hien cau lenh trong test neu co

class MathTest(Test):
    numQuess = 0

    def __init__(self):
        super().__init__() #super to call father's method
        self.name = "Toan"
        self.numQuess = 10
    
    def __del__(self):
        print("Del Obj!")

    def declare(self):
        super().declare()
        print("Number Question : ", self.numQuess)
    
#main

ex1 = MathTest()
ex1.declare()
