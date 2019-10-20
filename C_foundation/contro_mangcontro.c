#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

// bai toan xe tai va nhung chuyen duong =)))
#define N 20  //congt ti ngheo nen 1 ngay chi cayj kkhong qua 20 xe
#define L 1000 // xe cong ti khong xin nen 1 ngay chi di duoc khong qua 1000 chuyen

// con tro dung de chua mang du lieu
int ps[L],pp[N];
float pm[L]; 
int *pscar[N];
float *pmcar[N];
// int **pp; // mang con tro tro con tro de chi den dia chi chinh xac


int vaosl(int n);
int searchcar(int n);

void main() {
	int i,n;
	
	printf("\n mhap so luong xe vao <20 : ");scanf("%d",&n);fflush(stdin);
	
	vaosl(n);
	
	tt:
	i= searchcar(n);
	if (i==0) printf("\n \t khong tim thay thong tin xe \n");
	
	printf("\n\n press key K to exit");
	if ( toupper(getch())!= 'K') goto tt;
}

int vaosl(int n){
	int i,j,a;
	int *pps;
	float *ppm;
	pps=ps;ppm=pm;
	
	for (i=0;i<n;++i){
		printf("\n nhap so  nhieu xe thu %2d \n",i+1);
		printf("\n nhap so chuuyen di cua xe  : ");scanf("%d",&a);fflush(stdin);
		
		pp[i]=a;
		pscar[i]=pps;
		pmcar[i]=ppm;
		
		for(j=0;j<a;++j){
			printf("\n nhap quang duong %2d : ",j+1);scanf("%d",pps++);fflush(stdin);
			printf("\n nhap khoi luong  %2d : ",j+1);scanf("%f",ppm++);fflush(stdin);
		}
		
		
	}
	return 1;
	
}

int searchcar(int n){
	int i,j,x;
	
	printf("\n nhap ma so xe can tim : ");scanf("%d",&x);fflush(stdin);
	if ((x>n) || (x<1)) return 0;
	
	printf("\n\n thong tin xe %2d la \n \t so chuyen la %2d",x--,pp[x]);
	
	printf("\n quang duong :");
	for (i=0;i<pp[x];++i) printf("\t %4d km",*(pscar[x]+i));
	printf("\n khoi luong  :");
	for (j=0;j<pp[x];++j) printf("\t %4.1f kg",*(pmcar[x]+j));
	
	return 1;
}









