//
// Created by k0itoYuu on 2025/11/11.
//
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
void solve(){
    int n,q;
    cin>>n>>q;
    map<int,int>mp;
    map<int,int>ap;
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if(mp[a]==0)mp[a]=b;
        else mp[a]=max(mp[a],b);
        if(ap[b]==0)ap[b]=a;
        else ap[b]=min(ap[b],a);
    }
    cout<<"? 1 "<<n/2<<endl;
    int w;
    cin>>w;
    int ans=0;
    if(w!=0){
        for(auto i:mp){
            if(i.first>=n/2){
                break;
            }
            cout<<"? "<<i.first<<" "<<i.second<<endl;
            cin>>w;
            ans=max(ans,w);
        }
    }else{
        for(auto i:ap){
            if(i.first<=n/2){
                continue;
            }
            cout<<"? "<<i.second<<" "<<i.first<<endl;
            cin>>w;
            ans=max(ans,w);
        }
    }
    cout<<"! "<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}