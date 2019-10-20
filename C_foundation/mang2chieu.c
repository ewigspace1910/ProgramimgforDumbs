#include <stdio.h>
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

#define n 3

void main(){
	// TRUONG TRINH DUNG CON TRO VOI MANG 2 CHIEU
	int a[n][n],*pa,(*pb)[n],i,j;
	void *pp;
	
	for (i=0;i<n;++i)
		for (j=0;j<n;++j) a[i][j]= rand();
	
	printf ("\n mang duoc nhap la \n");
	for (i=0;i<n;++i)
		for (j=0;j<n;++j) printf(" %6d %c", a[i][j], j==n-1?'\n':' ');
	
	pa=(int*)a; pp=a;pb=a;
	
	printf("\n dung con tro int* pa \n");
	for (i=0;i<n;++i)
		for (j=0;j<n;++j) printf(" %6d %c",*(pa+i*n+j),j==n-1?'\n':' ');
	
	printf("\n dung con tro int[]* pb \n");
	for (i=0;i<n;++i)
		for (j=0;j<n;++j) printf("%6d %c",pb[i][j],j==n-1?'\n':' ');
	
	printf("\n dung con tro void pp \n");
	pa=(int*)pp;
	for (i=0;i<n;++i)
		for (j=0;j<n;++j) printf("%6d %c",*(pa+i*n+j),j==n-1?'\n':' ');
	
	getch();
}
