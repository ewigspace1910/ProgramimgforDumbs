// doc ghi dong thi tren tep
#include "iostream"
#include "fstream"

using namespace std;

int main(){
    fstream f;
    f.open("sl.sl",ios::binary | ios::in | ios::out);
    if (f.bad()){
        cout << "\n loi mo file " ;
    }
    else {
        cout << "\n--------------------- viet vao 1 file------------------------";
        for (int i=0;i<10;i++) f << i;
    }
    cout << "\n done!";
    f.close();
}

// neu nhu file la 1 kieu du lieu nhu int,...accumulate
// thi fstream, ostream/ istream la 1 class
