#song()

def song():
    for i in range(10):
        sing()

#song()

def sing():
    print("hahaha")

song()
#python excute only line from top to bottom, when 
#Function definitions do not alter the flow of execution of the program, 
# but remember that statements inside the function are not executed until the function is called.
# A function call is like a detour in the flow of execution. Instead of going to the next
# statement, the flow jumps to the body of the function, executes all the statements
# there, and then comes back to pick up where it left off.

