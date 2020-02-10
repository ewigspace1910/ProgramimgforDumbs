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
			f=fopen(s,"wt");
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
			f=fopen(s,"rt");
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
	// ham read chi in ra ki tu thu 25 vi ki tu thu 26 theo kieu doc read text la ki tu ket thuc van ban
}
// kieu open file rt phu hop voi file text;