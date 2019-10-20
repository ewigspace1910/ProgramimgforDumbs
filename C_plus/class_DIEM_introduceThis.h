// tinh chu vi tam giac
// class co phuong thuc : tinh do dai 1 canh, tinh chu vi
#include<iostream>
#include "cmath"
using namespace std;

class DIEM {
	private :
		int x,y;
	public :
		void nhap(){
			cout <<  " \n nhap toa do diem : ";
			cin >> x >> y;
		}
		double dodai(DIEM d2);
		double chuvi(DIEM d2, DIEM d3);
};

double DIEM :: dodai( DIEM d2){
	// vi goi ca thang d2 di cung nen ham nay co the dung data of d2, though by d2

	return sqrt(pow((this->x - d2.x),2) + pow(this->y - d2.y,2));
	// dung con tro this khong khac dung nguyen gia tri x,y
	// nhung no se ro rang hon cho biet x,y cua bien nao
	// mac dinh this la doi tuong chua phuong thuc
}

double DIEM :: chuvi(DIEM d2, DIEM d3){
	return (*this).dodai(d2)+ (*this).dodai(d3) + d2.dodai(d3);
	// con tro chi dung dang ->  de truy cap data
	// con tro dung dang (*) de truy cap phuong thuc, data tuong tu trang thai 1 bien
}



int main(){
	DIEM d1, d2, d3;
	d1.nhap();
	d2.nhap();
	d3.nhap();
	cout << " chu vi cua tam giac la : " << d1.chuvi(d2,d3);


}


