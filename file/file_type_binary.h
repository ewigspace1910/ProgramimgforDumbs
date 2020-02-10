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
                cout << "t se viet het ki tu tu 1->30 vao file";
                for (int i=1;i<31;i++){
                    fputc(i,f);
                }
                cout << "\n ok man~~";
			}
            fclose(f);
		}
		void readfile(){
			f=fopen(s,"rb");
			cout << "t se doc cho m nghe file " << s;
			char c;
			int i=0;
			while( c=fgetc(f) != EOF ){
				cout << "\n ki tu thu " << ++i << " : " << c;
			}
			fclose(f);
		}
};

int main(){
	file f;
	char *ss="hello.txt";
	f.ren(ss);
	f.writefile();
	f.readfile();
	// ham read chi in ra ki tu thu 30 vi ket thuc file bang bit -1
}
// ham fputc, fgetc, deu doc viet 1 ki tu cho ca hai kieu