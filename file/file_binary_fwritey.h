// doc ngau nhien random access file
// using ftell,fseek function to control the file position locator
#include "iostream"
#include "stdio.h"

using namespace std;
struct person{
	int id;
	int toan,ly,hoa;
};

class file{
	private :
		FILE *f;
		char *s;
	public :
		void ren(char *ss){
			s=ss;
		}
		void writefile(){
			f=fopen(s,"wb");
			if (f==NULL){
				cout << "loi file!";
			}
			else {
                cout << "\n danh sach diem, id=0 to exit ";
				int id=1,t,l,h;
				person p;
				while(1){
					cout << "\n nhap id thi sinh " ;
					cin >> p.id;
					if (p.id==0) break;
					cout << "\n nhap lien tiep diem toan ly hoa : ";
					cin >> p.toan >> p.ly >> p.hoa;
					fwrite(&p,sizeof(p),1,f);
					cout <<"|------------------------------------------------|";
				}
				cout << "\n qua trinh nhap ket thuc !";

			}
            fclose(f);
		}

};

int main(){
	file f;
	char *ss="testdata.sl";
	f.ren(ss);
	f.writefile();


}
// ta se thay file txt bi ma hoa vi viet theo kieu br;
// va file coppy se co them ki tu (do la eof, giai thich tu bai text)
