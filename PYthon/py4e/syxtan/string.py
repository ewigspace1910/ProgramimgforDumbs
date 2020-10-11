import string

s = "hahaha"
ss = s
print(s," - ", ss)
s.replace('h','k',2)
print(s," - ",ss)

#compare -> string is considered one premitive value(maybe object)
t = "hahaha"
print(t is s)
print(t == s)

#string is unmutable
num = 55
print("helo %d" % num)
s = "helo %d -- %d -- %s" % (num, 12, "hihi")
print(s)
print(len(s))
# % is oparand format string

#exercise
s = 'X-DSPAM-Confidence:0.8475'
colon = s.find(':')
print(s[colon+1:])

#string strick
s = s.translate(s.maketrans(".","_",":"))
print(s)