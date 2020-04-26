#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    while(cin>>n && n!=0){
        unsigned long long x = floor(sqrt(2*n + 0.25) - 0.5);
        unsigned long long k=(x*(x+1))/2;
        if(n==k) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
