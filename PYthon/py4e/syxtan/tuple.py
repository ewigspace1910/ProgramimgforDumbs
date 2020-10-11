txt = 'but soft what light in yonder window breaks'
words = txt.split()
t = list()
for word in words:
    t.append((len(word), word))
t.sort(reverse=True)
print(t)
res = list()
for length, word in t: # length, word is a tuple , Signal : (,) / a, b
    res.append(word)
print(res)
m = [ 'have', 'fun' ]
(x, y) = m
print("type m : ", type(m))
print("tuple (x,y) = ", (x,y))
# swap by tuple
a = 2
b = 3
a, b = b, a
print(a,b)
