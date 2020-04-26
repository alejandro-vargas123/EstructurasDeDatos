#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double a;
	//cin>>a;
	while(1){
		cin>>a;
		if(a==0) break;
		double num=floor(-(0.5)+sqrt(2*a+(0.25)));
		double total=num+1;
		double pagina=((total*(total + 1)))/2-a;
		cout<<pagina<<" "<<total<<endl;
		//cout<<num<<endl;
	}
	return 0;
}
