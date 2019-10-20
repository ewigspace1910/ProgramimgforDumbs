// bai don gian ve class
#include<iostream>
#include "graphics.h"
using namespace std;

class DIEM {
	private :
		int x,y,m  // 1 diem co toa do (x,y) va mau sac m
	public :
		void nhapsl();
		void hien();
		void an(){
			putpixel(x, y, getbkcolor())
		}
		
};

void DIEM :: nhap(){
	cout << "\n nhap toa do cua diem : ";
	cin >> x >> y;
	cout << " chon mau sac cho diem  : "
	cin >> m;
	m %= 15
}

void DIEM :: hien(){
	int mau_ht = getcolor();
	putpixel(x,y,m);
	setcolor(mau_ht);
}

// toan tu '::' de chi pham vi cua phuong thuc(ham) thuoc class nao, chi class do xu dung dc data cua class
// private/public (con co protected) chi pham vi cua bien/phuowng thuc

void kd_do_hoa(){
	int mh,mode;
	mh = mode = 0;
	initgraph(&mh, &mode, "");
}

int main(){
	DIEM d1, d2, d3;
	d1.nhap();
	d2.nhap();
	d3.nhap();
	kd_do_hoa();
	setbkcolor(BLACK);
	d1.hien();
	d2.hien();
	d3.hien();
	getch();
	d1.an();
	d2.an();
	d3.an();
	getch();
	closegraph();
}


