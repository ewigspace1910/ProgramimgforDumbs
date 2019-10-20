#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

#define N 4


int x[N][N]; 

int mode1(int*a);
int mode2(int*a);
int mode3(int*a);
int mode4(int*a);
int sapsep(int*a);



void main() {
	int *pa,a[N][N],i,j,mode;
	tt:
	for (i=0;i<N;++i)
		for (j=0;j<N;++j) a[i][j]=rand();
	
	printf("\n mang da nhap la \n");
	for (i=0;i<N;++i)
		for (j=0;j<N;++j) printf(" %6d %c",a[i][j],j==N-1?'\n':' ');
	
	// chuyen doi tu mang 2 chieu thanh 1 chieu
	pa=(int*)malloc((sizeof(int)*(N*N)));
	if (pa==0) {
		printf("\n not enough memory for prodece \n exit "); goto ex;
	}
	for (i=0;i<N;++i)
		for (j=0;j<N;++j) *(pa+i*N+j)=a[i][j];
	//sapsep
	sapsep(pa);
	
	t1: 
	printf("\n ban muon chon che do sap sep nao 1-4 : ");scanf("%d",&mode);fflush(stdin);
	switch(mode){
		case 1: mode1(pa);
			break;
		case 2: mode2(pa);
			break;
		case 3: mode3(pa);
			break;
		case 4: mode4(pa);
			break;
		default:goto t1;
	}
	
	for (i=0;i<N;++i)
		for (j=0;j<N;++j) for (j=0;j<N;++j) printf(" %6d %c",x[i][j],j==N-1?'\n':' ');

	ex:
	printf("\n\n \t\t CONTINUE ? \n \t press key Y to play again");
	if (toupper(getch())=='Y') goto tt;
	
}

int sapsep(int*a){
	int i,j,z;
	for (i=0;i<N*N-1;++i)
		for (j=i;j<N*N;++j) 
			if (*(a+i)>*(a+j)) {
				z=*(a+i);*(a+i)=*(a+j);*(a+j)=z;
			}
}

int mode1(int*a){
	int n=0,i,j;
	printf("\n sap xep mang theo kieu bang tuan hoan hoa hoc\n");
	for (i=0;i<N;++i)
		for (j=0;j<N;++j) x[i][j]=*(a+n++);
	return 0;
}

int mode2(int*a){
	int i,j,n;
	printf("\n sap xep mang theo kieu zizzac ngang \n");
	
	for (i=0;i<N;++i)
		for (j=0;j<N;++j)
			if (i%2==0) x[i][j]=*(a+n++);
			else x[i][N-j-1]=*(a+n++);

	return 0;
}

int mode3(int*a){
	int n=0,i,j;
	
	printf("\n sap sep mang theo kieu zizzac dung\n");
	for (j=0;j<N;++j)
		for (i=0;i<N;++i)
			if (j%2==0) x[i][j]=*(a+n++);
			else x[N-i-1][j]=*(a+n++);
	return 1;
}

int mode4(int*a){
	int i,j,n,t0,t1,t2,t3,t;
	
	printf("\n sap xep mang theo kieu xoay oc\n");
	
	for (i=0;i<N;++i)
		for (j=0;j<N;++j) x[i][j]=0;
			
	t=t0=t1=t2=t3=0;
	for (n=0;n<N*N;){
		
		for (j=0;j<N;++j){
			
			if((x[t0][j]==0) && (t%4==0) ) {
				x[t0][j]=*(a+n++);
			}	
			else if ( (x[j][N-t1-1]==0) && (t%4==1) ) {
				x[j][N-t1-1]=*(a+n++);
			}
			else if ( (x[N-1-t2][N-1-j]==0) && (t%4==2) ) {
				x[N-1-t2][N-1-j]=*(a+n++);
			}
			else if ((x[N-j-1][t3]==0) && (t%4==3) ) {
				x[N-j-1][t3]=*(a+n++);
			}
			
		}
		
		if (t%4==0) t0++;
		if (t%4==1) t1++;
		if (t%4==2) t2++;
		if (t%4==3) t3++;
		++t;
	}
	
	return 2;
}





















