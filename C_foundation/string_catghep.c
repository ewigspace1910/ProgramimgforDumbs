#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "time.h"
#include "string.h"


typedef struct {
	char fistname[10],lastname[10],middlename[10]; // ten NDA -> fist :A | last :N |mid :D 
} hoten;
typedef struct {
	int date,month,year;
} born;
typedef struct {
	int id;
	hoten fullname;
	born dates;
} thisinh;

thisinh *p;
void dissociatename(char *fullname,thisinh *x);// ham tach chuoi con ra tu chuoi me;
void dissociatedate(char *date,thisinh *x); // ham tach ngay thang
void deletespae(char *s);// xoa ki tu space o 2 dau string
void nhaptt(thisinh *p);
void intt(thisinh *p);

void main(){
	
	p=(thisinh*)malloc(sizeof(thisinh));
	nhaptt(p);
	intt(p);
	getch();
	
}

void dissociatename(char *fullname,thisinh *x){
	char *p;
	x->fullname.fistname[0]=x->fullname.middlename[0]=x->fullname.lastname[0]='o';
	if ((p=strchr(fullname,32))!=NULL) {
		*p++='\0';
		strcpy(x->fullname.lastname,fullname);
		fullname=p;
		if ((p=strrchr(fullname,32))!=NULL) {
			*p++='\0';
			strcpy(x->fullname.middlename,fullname);
			strcpy(x->fullname.fistname,p);
		}
	}
}

void dissociatedate(char *date, thisinh *x){
	char *p;
	x->dates.date=x->dates.month=1;x->dates.year=2001;
	p=date;
	if ((p=strchr(date,'/'))!=NULL) {
		*p++='\0';
		x->dates.date=atoi(date);
		date=p;
		if ((p=strchr(date,'/'))!=NULL) {
			*p++='\0';
			x->dates.month=atoi(date);
			x->dates.year=atoi(p);
		}
	}
	
}
void deletespae(char *s){
	char *p;
	//xoa dau
	p=s;
	while(s[0]==32){
		*p++='\0';
		strcpy(s,p);
	}
	strrev(s);
	p=s;
	while(s[0]==32){
		*p++='\0';
		strcpy(s,p);
	}
	strrev(s);
}
void nhaptt(thisinh *p){
	thisinh x;
	char ht[30],date[12],*ps;
	x.id=rand()%1000;
	printf("\n ID HAS BEEN PROVIDED/SUPPLYED : %d \n\t\t nhap dung theo huong dan ",x.id);
	printf("\n IMPORT FULLNAME      : ");gets(ht);fflush(stdin);
	printf("\n IMPORT DATE OF BIRTH : (dd/mm/yy) ");gets(date);fflush(stdin);
	
//-----------------------------------------------------xulithongtin---------------------------------------
	// hoten 
	strupr(ht);
	deletespae(ht);
	dissociatename(ht,&x);
	
	//ngay sinh
	deletespae(date);
	dissociatedate(date,&x);
	
//------------------------------------------------------luu lai---------------
	*p=x;
}
void intt(thisinh *p){
	printf("\n------------------------------ INFORMATION OF CANDIDATES ID %04d -----------------------",p->id);
	printf("\n\t ||FISTNAME      : %s",p->fullname.fistname);
	printf("\n\t ||MIDDLENAME    : %s",p->fullname.middlename);
	printf("\n\t ||LASTNAME      : %s",p->fullname.lastname);
	printf("\n\t ||DATE OF BIRTH : %02d/%02d/%04d",p->dates.date,p->dates.month,p->dates.year);
	putch(13);
}
