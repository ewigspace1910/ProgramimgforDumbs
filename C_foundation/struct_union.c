#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "time.h"
#include "string.h"

typedef struct {
	unsigned ngay:5;
	unsigned thang:4;
	unsigned nam:7;
} date; // kieu date co gia tri 16bit = 2 byte

typedef struct {
	char type;
	union {
		float fval; // data type : number
		char *cval; // data type : word
		date dval; //  data type : date  DD/MM/YYYY
		int lval; //   data type : logic YyNn
		
	} v;
} stdata;

stdata data;

int savedata(char type,char *s,stdata *data);
int printfdata(stdata *x);


void main(){
	char t,s[25];
	tt: 
	printf("\n type of data can be save : C: String || N :number || D :date DD/MM/YYYY || L: logic YyNn ");
	printf("\n CHOOSE TYPE DATA TO SCAN :  "); scanf("%c",&t);fflush(stdin);
	printf("\n IMPORT YOUR DATA ");gets(s);fflush(stdin);
	
	savedata(t,s,&data);
	printf("\n DO YOU WANT TO PRINT YOUR DATA  ? \n\t press key Y");
	if (toupper(getch())=='Y') printfdata(&data);
	printf("\n\t\t AGAIN? \n\t press key Y");
	if (toupper(getch())=='Y') goto tt;
}


int savedata(char type,char *s,stdata *datas){
	stdata x;
	char *p;
	p=strupr(s);
	
	x.type=toupper(type);
	switch (x.type){
		case 'N': x.v.fval=atof(s);
			break;
		case 'C': x.v.cval=s;
			break;
		case 'D': 
			// mac dinh la ngay 1/1/95
			x.v.dval.ngay=x.v.dval.thang=1;x.v.dval.nam=95;
			// tach 1 chuoi string thanh nhieu dia chi
			if ((p=strchr(s,'/'))!=NULL){
				*p++='\0';
				x.v.dval.ngay=atoi(s);
				s=p;
				if((p=strchr(s,'/'))!=NULL){
					*p++='\0';
					x.v.dval.thang=atoi(s);
					x.v.dval.nam=atoi(p);
				}		
			}
			break;
		default : if (strchr(s,'Y')!=NULL) x.v.lval=1; else x.v.lval=0;
	}
	
	*datas=x;
}

int printfdata(stdata *x){
	putch(13);
	printf("\n Your data : ");
	switch(x->type) {
		case 'C': printf(" STRING %s",x->v.cval);
			break;
		case 'N': printf(" NUMBER %05.2f",x->v.fval);
			break;
		case 'D': printf(" Date %02d|%02d|%02d",x->v.dval.ngay,x->v.dval.thang,x->v.dval.nam);
			break;
		default: if (x->v.lval==1) printf(" TRUTH \n"); 
			else printf("False \n");
	}
}
