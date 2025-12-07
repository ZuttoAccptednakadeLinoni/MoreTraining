//
// Created by k0itoYuu on 2025/11/23.
//
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    int q;
    for(int i=1;i<=n;i++){
        cin>>q;
        mp[q]++;
    }
    int ans=0;
    for(auto i:mp){
        if(i.second>i.first)ans+=i.second-i.first;
        else if(i.second<i.first)ans+=i.second;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}