import re
mylist = []
try:
    myfile = open("mailbox.txt")
    for line in myfile:
        line = line.rstrip()
        #x = re.findall("[a-zA-Z0-9]+@[a-zA-Z0-9]+",line) -> khong nhan dau 
        x = re.findall("[a-zA-Z0-9]\S+@\S+[a-zA-Z0-9]",line) # end must be letter
        mylist.extend(x)
    for item in mylist:
        print(item)
    print("--------- II --------")
    myfile.seek(0)
    for line in myfile:
        line = line.rstrip()
        x = re.findall('^Details:.*rev=([0-9.]+)', line) #note , + is maybe 'greedy-eat largest string', using '?' to make ReEx lazy(oppesite)
        if len(x) > 0:
            print(x)

except expression as identifier:
    print("==============")