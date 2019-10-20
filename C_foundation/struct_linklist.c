#include <stdio.h>
#include "math.h"
#include "conio.h"
#include "stdlib.h"
#include "ctype.h"
#include "time.h"

#define NOW 2019

typedef struct {
	int date,month,year;
}born;
typedef struct pp {
	int id;
	char fullname[25];
	born dates;
	struct pp *next;
}person;

person *pdau;

int erro444();
void input(person *p,int *n);
void output(person *p);
person *searchperson(int code,int n, person *pdau);
int delete(int code,int *n,person *pdau);
int insert(int vitri,int *n,person *pdau,person *pchen);

void main(){
	int i,j,n;
	person *pnext,*p;

//-------------------------------Head main function--------------------------------//
	printf("\n --------------- links list---------------------------");
	printf("\n || ************nhap thong tin************* || \n \t\t press K to stop \n");
	n=0;pdau=p=NULL;
	while(1){

		pnext=(person*)malloc(sizeof(person));
		if (p!=NULL) p->next=pnext;
		if (pnext==NULL) erro444;
		else{
			input(pnext,&n);
			if (n==1) pdau=p=pnext;
				else p=pnext;
			pnext=NULL;
		}
		if (toupper(getch())=='K' ) break;
	}


	// in danh sach
	printf("\n ban co muon in danh sach ?\n press Y to print list ");
	if ( toupper(getch())=='Y') {
		p=pnext=pdau;
		for (i=1;i<=n;++i){
			output(pnext);
			pnext=p->next;
			p=pnext;
		}
	}

	//chinh sua danh sach;
	printf("\n ------------ EDIT THE LINKLIST -----------------");

	printf("\n\t nhap id thi sinh can tim kiem : ");scanf("%d",&j);fflush(stdin);
	p=searchperson(j,n,pdau);
	output(p);

	printf("\n\t nhap id thi sinh can xoa bo   : ");scanf("%d",&j);fflush(stdin);
	delete(j,&n,pdau);
	printf("\n DONE! \t now this list is having %03d vacansys ",n);

	printf("\n\t nhap thong tin thi sinh can them \n ");
	i=n;p=NULL;
	p=(person*)malloc(sizeof(person));
	input(p,&i);
	printf("\n\t muon chen vao vi tri sau thi sinh thu may trong %03d thi sinh : ",n);scanf("%d",&j);fflush(stdin);
	insert(j,&n,pdau,p);
	printf("\n DONE! \t now this list is having %03d vacansys ",n);

	// in danh sach da chinh sua

	printf("\n THE EDITED LINKLIST ");
	p=pnext=pdau;
	for (i=1;i<=n;++i){
		output(pnext);
		pnext=p->next;
		p=pnext;
	}

	printf("\n\t\t thanks for used ");
	getch();
}
//-------------------------------end main function--------------------------------//
int erro444(){
	printf("\n co loi ve cap phat bo nho \n");
	return 0;
}
void input(person *p,int *n){
	person x;
	printf("\n---------- FILL INFOMATION OF PERSON %03d ------------\n",++(*n));
	x.id=1000+(*n)*1000/19;
	printf("\n\t id been auto fill : %04d",x.id);
	printf("\n\t fullname : ");gets(x.fullname);fflush(stdin);
	printf("\t date|month|year (space) : ");scanf("%d%d%d",&x.dates.date,&x.dates.month,&x.dates.year);fflush(stdin);
	x.next=NULL;

	*p=x;

}
void output(person *p){
	if (p==NULL) printf("\n dont have infomation \n");
	else{
		printf("\n---------- FULL INFOMATION OF PERSON ID %03d ------------",p->id);
		printf("\n\t ||FULLNAME : %s",p->fullname);
		printf("\n\t ||Age      : %3d",NOW-(p->dates.year));
		printf("\n\t ||Born     : %02d/%02d/%4d",p->dates.date,p->dates.month,p->dates.year);
		putchar(13);
	}
}
person *searchperson(int code,int n, person *pdau){
	int i;
	person *p;

	p=pdau;
	for (i=1;i<=n;++i) {
		if (code==p->id) return p;
		p=p->next;
	}
	p=NULL;
	return p;
}

int delete(int code,int *n,person *pdau){
	int i;
	person *p,*pre,*pnext;

	p=pre=pdau;
	for (i=1;i<=*n;++i){
		if ((code==p->id) && (i>1) ) {
			pnext=p->next;
			pre->next=pnext;
			free(p);
			break;
		}
		else if ((code==p->id) && (i==1) ) {
			pdau=p->next;
			free(p);
		}
		pre=p;
		pnext=p->next;
		p=pnext;
	}
	(*n)--;

	return 0;
}

int insert(int vitri,int *n,person *pdau,person *pchen){
	int i,j;
	person *p,*pnext;

	if (vitri>*n) {printf("\n vi tri khong ton tai "); return 1; }
	p=pdau;
	if (vitri==0) {
		pchen->next=pdau;
		pdau=pchen;
	}
	else
		for (i=1;i<=vitri;++i){

			if (i==vitri) {
				pnext=p->next;
				pchen->next=pnext;
				p->next=pchen;
			}
			pnext=p->next;
			p=pnext;

			break;
		}

	(*n)++;
	return 1;
}
