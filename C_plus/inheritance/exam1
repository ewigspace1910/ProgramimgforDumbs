/*
 The inheritane in class
*/

#include "iostream"
#include "cmath"
#include "string.h"
using namespace std;

class person{
	private:
		char *name;
		int year;
	public:
		person(){
			name=NULL;
			year=0;
		}
		~person(){
			name=NULL;
		}
		person(char *s,int y){
			year=y;
			name=s;
		}
		void in(){
			cout << "|| " << name <<" sinh nam : " << year << endl;
		}
};

class MONHOC{
	private:
		char *tenmon;
		int sotiet;
	public:
		MONHOC(){
			tenmon=NULL;
			sotiet=0;
		}
		MONHOC(char *mon, int sotiet){
			this->tenmon=mon;
			this->sotiet=sotiet;
		}
		void inmon(){
			cout << "|| bo mon : " << tenmon << " || "<< sotiet<< " tiet" << endl;
		}
};

class GIAOVIEN : public person
	{
		private :
			int id;
			MONHOC mh;
		public :
			GIAOVIEN():mh(),person(){
				// cac dung ham tao khong doi vs thanh phan doi tuong va class ke thua;
				id=0;
			}
			GIAOVIEN(int code, char *name,int y, char *mon,int num): person(name,y), mh(mon,num)
			{
				id=code;
			}
			void in(){
				person :: in();
				// cach goi phuong thuc cua class ke thua trong class dan xuat
				mh.inmon();
			}
	};

int main(){
	GIAOVIEN p1(1910,"Nguyen Duc Anh",2001,"All",20);
	GIAOVIEN p2; // goi ham tao khong doi;

	cout << "in 1" << endl;
	p1.in();

	cout << "NGUOI::IN"<< endl;
	p1.GIAOVIEN::in();
	cout << "person :: in" << endl;
	p1.person :: in();

	cout << endl << "in 2 :" << endl;
	p2.in();
}
/*
 rut ra ket luan
 -viec ke thua nhieu class de phan biet cac phuong thuc thi dung toan tu pham vi ::
 - khoi tao gia tri mac dinh cua cac thuoc tinh ke thua thi dung ham khoi tao class = ten class
 - su khac biet giua su dung method cua thanh phan class va ke thua chi khac cach goi methdd
        [ten class dan xuat].[phuong thuc class coso]
        <>[ten class co so].[ten phuong thuc]
*/
