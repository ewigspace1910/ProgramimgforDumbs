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

int main(){
	int fd; // chua ma hieu cua tep
	// doi kieu viet cho ham write
	_fmode = O_BINARY;
	fd = creat("sl.sl", S_IWRITE); // s_iwrite -> tep chi doc, s_iread -> chi doc
	// ghi 5 so nguyen vao
	write(fd,a,sizeof(int)*4); // ham write co the viet len file s_iread

	close(fd);

}

// thuong thi tao tep nay kha giong file nhi phan
