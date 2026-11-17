#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        cin.ignore();
        while(n--){
                int ans=0;
                string s;
                vector<int> a;
                a.clear();
                getline(cin,s);
                stringstream ss(s);
                while(ss>>s){
                        a.push_back(stoi(s));
                }
                for(int i=0;i<a.size();i++){
                        for(int j=i+1;j<a.size();j++){
                                ans=max(__gcd(a[i],a[j]),ans);
                        }
                }
                cout<<ans<<'\n';
        }
}
