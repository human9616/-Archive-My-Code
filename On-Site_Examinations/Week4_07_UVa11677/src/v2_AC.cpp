#include<bits/stdc++.h>
using namespace std;
int main(){
        int a,b,c,d;
        while(cin>>a>>b>>c>>d){
                if(a==0 && b==0 && c==0 && d==0)break;
                a*=60;c*=60;
                int t1=a+b,t2=c+d,total=0;
                if(t1>t2)t2+=24*60;
                total=t2-t1;
                cout<<total<<"\n";
        }
}
