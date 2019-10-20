#include "stdio.h"
#include "conio.h"
#include "ctype.h"
#include "stdlib.h"

#define fn "data.sl"
#define ERRO414 {printf("\n loi 414");exit;}

typedef struct {
	float toan,ly,hoa,total;
} point;
typedef struct {
	int id;
	char name[25];
	point diem;
} person;

void importts(person *thisinh,int n);
void nhap();
void in();
void sapsep();
void fix(int n);

void main() {
	int n;
	
	printf("\n nhap data cho file :\n");
	nhap();
	in();
	
	printf("\n thay the phan id : ");scanf("%d",&n);fflush(stdin);
	fix(n);
	
	
	printf("\n ban co muon sap sep file - key Y to sort ");
	if (toupper(getch())=='Y') sapsep();
	
	printf("\n in list ra nhe ");
	in();
	
	printf("\n\t\t END \n");getch();
}
void importts(person *thisinh,int n){
	person x;
	
	x.id=1000+n*19;
	printf("\n\t nhap ten : ");gets(x.name);fflush(stdin);
	printf("\n\t nhap diem toan ly hoa :");scanf("%f%f%f",&x.diem.toan,&x.diem.ly,&x.diem.hoa);fflush(stdin);
	x.diem.total=x.diem.toan+x.diem.ly+x.diem.hoa;
	
	*thisinh=x;
}
void nhap(){
	FILE *fp;
	person x;
	int n=0;
	
	fp=fopen(fn,"wb");	
	if (fp==NULL) ERRO414;
	
	tt:
	printf("\n -----------------------------INFORMATION CANDIDATES STT %3d ",++n);
	importts(&x,n);
	fwrite(&x,sizeof(person),1,fp);
	
	printf("\n\t\t continue ? K to stop "); 
	if (toupper(getch())!='K') goto tt;
	fclose(fp);
}
void in(){
	FILE *fp;
	person x;

	
	fp=fopen(fn,"rb");
	if(fp==NULL) printf("\n co loi erro 3 ");
	else {
		while(fread(&x,sizeof(person),1,fp) > 0) {
			printf("\n ----------------------INFORMATION CANDIDATES ID %4d ",x.id);
			printf("\n\t || FULLNAME  : %s", x.name);
			printf("\n\t || Diem A0   : Toan %3.1f | Ly %3.1f | Hoa %3.1f ",x.diem.toan,x.diem.ly,x.diem.hoa);
			printf("\n\t || Total     : %3.1f",x.diem.total);	
		}
	}
	fclose(fp);
}
void sapsep(){
	FILE *fp;
	person *pp,ptg;
	int n;
	register int i,j;
	//read file
	fp=fopen(fn,"r+b");
	fseek(fp,0,SEEK_END);
	n=ftell(fp)/sizeof(person); 
	pp=(person*)malloc(n*sizeof(person));
	fseek(fp,0,SEEK_SET);
	fread(pp,sizeof(person),n,fp);
	
	//sort
	for (i=0;i<n-1;++i)
		for (j=i+1;j<n;++j)
			if((pp+i)->diem.total < (pp+j)->diem.total ) {
				ptg=*(pp+i);*(pp+i)=*(pp+j);*(pp+j)=ptg;
			}
	//write into file
	fseek(fp,0,SEEK_SET);
	fwrite(pp,sizeof(person),n,fp);
	fclose(fp);
}
void fix(int n){
	FILE *fp;
	person *pp,pchen,x;
	int check=0,vitri;
	fp=fopen(fn,"r+b");if (fp==NULL) ERRO414;
	while(!check){
		if (fread(&x,sizeof(person),1,fp)>0)
			if (x.id==n) check=1;
		else break;
	}
	if (check){
		printf("\n nhap thong tin thi sinh thay the : \n");
		importts(&pchen,n);
		vitri=ftell(fp)-sizeof(person);
		fseek(fp,vitri,SEEK_SET);
		fwrite(&pchen,sizeof(person),1,fp);
	}
	else printf("\n khong tim thay thong tin thi sinh can thay the! \n");
	fclose(fp);
}
