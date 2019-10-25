/*
 The inheritane in class
 LOI khi:
	|ke thua nhieu muc
	|ham tao, ham huy
	|class ao, ke thua ao virtual
*/
#include "iostream"
#include "cmath"
#include "string.h"
using namespace std;

class A{
	private:
		int a;
	protected:
		char *str;
	public:
		A(){
			a=0;str=NULL;
		}
		A(int a1, char *s1){
			a=a1;str=s1;
		}
		~A(){
			cout << "Huy A" << endl;
			a=0;if (str!=NULL) delete(str);
		}
		void xuat(){
			cout << endl << "So nguyen lop A= " << a << "| chuoi lop a = " << str;
		}
};
class B{
	private:
		int b;
    protected:
		char *str;
	public:
		B(){
			b=0;str=NULL;
		}
		B(int a1, char *s1){
			b=a1;str=s1;
		}
		~B(){
			cout << "Huy A" << endl;
			b=0;if (str!=NULL) delete(str);
		}
		void xuat(){
			cout << endl << "So nguyen lop A= " << b << "| chuoi lop a = " << str;
		}
};

class C: public B, virtual public A{
	public :
		C() : B(),A() {
		}
		C(int a1,char *s1,int a2,char *s2):A(a1,s1),B(a2,s2){
			cout << "khoi tao c co bien" << endl;
		}
		~C(){
			// huy chi can huy thanh phan cua C, cac thanh phan ke thua tu goi ham huy
			cout << "huy C";
		}
		void xuat(){
			cout << "Class C :" << endl;
			//A :: xuat();
			B :: xuat();
			cout << endl << "co 2 chuoi la : " << A::str << "va" << B::str;
			// 2 gia tri co pham vi protected nen co the truy cap boi ham ke thua nhung khong the truy cao ben ngoai
		}
};
class D: virtual public A{
	public :
		D() : A() {
		}
		D(int a1,char *s1):A(a1,s1){
			cout << "khoi tao D  co bien"<< endl;
		}
		~D(){
			// huy chi can huy thanh phan cua C, cac thanh phan ke thua tu goi ham huy
			cout << "huy D";
		}
		void xuat(){
			cout << "class D :" << endl ;
			A :: xuat();
		}
};
class H: public C, public D {
	// vi class C & D deu ke thua A, H ke thua C D -> trung thanh phan ke thua -> virtual
	public:
		H():C(),D(){}
		H(int a1,char *s1,int a2, char *s2,int a3, char *s3) : C(a1,s1,a2,s2), D(a3,s3){}
		~H(){
			cout << "Huy H" << endl;
		}
		void xuat(){
			cout << "-----------class H-----------" << endl;
			D::xuat();
			C::xuat();
		}
};
int main(){
	char s[]="hai",s1[]="ba",s2[]="bon";
	H h(2,s,3,s1,4,s2);


	h.H::xuat();
}
/*
	ban se thay chuong trinh khong hoat dong du khong co loi
	loi o day chinh la ve logic cua virtual class, khi may thuc hien phuong thuc khoi tao H() va xuat()
	no se refuse vi ban chat cua 2 class A da hop nhat nhung menthod xuat() lai coi hai class nay la rieng biet :)))
	kha la dau dau day. loi o contructor thi kha de nhan ra =)), a chi co 1;
	vi the nen virtual chi ap dung khi class chi co data / method khong duoc ke thua 
*/
