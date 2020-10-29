class Test:
    #attribute / property
    name = "Test Object"

    #method
    def declare(self):
        print(self.name)

#main
testA = Test()
testA.declare()

#constructor and destructor
class PartyAnimal:
    x = 0
    name = ''
    def __init__(self, nam):
        self.name = nam
        print(self.name,'constructed')
    def party(self) :
        self.x = self.x + 1
        print(self.name,'party count',self.x)
    def __del__(self):
        print("destructor has called!\n")

s = PartyAnimal('Sally')
j = PartyAnimal('Jim')
s.party()
j.party()
s = 3
print(s, " -- s khong con tham chieu, Obj cu bi mat lien ket")

