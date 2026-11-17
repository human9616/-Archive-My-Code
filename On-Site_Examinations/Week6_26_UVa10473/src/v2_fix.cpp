#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        while(cin>>n){
                if(n[0]=='-')break;
                if(n[0]=='0' && n[1]=='x'){  //16->10
                long long a=0,t=0;
                for(int i=n.size()-1;i>=2;i--){
                        int r;
                        if(n[i]>='A' && n[i]<='F')r=n[i]-'A'+10;
                        else if(n[i]>='a' && n[i]<='f')r=n[i]-'a'+10;
                        else r=n[i]-'0';
                        a+=r*(long long)pow(16,t++);
                }
                cout<<a<<"\n";
                }
                else{                           //10->16
                string ans="";
                        long long a=stoll(n);
                        cout<<"0x";
                        if(a==0)ans="0";
                        while(a>0){
                                char r=(a%16)-10+'A';
                                if(a%16>=10)ans+=r;
                                else ans+=to_string(a%16);
                                a/=16;
                        }
                        for(int i=ans.size()-1;i>=0;i--)
                        cout<<ans[i];
                        cout<<"\n";
                }
        }

}
