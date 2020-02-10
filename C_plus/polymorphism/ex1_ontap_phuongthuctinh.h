/* polymaphims 

*/
#include "iostream"

using namespace std;

class A {
	private :
		int a;
	public :
		A(){
			a=0;
		}
		A(int x){
			a=x;
		}
		void xuat(){
			cout << "\n lop A = " << a;
		}
};
class B : public A{
	private :
		int b;
	public :
		B(int x, int x1) : A(x){
			b=x1;
		}
		void xuat(){
			cout << "\n lop B la : " << b;
			A::xuat();
		}
};
class C : public B{
	private : 
		int c;
	public :
		C(int x, int x1, int x2) : B(x1,x2){
			c=x;
		}
		void reset(){
			c=999;
		}
		void xuat(){
			cout << "\n lop c la : " << c;
			cout << "\n cac lop con lai la : ";
			//this->B::xuat();
			B::xuat();
		}
		
};
void in(A *p){
	cout << "\n|| in dung con tro kieu A" << endl;
	p->xuat();
}
/*
void in2(A *p){
	cout << "\n|| dung con tro lop A de goi phuog thuc lop dan xuat"
	p->reset();
	
}
--> ham nay loi vi class a ko co reset
*/
int main(){
	A a(1);
	B b(2,3);
	C c(4,5,6);
	cout << "\n-----test 1 ---------\n";
	// doi tuong lop nao thi goi method lop do
	a.xuat();
	b.xuat();
	c.xuat();
	cout << "\n-----test 2 ----------\n";
	// doi tuong lop dan xuat co the goi method lop co so qua operator ::
	c.B::xuat();
	c.A::xuat();
	cout << "\n-----test 3 -----------\n";
	// con tro lop co so co the dung de luu dia chi lop xuat xuat vi cung 1 ho
	// nhung khi goi method thi chi dung dc method wwhich is inheritace
	in(&a);
	in(&b);
	in(&c);
	cout << "\n-----test 4 ------------\n";
	// tuong tu o tren :)
	B *p;
	p=&b;
	p->xuat();
	p=&c;
	p->xuat();
	
	
}