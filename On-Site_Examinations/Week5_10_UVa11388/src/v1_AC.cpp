#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        while(n--){
                int a,b;
                cin>>a>>b;
                int g=__gcd(a,b);
                int l=(g/a)*b;
                if(l==0)cout<<"-1\n";
                else cout<<g<<" "<<l<<"\n";
        }
}
