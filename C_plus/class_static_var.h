#include "iostream"

using namespace std;

class hoadon{
	private :
		int id, totalfee;
		static int sumbill,summoney;
	public :
		hoadon(){
			id=totalfee=0;
		}
		// static argument phai khoi tao ben ngoai vi la vung nho chung
		~hoadon(){
			sumbill--;
			summoney-=totalfee;
			id=totalfee=0;
		}
		void setbill(){
			cout << "nhap id hoa don x : ";
			cin >> id;
			cout << "nhap gia tri hoa don : ";
			cin >> totalfee;
			sumbill++;
			summoney+=totalfee;
		}
		void inbill (){
			cout << "id  " << id << " : " << totalfee << " dolla" << endl;
		}
		static insum (){
			cout << " so hoa don : " << sumbill << endl;
			cout << " so tien    : " << summoney << endl;
		}
		// static method just use static varilue to process
};
int hoadon :: sumbill = 0;
int hoadon :: summoney =0;
// phai khai bao bien static truoc
// tuong tu khai bao 1 method

int main(){
	hoadon dien[12], *nuoc = new hoadon;
	(*nuoc).setbill();
	for (int i=0 ; i < 2; i++ ) dien[i].setbill();
	for (int i=0 ; i < 2; i++ ) dien[i].inbill();
	(*nuoc).inbill();
	cout << endl;
	hoadon :: insum(); 
	delete(nuoc);
	cout << endl;
	hoadon :: insum(); // vi insum la static method chung cho tat ca bien kieu hoadon (not rieng) nen phai khai bao the nay 
}
