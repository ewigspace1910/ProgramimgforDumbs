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
		void infile();
		void bosung();
		void suchua();
};

void file::infile(){
	f=fopen(s, "rb");
	int n;
	fseek(f,0,2); // 2= SEEK_END
	n=ftell(f)/sizeof(person);
	cout << "\n co tong cong " << n << " thi sinh : ";
	rewind(f); // tuong tu hAM fseek(f,0,0);
	person *p = new person[n+1];
	fread(p,sizeof(person),n,f);
	for (int i=0;i<n;i++){
		cout << endl << "\t thi sinh id " << (p+i)->id << " co diem toan ly hoa la " << (p+i)->toan << " " << (p+i)->ly << " " << (p+i)->hoa;
	}
}
void file::bosung(){
    f=fopen(s,"ab");
    fseek(f,0,SEEK_END);
    int n=ftell(f)/sizeof(person);
    cout << "\n danh sach co " << n << " nguoi, nhap id=0 de thoat" ;
    person p;
    while(1){
        cout << "\n nhap id nguoi thu " << ++n << " : ";
        cin >> p.id;
        if (p.id==0) break;
        cout << "\n nhap lien tiep diem toan ly hoa : " ;
        cin >> p.toan >> p.hoa >> p.ly;
        fwrite(&p,sizeof(person),1,f);
    }
    cout << "\n qua tirnh bo aung ket thuc";
    fclose(f);
}
void file::suchua(){
    f=fopen(s,"r+b");
    fseek(f,0,SEEK_END);
    int n=ftell(f)/sizeof(person);
    cout << "\n danh sach co " << n ;
    int x;
    person p;
    cout << "\n nhap so thu tu cua nguoi can sua : ";
    cin >> x;
    if (x>n && x<0) printf("\n may dua t a ");
    else{
        fseek(f,(x-1)*sizeof(person),SEEK_SET); // con tro file tinh tu vi tri 0
		fread(&p,sizeof(person),1,f);
		cout << "\n thong tin nguoi bi sua : ";
		cout << endl << "\t thi sinh id " << p.id << " co diem toan ly hoa la " << p.toan << " " << p.ly << " " << p.hoa;

		// nhap newperson
        cout << "\n nhap id thi sinh " ;
        cin >> p.id;
        cout << "\n nhap lien tiep diem toan ly hoa : ";
		cin >> p.toan >> p.ly >> p.hoa;
		//luu
		fseek(f,-sizeof(person),SEEK_CUR);
		fwrite(&p,sizeof(person),1,f);

    }

    fclose(f);
    cout << "\n qua trinh suw haon thanh ";
}
int main(){
	file f;
	char *ss="testdata.sl";
	f.ren(ss);
	//f.writefile();
    f.infile();
	f.bosung();
	f.infile();
	f.suchua();

	cout << "\n in lai danh sach lan cuoi \n";
    f.infile();
}
// ta se thay file txt bi ma hoa vi viet theo kieu br;
// va file coppy se co them ki tu (do la eof, giai thich tu bai text)
