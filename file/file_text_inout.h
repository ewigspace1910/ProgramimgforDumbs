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
                cout << "\n nhap 1 so bag ki ";
                int a;
				cin >> a;
				cout << "\n t se nhap so do theo dang nay %d";
				fprintf(f,"\n t se nhap so do theo dang nay %d",a);
				fprintf(f,"\n dong 2 nay co ki tu bel %c", 7);
				fputs("\n dong 3 dung fputs",f);
                cout << "\n ok man~~";
			}
            fclose(f);
		}
		void coppy(char *s1){
			f=fopen(s,"rt");
			FILE *f2=fopen(s1,"wt");
			cout << "t se coppy file 1->file2 " << s;
			char c[50];
			while( !feof(f) ){
				fgets(c,50,f);
				fputs(c,f2);
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

// other, fscanf running like scanf