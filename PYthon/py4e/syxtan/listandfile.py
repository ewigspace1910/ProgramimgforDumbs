#  split the line into a list of words
try:
    myfile = open("py4e\\txt.txt")
    mylist = []
    for line in myfile:
        line = line.replace("[","").replace("]","").replace("\'","")
        words = line.rstrip().lower().split(",")
        for word in words:
            if (len(word) > 0 and not(word in mylist) ):
                mylist.append(word)
    
    print(mylist)
except:
    print("==================ERROR==================")