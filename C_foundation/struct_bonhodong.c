#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "time.h"
#include "ctype.h"

typedef struct{
	int date,month,year;
}born;
typedef struct {
	int id;
	char fullname[25];
	born dates;
}person;
typedef struct {
	int idroom;
	int nhanvien;
	person *p;
} room;
typedef struct {
	int idvien;
	char tenvien[100];
	int sophong;
	room *r;
} vien;

vien *vvv;

int erro444();
void vaodulieu(vien *vvv);
vien *searchvien(int code,int n,vien *vvv);
int indulieu(vien *vvv);

void main(){
	int i,j,n;
	vien *vien1;
	tt:
	printf("\n nhap so benh vien can luu thong tin : ");scanf("%d",&n);fflush(stdin);
	vvv=(vien*)malloc(n*sizeof(vien));
	if (vvv==NULL) {erro444; goto end;}
	for (i=0;i<n;++i) vaodulieu(vvv+i);
	
	//tim kiem benh vien
	printf("\n nhap id benh vien ban muon xem thong tin : ");scanf("%d",&j);fflush(stdin);
	vien1=searchvien(j,n,vvv); 
	indulieu(vien1);
	
	//in toan bo benh vien
	printf("\n ban co  muon in toan bo thong tin cac benh vien\n press key Y  ");
	if (toupper(getch())=='Y') 
		for (j=0;j<n;++j) indulieu(vvv+j);
	
	while(kbhit()!=0) getch(); // dk!=0 bo nho dem con ki tu
	end:
	printf("\n\n \t\t CONTINUE? \n press key Y to continue ");
	if (toupper(getch())=='Y') goto tt;
}

int erro444(){
	printf("\n\n\t\t ERRO444 \n\t thong bao co loi !!!");
	getch();
	return 1;
}

void vaodulieu(vien *vvv){
	int i,j;
	room rr;
	person pp;
	vien v;
	
	v.idvien=((rand()+1)%10)*1000+(rand()%1000);
	printf("\n id cap cho benh vien  : %4d ",v.idvien);
	
	printf("\n nhap ten benh vien : ");gets(v.tenvien);fflush(stdin);
	printf("\n nhap so luong phong: ");scanf("%d",&v.sophong);fflush(stdin);
	v.r=(room*)malloc(sizeof(room)*(v.sophong));
	if (v.r==NULL) {erro444;goto ehv;}
	for (i=0;i<v.sophong;i++){
		rr.idroom=((rand()+1)%10)*100+(rand()%100);
		printf("\n id phong thu %02d : %3d ",i+1,rr.idroom);
		printf("\n nhap so nhan vien phong thu %02d    : ",i+1);scanf("%d",&rr.nhanvien);fflush(stdin);
		rr.p=(person*)malloc(sizeof(person)*(rr.nhanvien));
		if (rr.p == NULL) {printf("\n co lo ve bo nho ");goto ehv;}
		for(j=0;j<rr.nhanvien;++j){
			pp.id=((rand()+1)%10)+(rand()%100);
			printf("\n\t id nhan vien thu %02d : %4d",j+1,pp.id);
			printf("\n\t nhap ten nhan vien        : ");gets(pp.fullname);fflush(stdin);
			printf("\n\t nhap ngay thang nam sinh  : ");
			scanf("%d%d%d",&pp.dates.date,&pp.dates.month,&pp.dates.year);fflush(stdin);
			
			rr.p[j]=pp;
		}
		v.r[i]=rr;
	}
	
	*vvv=v;
	ehv: 
	putchar(13);
	
}

vien *searchvien(int code,int n,vien *vvv){
	vien *v;
	int i,j;
	
	for (i=0;i<n;++i)
		if ( (vvv+i)->idvien==code ) return (vvv+i);
	
	v=NULL;
	return v;
}

int indulieu(vien *vvv){
	int i,j;
	room *rr;
	person *pp;
	if (vvv==NULL) printf("\n khong co thong tin!!! ");
	else {
		printf("\n benh vien id %4d : %s",vvv->idvien,vvv->tenvien);
		printf("\n so luong phong : %3d",vvv->sophong);
		rr=vvv->r;
		for (i=0;i<vvv->sophong;++i){
			printf("\n\t phong id %3d gom %3d nhan vien :",(rr+i)->idroom,(rr+i)->nhanvien);
			pp=rr->p;
			for(j=0;j<rr->nhanvien;++j){
				printf("\n\t\t ||id %3d : %s ",(pp+j)->id,(pp+j)->fullname);
				printf("\n\t\t ||ngay de: %02d/%02d/%4d \n",(pp+j)->dates.date,(pp+j)->dates.month,(pp+j)->dates.year);
			}
		}
		putchar(13);
	}
	return 1;
}
