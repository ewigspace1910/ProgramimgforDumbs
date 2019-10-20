#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a,b, S;
	cin >> a >> b;
	S =a*a*a+b*b*b;
	
	cout << setiosflags(ios :: fixed);
	cout << setprecision(2) << S << endl;
}