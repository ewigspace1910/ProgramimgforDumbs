// bai tong hop kien thuc co ban ve class
// danh sach class thi sinh thi cap 3
// danh sach lien ket dong
// su dung
/*
	constructor(default,coppy, assignment = )
	destructor
	static var
	listlink
	overload operator
	friend function
	cover class : [class_diem] (= [class_thisinh]
	set/get of cover class to get infomation..., you should read slowly and deeply about this contend

*/

#include "iostream"
#include "iomanip"
#include "stdio.h"
#include "string.h"

using namespace std;

class baithi{
	private:
		int toan,van;
	public:
		baithi(){
			toan=van=0;
		}
		baithi(int t,int v){
			toan=t;van=v;
		}
		void inbaithi(){
			cout << "\n\t Diem thi :" << "\n\t\t | Toan : " << toan << "\n\t\t | Van : " << van << endl;
		}
		int gettoan(){
			return toan;
		}
		int getvan(){
			return van;
		}
		void setpoint(int x,int y){
			toan=x;
			van=y;
		}
};

class thisinh{
	private:
		char name[30];
		baithi diem;
		// phan nay co the tao 1 struc infor....

		thisinh *pnext;

		static int sum;
	public:
		thisinh() : diem(){
			strcpy(name,"DanK");
			pnext=NULL;
		}
		thisinh(int x,int y,char *s, thisinh *p) : diem(x,y)
		{
			// gan data thi sinh theo bien so
			strcpy(this->name,s);
			pnext=p;
		}
		~thisinh(){
			strcpy(name,"");
			pnext=NULL;
			sum--;
		}
		// phan nhap 1 list
		friend void lienket(thisinh *p1,thisinh *p2);
		void setthisinh(){
			//nhap thi sinh
			cout << "Nhap thong tin thi sinh : ";
			fflush(stdin);
			cin.get(this->name,30);
			cout << "NHap diem toan van cua thi sinh :";
			int x,y;
			cin >> x >> y;
			diem.setpoint(x,y);

			pnext=NULL;
			sum++;
		}
		thisinh* getdc(){
			return pnext;
		}



		// sapseplist theo diem
		void hoanvi(thisinh *p2){
			// hoan vi ten
				char s[30];
				strcpy(s,p2->name);
				strcpy(p2->name,this->name);
				strcpy(this->name,s);
			//hoan vi diem
				int t2=p2->diem.gettoan();
				int v2=p2->diem.getvan();
				int t1=this->diem.gettoan();
				int v1=this->diem.getvan();

				p2->diem.setpoint(t1,v1);
				this->diem.setpoint(t2,v2);

			//giu nguyen lien ket
		}
		int getpoint(){
			return diem.gettoan()+diem.getvan();
		}
		friend void sortlist(thisinh *p);

		// phan in
		void in(){
			cout << "\t|Name :" << name;
			diem.inbaithi();
		}
		static void insum();
		friend ostream& operator<< (ostream& os,  thisinh *x );



};

int thisinh :: sum = 0;
void thisinh :: insum(){
	cout << "Tong so thi sinh la: " << sum;
}

void lienket(thisinh *p1, thisinh *p2){
	p1->pnext = p2;
}

ostream& operator<< (ostream& os, thisinh *x ){
	os << "\n -----------------INFORMATION OF STUDENT--------------";
	(*x).in();
	return os;
}
void sortlist (thisinh *pdau){
	thisinh *pnext,*p;
	int tong1,tong2;
	p=pdau;
	
	while (p!=NULL){
		pnext=p->getdc();
		while (pnext!=NULL){
			tong1=pnext->getpoint();
			tong2=p->getpoint();
			if (tong1 > tong2)
				pnext->hoanvi(p);
			pnext=pnext->getdc();
		}
		p=p->getdc();
	}
}


int main(){
	thisinh *pdau=NULL,*p,*ptmp;
	char c;
	while(1){
		p= new thisinh;
		p->setthisinh();

		if (pdau==NULL){
			pdau=p;
		}
		else {
			lienket(ptmp,p);
		}
		ptmp=p;

		cout << "\t S to stopp ";
		cin >> c;
		if (c=='S' or c=='s') break;
	}

    sortlist(pdau);

	thisinh :: insum();
	cout << "\n Cac thi sinh la "<< endl;
	p=pdau;
	while(p!=NULL){
		cout << p;
		p=p->getdc();
	}
}






