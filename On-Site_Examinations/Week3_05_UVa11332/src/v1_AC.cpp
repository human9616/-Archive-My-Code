#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    while(cin>>n && n>0){
        while(n>10){
            long long tmp=0;
            while(n>=1){
                tmp+=n%10;
                n/=10;
            }
            n=tmp;
        }
        cout<<n<<"\n";
    }
}
