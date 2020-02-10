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
	fd = _creat("sl_s.sl",FA_HIDDEN | FA_ARCH); // tep an va chi doc
	write(fd,a,sizeof(int)*4);
	close(fd);
}
// tuong tu exam1
// cach tao tep 2 vs attribute
// dung voi he dieu hanh dos
