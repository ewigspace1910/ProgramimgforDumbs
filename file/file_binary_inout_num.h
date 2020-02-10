#include "iostream"
#include "stdio.h"

using namespace std;

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
                cout << "\n nhap 5 so nguyen ";
				int a;
				for (int i=0;i<5; i++) {
					cin >> a;
					putw(a,f);
					// ham viet 1 so nguyen theo kieu brinary
				}
				cout << "\n da nhap 5 so nguyen theo kieu brinary";
			}
            fclose(f);
		}
		void coppy(char *s1){
			f=fopen(s,"rt");
			FILE *f2=fopen(s1,"wt");
			cout << "t se coppy file 1->file2 " << s;
			int c;
			while( !feof(f) ){
				c=getw(f);
				cout << c << endl;
				putw(c,f2);
				
			}
			fclose(f);
			fclose(f2);
		}
};

int main(){
	file f;
	char *ss="hello.txt";
	f.ren(ss);
	f.writefile();
	f.coppy("filecp.txt");

}
// ta se thay file txt bi ma hoa vi viet theo kieu br;
// va file coppy se co them ki tu (do la eof, giai thich tu bai text)