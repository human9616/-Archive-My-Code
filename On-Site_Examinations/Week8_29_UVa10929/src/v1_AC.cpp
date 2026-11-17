#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        while(cin>>n){
                if(n=="0")break;
                bool f=0;
                int a=0,b=0;
                for(int i=0;i<n.size();i++){
                        if(f){
                                a+=n[i]-'0';
                                f=0;
                        }
                        else {
                                b+=n[i]-'0';
                                f=1;
                        }
                }
                if(abs(a-b)==0 || abs(a-b)==11)cout<<n<<" is a multiple of 11.\n";
                else cout<<n<<" is not a multiple of 11.\n";
        }
}
