// tao tep bang lenh he thong
// tep du lieu # file
#include "iostream"
#include "stdio.h"
#include "sys/stat.h"
#include "io.h"
#include "fcntl.h"
#include "dos.h"
#include "stdlib.h""


using namespace std;

int a[4]={1,19,10,2001};
char *s="data.sl";
int main(){
	int fd; // chua ma hieu cua tep
	fd = open(s,O_WRONLY | O_TRUNC | O_BINARY | O_CREAT, S_IWRITE);
	// MO TEP voi cac atrribute
	
	write(fd,a,sizeof(int)*4); 
	close(fd);
}
// tiep noi exam 1
// ham write tuong tu nhu ham fwrite, fread, fseek tuong ung la read, lseek;
