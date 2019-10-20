// truong trinh nhap/in/bosung/xoa/sapsep thong tin thi sinh;
// danh sach lien ket moc noi
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "ctype.h"
#include "time.h"
#include "math.h"

typedef struct {
	int date,month,year;
}born;
typedef struct {
	float toan,ly,hoa,total;
} count;
typedef struct pp {
	int id;
	char fullname[25];
	born dates;
	count diem;
	struct pp *next,*pre;
}thisinh;

thisinh *pdau;

void vaosl(thisinh *p);
void insl(thisinh *p);
int inlist(thisinh *pdau);
int delete(thisinh *pxoa,thisinh **pdau);
void hoandoi(thisinh *p1,thisinh *p2);
void sapsep(thisinh *pdau);
void insert(thisinh *pchen, thisinh *pvitri,thisinh **pdau,int type);


void main(){
	int i,j,n=0;
	thisinh *p,*ppre,*pnext,*pchen;
	
	tt: 
	p=ppre=pnext=pdau=pchen=NULL;
	printf("\n\t------------------ NHAP Du LIEU ------------------");
	do {
		p=(thisinh*)malloc(sizeof(thisinh));
		vaosl(p);
		if (pdau==NULL) {pdau=p;ppre=pdau; }
		else {
			p->pre=ppre;
			ppre->next=p;		
			ppre=p;
		}
		printf("\t press key K to stop input ");
	}while(toupper(getch())!='K');
	// end nhapdulieu
	
	printf("\n\t ---------------------LIST COMPELETE------------------------ ");
	inlist(pdau);
	
	
	//----------------------------------------------------------------------------------------------------------EDIT LIST||
	printf("\n ---------------- MODE EIDT THE LIST------------------------");
	// xoa thi sinh
	printf("\n nhap id thi sinh can xoa (0 to cancel) : ");scanf("%d",&n);fflush(stdin);
	if(n!=0){
		p=pdau;
		while (p!=NULL){
			if(p->id==n) {delete(p,&pdau);printf("\t DONE!");break;}
			p=p->next;
		}
		if(p==NULL) insl(p);
	}

	// sap sep thi sinh theo thu tu diem cao xuong thap
	printf("\n tien hanh sap xep danh sach theo diem so \n");
	sapsep(pdau);
	printf(" DONE!\n");
	
	// bosung thi sinh vao vi tri bat ki
	printf("\n nhap thong tin cho thi sinh can bo sung : ");
	pchen=(thisinh*)malloc(sizeof(thisinh));
	vaosl(pchen);
	p=pdau;n=0;
	while(p!=NULL){
		printf("\n xet lan %02d",++n);
		if (pchen->diem.total > p->diem.total) {
			insert(pchen,p,&pdau,1); printf("\t donne!");
			break;
			}
		ppre=p; 
		p=p->next;	
	}
	if (p==NULL) {insert(pchen,ppre,&pdau,2); printf("\t done!");}


	//----------------------------------------------------------------------------------------------------------Sap sep||
	

	printf("\n do you wanna printf list ? press key 'Y' ");
	if(toupper(getch())=='Y') inlist(pdau);
	getch();
	
	// ---------------------------------------------------------------------------------------------------------END PROGRAM||
}

void vaosl(thisinh *p){
	thisinh x;
	x.id=1000+(rand()/1000);
	printf("\n\t\t INFORMATION CANDIDATES ID %4d ",x.id);
	printf("\n\t || FULL Name : ");gets(x.fullname);fflush(stdin);
	printf("\n\t || BORN dd|mm|yyyy  :");scanf("%d%d%d",&x.dates.date,&x.dates.month,&x.dates.year);fflush(stdin);
	printf("\n\t || Diem toan ly hoa :");scanf("%f%f%f",&x.diem.toan,&x.diem.ly,&x.diem.hoa);fflush(stdin);
	x.diem.total=x.diem.toan+x.diem.ly+x.diem.hoa;
	x.pre=x.next=NULL;
	
	*p=x;
}
void insl(thisinh *p){
	if (p==NULL) {printf ("\n khong co thong tin");return ;}
	printf("\n ------------------INFORMATION OF CANDIDATES ID %04d ----------------------- ",p->id);
	printf("\n\t || FULLNAME: %s",p->fullname);
	printf("\n\t || BORN    : %02d|%02d|%04d ",p->dates.date,p->dates.month,p->dates.year);
	printf("\n\t || COAST   : TOAN %3.2f LY %3.2f HOA %3.2f || TONG= %4.2f",p->diem.toan,p->diem.ly,p->diem.hoa,p->diem.total);
	putch(13);
}

int inlist (thisinh *pdau){
	thisinh *p,*pnext;
	p=pdau;
	while(p!=NULL) {
		insl(p);
		p=p->next;
	}
	putchar(13);
}
int delete(thisinh *pxoa,thisinh **pdau){
	thisinh *ppre,*pnext;
	
	if (pxoa->pre==NULL){
		pnext=pxoa->next;
		pnext->pre=NULL;
		*pdau=pnext;
	}
	else if (pxoa->next==NULL) {
		ppre=pxoa->pre;
		ppre->next=NULL;
	}
	else{
		ppre=pxoa->pre;
		pnext=pxoa->next;
		ppre->next=pnext;
		pnext->pre=ppre;
	}
	free(pxoa);
	return 1;
}

void hoandoi(thisinh *p1,thisinh *p2){
	thisinh ptg,*pre1,*pre2,*nex1,*nex2;
	
	pre1=p1->pre;nex1=p1->next;
	pre2=p2->pre;nex2=p2->next;
	
	ptg=*p1;*p1=*p2;*p2=ptg;
	
	p1->pre=pre1;p1->next=nex1;
	p2->pre=pre2;p2->next=nex2;
}
void sapsep(thisinh *pdau){
	thisinh *p1,*p2;
	
	p1=pdau;
	while(p1->next!=NULL){
		p2=p1->next;
		while(p2!=NULL){
			if(p2->diem.total > p1->diem.total) hoandoi(p1,p2);
			p2=p2->next;
		}
		p1=p1->next;
	}
	
}

void insert(thisinh *pchen, thisinh *pvitri,thisinh **pdau,int type){
	thisinh *ppre=NULL;
	
	if (type<2){
		ppre=pvitri->pre;
		if (pvitri==(*pdau)) {printf("\n thay doi thu khoa ");*pdau=pchen; goto z;}
		ppre->next=pchen;
		z:
		pchen->pre=pvitri->pre;
		pvitri->pre=pchen;
		pchen->next=pvitri;
		
		
	}
	else {
		pvitri->next=pchen;
		pchen->pre=pvitri;
	}
}

