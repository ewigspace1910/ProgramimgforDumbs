dic = dict()
print(dic)
dic["hello"] = "xin chao"
dic["1"] =  2
print(dic)
print(dic.keys())
print(dic.values())
print(dic.pop("1"))
print(dic)

#exercise
dic = dict()
try:
    myfile = open("mailbox.txt")
except:
    print("error file ~~")
    exit()
for line in myfile:
    if (line.startswith("From")):
        words = line.rstrip().split(" ")
        if (len(words) > 2):
            dic[words[2]] = dic.get(words[2],0) + 1
print(dic)