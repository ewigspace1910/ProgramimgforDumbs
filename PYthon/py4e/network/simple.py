import socket
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(('data.pr4e.org', 80)) #sourse and port
cmd = "GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n".encode() #\r\n is EOL
    #send a blank line. The web server will respond with some header information about the document and a blank line followed by the document content
mysock.send(cmd)

while True:
    data = mysock.recv(512) #receives data in 512-character
    if len(data) < 1:
        break
    #print(data.decode(),end = '')
    print(data.decode()) # the HTTP protocol is the need to send and receive data as bytes objects, instead of strings => using encode/decode

mysock.close()