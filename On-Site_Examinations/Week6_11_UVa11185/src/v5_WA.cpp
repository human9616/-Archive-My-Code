#include<bits/stdc++.h>
using namespace std;
int main(){
        string n;
        int f=0;
        while(cin>>n){
                if(n=="-1")break;
                string s="";
                while(n!="0"){
                        s+=to_string(stoi(n)%3);
                        n=to_string(stoi(n)/3);
                }
                for(int i=s.size()-1;i>=0;i--)
                cout<<s[i];
                cout<<"\n";
        }
}
