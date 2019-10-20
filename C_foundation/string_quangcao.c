#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "ctype.h"
#include "string.h"

int runone(int speed);
int runtwo(int speed);


void main() {
	int i,n;
	tt: 
	
	printf("\n ban muon xem quang cao loai nao 1 or 2  : ");scanf("%d",&n);fflush(stdin);
	printf("\n nhap toc do ban muon chay 1-5 : ");scanf("%d",&i);fflush(stdin);
	i=(i%5)*100;
	if (n==1) runone(i);
		else runtwo(i);
	
	printf("\n\n\t\t CONTINUE? \n\t press Y to continue  \n ");
	if (toupper(getch())=='Y') goto tt;
}

int runone(int speed){
	char st[123]="Hello DA xin chao ban";
	char *st_show;
	int i;

	st_show=(char*)malloc(80*sizeof(char));
	
	for (i=0;i<80;++i) strcat(st_show," ");
	
	//dao chuoi va ghep chuoi de them 80 ki tu space dang truoc chuoi
	strrev(st);
	strcat(st,st_show);
	strrev(st);
	
	// cho thay doi chuoi lien tuc tao ao giac no dangg chay
	for (i=0;i<80;++i){
		strncpy(st_show,st+i,79); // ham se thay the dia chi cua st_show->st+1
		//gotoxy(1,1);
		printf("%s",st_show);
		//delay(speed);
		
	}
	
	return 0;
}

int runtwo(int speed){
	char st[123]="Hello DA xin chao ban";
	char *st_show,c;
	int i;
	
	st_show=(char*)malloc(80*sizeof(char));
	for (i=0;i<80;++i) strcat(st_show," ");
	
	printf("\n %s",st);
	
	//dao chuoi va ghep chuoi de them 80 ki tu space dang truoc chuoi
	strrev(st);
	printf("\n %s",st);
	strcat(st,st_show);
	printf("\n %s",st);
	strrev(st);
	
	i=strlen(st);
	
	printf("\n %s",st);
	
	c=st[0];st[0]=st[i-1];st[i-1]=c;
	printf("\n %s",st);
	
	return 1;
}
