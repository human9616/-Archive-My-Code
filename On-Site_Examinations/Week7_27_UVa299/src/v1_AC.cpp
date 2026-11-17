#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t--){
                int n,ct=0;
                cin>>n;
                int c[n];
                for(int i=0;i<n;i++){
                        cin>>c[i];
                }
                for(int i=0;i<n;i++)
                        for(int j=i+1;j<n;j++){
                                if(c[i]>c[j]){
                                        swap(c[i],c[j]);
                                        ct++;
                                }
                        }
        cout<<"Optimal train swapping takes "<<ct<<" swaps.\n";
        }
}
