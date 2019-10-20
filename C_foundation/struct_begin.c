// lam quen voi kieu bien cau truc struct

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "time.h"
#include "ctype.h"
#include "string.h"
#include "math.h"

typedef struct {
	int date,month,year;
} born;

typedef struct {
	int id;
	char name[25];
	born dates;
} person;

int n;
person *pp,p[100];


int vaodl(person *p);
int radl(person *p);
person timnguoi(person *p,int n, char *ht);
person *timnguoi2(person *p,int n, int ma);
int sapsep(person *p,int n);
void hoanvi( person *p1,person *p2);

void main(){
	int i,j;
	person p1;
	char ten[25];
	tt:
	
	printf("\n nhap so nguoi trong doan : ");scanf("%d",&n);fflush(stdin);
	for (i=0;i<n;++i) vaodl(p+i);
	
	printf("\n\n nhap ten nguoi can tim  :");gets(ten);
	p1=timnguoi(p,n,ten);radl(&p1);getch();
		
	printf("\n\n nhap id nguoi can tim : ");scanf("%d",&j);fflush(stdin);
	pp=timnguoi2(p,n,j);radl(pp);getch();
	
	printf("\n\n\t\t DANH SACH NHAN VIEN DUOC SAP XEP THEO TUOI LA \n");
	sapsep(p,n);
	
	//in data
	for (i=0;i<n;++i) radl(p+i);
	putch(13);
	
	printf("\n\t\t YOU WANT TO CONTINUE ? \n\t plesant press key Y to continue \n\t\t\t fuckk!!");
	if (toupper(getch())=='Y') goto tt;
}

int vaodl(person *p){
	person x;
	x.id=((rand()+1)*10)/19;
	printf("\n nhap thong tin cho nhan vien co ma %6d",x.id);
	printf("\n\t ten nhan vien \t:");gets(x.name);fflush(stdin);
	printf("\t nhap ngay thang nam sinh");
	printf("\n\t || ngay : ");scanf("%d",&x.dates.date);fflush(stdin);
	printf("\t || thang  ");scanf("%d",&x.dates.month);fflush(stdin);
	printf("\t || nam  ");scanf("%d",&x.dates.year);fflush(stdin);
	
	*p=x;
	return 0;
}
int radl(person *p){
	if ((p!=NULL)&&(p->id!=0)){
		printf("\n id %4d",p->id);
		printf("\n full Name : %s",p->name);
		printf("\n ngay thang nam sinh :  %3d/%3d/%4d",p->dates.date,p->dates.month,p->dates.year);
	}
	else printf("\n khong co thong tin ve nguoi nay ");
	putch(13);
	
	return 1;
}

person timnguoi(person *p,int n, char *ht){
	int i;
	person x;
	char *s;
	x.id=0;
	x.name[0]=0;
	x.dates.date=x.dates.month=x.dates.year=0;
	for (i=0;i<n;++i){
		
		s=(p+i)->name;	
		if (strcmpi(ht,s)==0) return *(p+i);
	}
	return x;
}

person *timnguoi2(person *p,int n, int ma){
	int i;
	person *p2;
	for (i=0;i<n;++i) 
		if (ma==(p+i)->id) return (p+i);
	p2=NULL;
	return p2;
}


void hoanvi( person *p1,person *p2){
	person tg;
	tg=*p1;*p1=*p2;*p2=tg;
	}

int sapsep(person *p,int n){
	int i,j;
	for (i=0;i<n-1;++i)
		for (j=i+1;j<n;++j) {
			if ((p+i)->dates.year>(p+j)->dates.year){
				hoanvi(p+i,p+j);
			}
		}
	return 1;
}
