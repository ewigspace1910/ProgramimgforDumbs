// ham tao, ham huy co ban
#include "iostream"
#include "string.h"
#include "stdio.h"

using namespace std;

class hocsinh {
	private :
		char name[30];
		int ngay,thang,nam;

	public :
		void nhap(){
		    char tmp[30];
			cout << " \n nhap ho ten : ";
			fflush(stdin);
			cin.get(tmp,30);
			strcpy(name,tmp);
			cout << " nhap ngay thang nam sinh : ";
			fflush(stdin);
			cin >> ngay >> thang >> nam;
		}

		// ham tao khong doi thay the ham tao mac dinh
		// constructor
		hocsinh() {
			strcpy(this->name,"null");
			ngay = thang = nam = 0;
		}

		// ham tao co doi dung de khoi tao luc khai bao, theo muc dich
		hocsinh(char *s,int dd, int mm,int year){
			strcpy(name,s);
			ngay = dd;
			thang = mm;
			nam = year;
		}
		// ham tao sao chep
		// dung khoi tao gia tri doi tuong a, theo doi tuong b :  class_name a(b);
		hocsinh (const hocsinh &b){
			strcpy(this->name,b.name);
			this->ngay=b.ngay;
			this->thang=b.thang;
			this->nam=b.nam;
		}
		// ham sao chep se copi toan bo bit cua doituong B -> vung nho moi cua doituong A

		// ham huy
		~hocsinh(){
			strcpy(name,"");
			ngay = thang = nam = 0;
		}
		// ham huy hay dung de huy bo vung nho dc cap phat , doi tuong co chua con tro,...
		// neu khong tao ham huy se co ham huy mac dinh

		void xuat(){
			cout <<endl<< name << " \t Date : " << ngay << "|" << thang << "|" << nam << endl;
		}

};

int main(){
    char *nomal="Dank dep zai";
	hocsinh p1,p2(nomal,19,10,2001),p3(p2);
	p1.xuat();
	p2.xuat();
	p3.xuat();

	p3.nhap();

	p1.xuat();
	p2.xuat();
	p3.xuat();
}
