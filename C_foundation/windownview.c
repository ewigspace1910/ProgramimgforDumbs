#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "ctype.h"

void main(){
	int m,xt,xd,yt,yd,xd2,yd2,m2;
	textmode();
	textcolor(15);
	window(1,1,80,25);
	clrscr();
	
	tt:
	window(1,1,50,10);
	clrscr();
	cprintf("\t cua so thu nhat : mau xt,yt,zd,yd :");
	cscanf("%d%d%d%d%d",&m,&xt,&yt,&xd,&yd);
	// open 1st Windown
	textbackground(m);
	window(xt,yt,xd,yd);
	clrscr();
	
	cprintf("co tiep tuc ko? -C/K");
	if( toupper(getch())=='C') goto tt;
	textmode(2);
	window(1,1,80,25);
	clrscr();
}
