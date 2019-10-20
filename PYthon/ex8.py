# asking question
"""
now, we do lot of printing to get you
"""
print("what your name? ", end=' ')
name=input()                                # input is methods pass varialbe from keyboad,.. into your scripting
print('how old are you', end=" ")
age=int(input(" (number) "))                            # input send string format, then you should use "ep kieu"
print(f"""
    \n yeah! Now, this is your infor i have : \n
    your name is {name} and you are {age} years old
""")
# note
"""
in c/c++, we have function 'gets'/'getline', they like as input(); 
"""