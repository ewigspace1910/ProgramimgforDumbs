import json
data = '''
[
    {
        "id" : "2",
        "name" : "chuck"
    },

    {
        "id" : "1",
        "name" : "qqk"
    }
]'''

mylist = json.loads(data)
print("len data :", len(mylist) )
for item in mylist:
    print(item, "-->", item["name"], " : ", item["id"] )
