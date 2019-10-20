# print and edit string show
"""
we used to used a method of string class is .fomat()
now we be going to learn more usefull methods help you in showing string
"""

string = "hello ! i\'m Duc Anh_niichan"
# so ki tu trong chuoi
c=string.__len__()
print(c);

# cat string ->list
b = string.split()
print(b)

# partition tuong tu splist nhung cat chuoi thanh 3 phan tu vi tri chuoi trong ()
b = string.partition(!)
print(b)

# dem so lan xuat hien cua ki tru c
print(string.count('i',0,20)) # tu vi tri 0->20, neu bo thi tim toan day

# int find : y nhu cai ten, tra ve gia tri int
print(string.find('hello'))

# replace('can thay', 'thay')
# center(int,char) can 2 ne chung taam
print(string.center(20,'-'))
#capitalize viet hoa chu cai dau tien
#upper -> viet hoa toan bo
#lower -> viet thuong toan bo

#to reverse a string , metion 1
string = input()
print(string[::-1])