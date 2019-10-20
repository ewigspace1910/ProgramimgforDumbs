#include "stdio.h"
#include "conio.h"
#include "ctype.h"
#include "stdlib.h"
#include "time.h"
//#include "dir.h"  // thu vien kiem soat thu muc

#define fn "input.txt"
void main(){
	FILE *fp,*fpp;
	int n,j;
	char c,*s;
	
	
	printf("\n nhap mot chuoi ki tu vao file input \n\t press enter to stop\n\n");
	fp=fopen(fn,"wb");
	if (fp!=NULL)
		do{
			j=getche();
			if (j==13) break;
			putc(j,fp);
		}while (1);
	else printf("co loi \n");
	fclose(fp);printf("\n dong file input");
	
	printf("\n chuyen doi cac ki tu sang in hoa");
	fp=fopen(fn,"rb");
	fpp=fopen("0.txt","wb");n=0;
	if (fp==NULL || fpp==NULL) printf(" \n co loi 442");
	while (!feof(fp)){
		j=toupper(getc(fp));++n;
		putc(j,fpp);
		
	}
	fclose(fp);fclose(fpp);
	
	fp=fopen(fn,"wb");
	fpp=fopen("0.txt","rb");
	if (fp==NULL || fpp==NULL) printf(" \n co loi 444");
	while (!feof(fpp)){
		j=getc(fpp);
		putc(j,fp);
	}
	putc(13,fp);
	fwrite(&n,sizeof(int),1,fp);
	fclose(fp);fclose(fpp);
	
	tt:
	
	putch(13);printf("\n n=%d \n END!",n);
	getch();
}
