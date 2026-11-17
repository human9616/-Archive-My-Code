#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,m;
        cin>>n;
        while(n--){
                int ct1=0,ct2=0;
                cin>>m;
                int tmp=m,a=0,i=0;
                while(m>0){
                        a+=m%10*pow(16,i++);
                        m/=10;
                }
                m=tmp;
                while(m>0){
                        if(m%2==1)ct1++;
                        m/=2;
                }

                while(a>0){
                        if(a%2==1)ct2++;
                        a/=2;
                }
                cout<<ct1<<" "<<ct2<<"\n";
        }
}
