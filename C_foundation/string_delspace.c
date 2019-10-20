#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

char *p,s[25];
int i;
void main(){
	gets(s);fflush(stdin);
	printf("\n ban dau p= %s || s=%s",p,s);
	p=s;
	while(s[0]==32){
		*p++='\0';
		strcpy(s,p);
	}
	printf("\n xoa #32 p= %s || s=%s",p,s);
	getch();
}
/*
nhan xet
ten chuoi s : chua dia chi dau tien cua cac phan tu
s+1,...     : chua dia chi cua cac phan tu tiep theo

cac ham str... thay doi dia chi cua s, s+1,...

*/
