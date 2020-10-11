import urllib.request
try:
    img = urllib.request.urlopen("https://i.imgur.com/Xq2UPOn.png").read()
    picture = open("pic.png", "wb")
    picture.write(img)
    picture.close()
except:
    print("errro request")

