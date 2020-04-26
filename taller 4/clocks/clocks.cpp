#include <iostream>
#include <ctime>

using namespace std;

int main(){
    unsigned t0, t1;

    t0=clock();
    for(int a=0;a<2000;a++){
        cout<<a<<endl;
    }
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

}
