#include "iostream"
using namespace std;

class sort{
	protected:
		int *a;
		int len;
		void hoanvi(int i, int j){
			int tmp=*(a+i);
			*(a+i)=*(a+j);
			*(a+j)=tmp;
		}
	public :
		virtual void sapsep(int *x, int n){
			a=x;
			len=n;
		}
		void show(){
			for (int i=0;i<len;i++) cout << " " << a[i];
		}
};


class sort_buble: public sort {
	private:
		int *li;
		int len;
	protected :
		void sort_buc(){
			// sua lai nhung cap doi nghich
			// ban chua nang cap
			for (int i=0;i<len-1;i++){
				for (int j=len-1;j>=i;j--){
					if ( *(li+j) > *(li+j+1) )
						hoanvi(j,j+1);
				}
			}
		}
	public :
		virtual void sapsep(int *x, int n){
			sort :: sapsep(x,n);
			li=x;len=n;

			sort_buc();

			cout << "\n bub :";
			show();
			cout << endl;
		}

};

class sort_heap: public sort {
	private:
		int *li;
		int len;
	protected :
		void shift(int i,int right){
			//tao heap chu y vs mang co chi so = 0
			int l=i*2,r=i*2+1; // hai phan tu lien doi
			if (l>right) return;
			if (l==right && a[l]>a[i]) hoanvi(l,i);
			else {
				int k;
				if (a[l]<a[r]) k=l;
				else k=r;
				if (a[i]>=a[k]) return;
				else{
					hoanvi(i,k); // hoanvi lien doi
					
					// hieu ung tu hieu chinh 
					shift(k,right);
				}
			}
		}
		void sort_hea(){
			int right=len-1;
			for (int i=right/2;i>0;i--){
				shift(i,right);
				// right khong doi vi phai hieu chinh , lan truyen toan bo shift
			}
			
			while (right>0){
				hoanvi(1,right);
				right--;
				shift(right);
			}
		}

	public :
        virtual void sapsep(int *x, int n){
			sort :: sapsep(x,n);
			li=x;len=n;
			sort_hea();

			cout << "\n heap sort : " ;
			show();
			cout << endl;
		}
};

class sort_quick: public sort {
	private:
		int *li, len;
	protected :
		void sort_q(int left, int right){
			if (left < right){
				int i=left, j = right;
				int x=li[(i+j)/2];
				while(i<j){
					while ( li[i]<x) i++;
					while ( li[j]>x) j--;
					if (i<=j){
						// co dau bang vi gap th i=j=mid
						hoanvi(i,j);
						i++;j--;
					}
				}
				sort_q(left,j);
				sort_q(i,right);
			}
		}
	public :
		virtual void sapsep(int *x, int n){
			sort :: sapsep(x,n);
			li=x;len=n;

			sort_q(0,len-1);

			cout << "\n quick sort : " ;
			show();
		}
};
int a[]={1,3,2,5,7,4,6,10,13,9};
int n=10;
sort_buble sb;
sort_heap sh;
sort_quick sq;

int main(){
	sort *list[6];
	list[1]=&sb;
	list[2]=&sh;
	list[3]=&sq;

	for (int i=1;i<4;i++){
		list[i]->sapsep(a,n);
	}
}
