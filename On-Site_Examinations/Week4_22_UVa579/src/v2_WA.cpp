#include<bits/stdc++.h>
using namespace std;
int main(){
        string s;
        while(cin>>s){
                if(s=="0:00")break;
                double h=0,m=0,ans=0;
                int i=0,f=0;
                while(s[i]!=':'){
                        if(i==1){
                                h*=10;
                                h+=(s[i]-'0');
                                f=1;
                        }
                        else h+=s[i]-'0';
                        i++;
                }
                h-=12;
                for(i++;;i++){
                        if(f && i==5)break;
                        if(!f && i==4)break;
                        if((!f && i==3) || (f && i==4) )m*=10;
                        m+=s[i]-'0';
                }
                ans=abs((h*30+0.5*m)-(6*m));
                if(ans>180)ans-=180;
                cout<<fixed<<setprecision(3)<<ans<<"\n";
        }
}
