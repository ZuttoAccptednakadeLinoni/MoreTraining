//
// Created by k0itoYuu on 2025/11/12.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long MOD = 1000000007;


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k==1){
            cout<<n%MOD<<endl;
            continue;
        }
        int a=1,b=1;
        for(int i=3;i<=k*6;i++){
            int c=(a+b)%k;
            if(c%k==0){
                cout<<(i*(n%MOD))%MOD<<endl;
                break;
            }
            a=b;b=c;
        }
    }


}