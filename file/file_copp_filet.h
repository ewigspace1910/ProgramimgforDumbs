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
		void coppy(char *s1){
			f=fopen(s,"rb");
			FILE *f2=fopen(s1,"wb");
			cout << "t se coppy file 1->file2 " << s;
			char c;
			while( c=fgetc(f) != EOF ){
				// neu dung ham feof thi can luu y den ki tu cuoi cung, vi feof chi xet vi tri chu khong doc ki tu
				fputc(c,f2);
				fputc(10,f2);
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
	// ham read chi in ra ki tu thu 30 vi ket thuc file bang bit -1
}
// ham fputc, fgetc, deu doc viet 1 ki tu cho ca hai kieu
// ham coppy co the dung eof, da ghi luu y trong sach
