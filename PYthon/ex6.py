# printing, printing
stringg="{} {} {} {}"
print(stringg.format(1,2,3,4))
print(stringg.format("one","two", "three","four"), end=" ")  # end=' ', bao hieu ket thuc print la ki tu ' ' (space) thay vi enter
print(stringg.format(stringg,stringg,stringg,stringg))
print(stringg.format(
    "hey guy \n",                                   # \n duoc goi la esscape sequences , chuoi ki tu dac biet
    "\t how are you? \n",                           # \n xuong dong, \t = tab
    "\a i love you \n\n",                           # \a = alarm =bell
    "\b hi hi"                                      # \b = backspace
))
