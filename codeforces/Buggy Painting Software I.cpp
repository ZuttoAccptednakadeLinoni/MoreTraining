//
// Created by k0itoYuu on 2025/11/24.
//
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int q;
            cin>>q;
            mp[q]++;
        }
    }
    priority_queue<int>pq;
    for(auto i:mp){
        if(i.first==0)continue;
        pq.push(i.second);
    }
    int now=mp[0];
    int ans=0;
    int ov=0;
    while(!pq.empty()){
        auto i=pq.top();
        pq.pop();
        if(now*b<(n*m-now-i)*a)ans+=now*b;
        else {
            ans+=(n*m-now-i)*a;
            break;
        }
        now+=i;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}