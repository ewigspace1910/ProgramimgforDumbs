#reading and writing files
"""
now we learn more methods you can give to files
 . close            : save and close file
 . read             : read contennts of the file. you can assign the result to a variable
 . readline         : read contents just in once line of text file
 . truncate         : empties the file. what out if you care about the file
 . write('stuff')   : write 'stuff' to the file
 . seek(0)          : move the read/write location to the beginning of the file
 . open(filename, type use) : type use can be 'w' to write, 'r' to read, 'a' to append
"""

txt= 'ex10_sample.txt'
target = open(txt,'w')
print("truncate the file. gooodbye ! ")
target.truncate()

print(" now, i'm going to write 3 line.")
line1 = input('> ')
line2 = input('> ')
line3 = input('> ')

print("i'm going to write these to the file ")
target.write(line1+'\n')
target.write(line2+'\n')
target.write(line3+'\n')
target.close