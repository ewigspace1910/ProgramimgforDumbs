try:
    myFile = open("py4e\\txt.txt")
    print(myFile)
    count = 0
    for line in myFile:
        #file is tuple of char string(line)
        count = count + 1
        print(line.rstrip()) #rstrip to exhaus space  from the right side of a string
    print(count)
except:
    print("error file!")
