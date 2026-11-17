#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        while(cin>>n){
                if(n=="-1")break;
                if(n[0]=='0' && n[1]=='x'){  //16->10
                int a=0,t=0;
                for(int i=n.size()-1;i>=2;i--){
                        int r;
                        if(n[i]>'A' && n[i]<='F')r=n[i]-'A'+10;
                        else r=n[i]-'0';
                        a+=r%10*pow(16,t++);
                }
                cout<<a<<"\n";
                }
                else{                           //10->16
                string ans="";
                        int a=stoi(n);
                        cout<<"0x";
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
