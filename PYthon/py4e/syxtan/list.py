#list is sequence element/item and can mutable
try:
    myList = []
    s = "string"
    myList.append(s)
    for char in s:
        myList.append(char)
    print("my list : ", myList)
    myList[0] = "hihi"
    print(myList)

except:
    print("error 404!")


#nest list(array two axis) 

myList = [[12,1],[2,3]]
print(myList)
print(myList[1][1])

#traversal
numbers = [1,2,3,4]
for i in range(len(numbers)):
    numbers[i] = numbers[i] * 2
print(numbers)

for num in numbers: #This works well if you only need to read the elements of the list. But if you want
    num = num * 0   #to write or update the elements, you need the indices
print(numbers)

#trick
numbers2 = numbers[1:3] # it return copy value
print(numbers2)
numbers2[0] = 0
print(numbers, " | ", numbers2)

numbers[1:3] = numbers2 #trick assign throung slice
print(numbers)

print(numbers.sort(), " | sort ->" , numbers)

#list(object) is argurment
numbers = [1,2,3,4,5]
def changeList(testList):
    testList[1] = -1
    testList.pop()
changeList(numbers)
print(numbers) #same Java
