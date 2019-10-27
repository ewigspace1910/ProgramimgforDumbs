/*
the inheritane .builting app and up date_order:
	first build class mon_hoc,gv, Bo_mon
	second, update sw : add class luan_van, gv2 inteheriate from gv
*/
#include "iostream"
#include "string.h"
#include "stdio.h"

using namespace std;

class monhoc{
	private:
		char tenmh[25];
		int sotiet;
	public:
		monhoc(){
			tenmh[0]=sotiet=0;
		}
		const monhoc& operator= (const monhoc &x){
			this->sotiet=x.sotiet;
			strcpy(this->tenmh,x.tenmh);
			return x;
		}
		void nhap(){
			cout << "\n nhap ten mon hoc : ";
			fflush(stdin);
			cin.get(tenmh,25);
			cout << "nhap so tiet cua mon : ";
			cin >> sotiet;
		}
		void xuat(){
			cout <<"\n\t mon hoc : " << tenmh << " gom :" << sotiet <<"tiet";
		}
};
class gv{
	private :
		char tengv[30];
		int somon;
		monhoc *mon;
	public :
		gv(){
			tengv[0]=somon=0;
			mon=NULL;
		}
		~gv(){
			if (mon) delete(mon);
			tengv[0]=somon=0;
		}
		void nhap();
		void xuat();
		const gv& operator= (const gv& x);
		int getsm(){
            return somon;
		}
		// cap nhat ver1
		gv* getgv(){
			return this;
		}

};
void gv::nhap(){
	cout << "\n nhap ten gv :";
	fflush(stdin);
	gets(tengv);
	cout << "so mon day :";
	cin >> somon;
	if(mon!=NULL) delete(mon);
	mon = new monhoc[somon+1];
	for (int i=0;i<somon;i++){
		mon[i].nhap();
	}
}
void gv::xuat(){
	cout << "\n * sensei : " << tengv << " day " << somon <<" mon ";
	for (int i=0;i<somon;i++) mon[i].xuat();
}
const gv& gv::operator= (const gv& x){
	strcpy(this->tengv,x.tengv);
	this->somon = x.somon;
	for (int i = 0 ; i < somon; i++){
		(*this).mon[i]=x.mon[i];
	}
	return x;
}
//--------------------------------------------- update lan 1
	//them class lop_chu_nhiem && class gv_2 dc cap nhat

class lopcn{
	private :
		int id,member;
	public :
		lopcn(){
			id=member=0;
		}
		void nhap(){
			cout << "\nnhap id lop    : " ;cin >> id;
			cout << "nhap si so lop : " ;cin >> member;
		}
		void xuat(){
			if (id)
                cout <<"\n\t lop chu nhiem #" << id << " gom " << member << "thanh vien ";
		}
		const lopcn& operator= (const lopcn &x){
			this->id=x.id;
			this->member=x.member;
			return x;
		}
};

class gv2 : public gv {
	private :
		lopcn c;
	public :
		gv2():gv(),c(){}
		~gv2(){};
		void nhap();
		void xuat();
		const gv2& operator= (gv2 &x); // khong de cosnt gv2 

};

void gv2 :: nhap(){
	gv :: nhap();
	int id;
	cout <<"\n gv co chu nhiem lop nao ko 1/0 ";cin >> id;
	if (id) c.nhap();
}
void gv2::xuat(){
	gv::xuat();
	c.xuat();
}
const gv2& gv2::operator= (gv2 &x){
	gv *p1,*p2;
	// gan thanh phan moi
	this->c=x.c;
	// gan thanh phan gv cu thong qua con tro, tan dung toan tu gan;
	p1 = this->getgv();
	p2 = x.getgv(); // lay dia chi
	*p1 = *p2; // gan noi dung;
	return x;
}
//-----------------------------------------------
#define gv gv2 // cap nhat gv->gv2
class school{
	private:
		char tensc[25];
		int sogv;
		gv *person;
	public:
		school(){
			tensc[0]=sogv=0;
			person=NULL;
		}
		~school(){
			if(perror!=NULL) delete(person);
		}
		const school& operator= (const school &x);
		void nhap();
		void sapsep();
		void xuat();
};

void school::nhap(){
	cout << "\n nhap ten truong :";fflush(stdin);gets(tensc);
	cout << "\n nhap so giao vien : "; cin >> sogv;
	if (person!=NULL) delete(person);
	person = new gv[sogv+1];
	for (int i=0; i<sogv; i++){
        cout << "\n------------- gv " << i+1 << "----------------";
		person[i].nhap();
	}
}
void school::xuat(){
	cout << "\n---------------------" << tensc << "-----------------------";
	cout << "\n|---------------------------------------------------------|";
	cout << "\n gom " << sogv << ": ";
	for (int i=0;i<sogv; i++) person[i].xuat();
	cout <<"\n|                                                          |";
	cout <<"\n---------------------no coppyright--------------------------";
}
void school::sapsep(){
	gv tmp;
	int n=sogv;
	for (int i=0; i<n-1 ; i++)
		for (int j=i+1; j<n;j++){
			if (person[i].getsm() < person[j].getsm()){
				tmp = person[i];person[i]=person[j];person[j]=tmp;
			}
		}
}
#undef gv // ket thuc cap nhat ver1
//------------------------------------------------------------
int main(){
	school toan;
	toan.nhap();
	toan.sapsep();
	toan.xuat();
}
