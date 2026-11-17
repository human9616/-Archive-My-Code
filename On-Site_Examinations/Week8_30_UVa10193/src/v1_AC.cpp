#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        for(int d=0;d<n;d++){
                string s1,s2;
                int a=0,b=0;
                cin>>s1;
                for(int i=0;i<s1.size();i++)a+=(s1[i]-'0')*pow(2,s1.size()-1-i);
                cin>>s2;
                for(int i=0;i<s2.size();i++)b+=(s2[i]-'0')*pow(2,s2.size()-1-i);
                if(__gcd(a,b)>1)cout<<"Pair #"<<d+1<<": All you need is love!\n";
                else cout<<"Pair #"<<d+1<<": Love is not all you need!\n";
        }
}
