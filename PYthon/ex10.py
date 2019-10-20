#reading file
from sys import argv
'''
filename = argv
txt =open(filename)
print(f"here's your file {filename} : ")
print(txt.read())
'''
print(("type the your file agains : "))
file_again = input('> ')
text_again = open(file_again)
print(text_again.read())
