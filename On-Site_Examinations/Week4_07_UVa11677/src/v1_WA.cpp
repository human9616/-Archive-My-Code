#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b,c,d;
        while(cin>>a>>b>>c>>d){
                if(a==0 && b==0 && c==0 && d==0)break;
                if(a>c)c+=24;
                a*=60;c*=60;
                int t1=a+b,t2=c+d,total=0;
                total=t2-t1;
                if(total<0)total*=-1;
                cout<<total<<"\n";
        }
}
