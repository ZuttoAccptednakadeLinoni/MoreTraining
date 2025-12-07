//
// Created by k0itoYuu on 2025/11/23.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define pp pair<int,int>
int arr[200005];
void solve(){
    int n,k;
    cin>>n>>k;
    map<int,int>mp;vector<pp>ve;int ans=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }


    int l=0,r=0;
    int now=0;
    for(auto i:mp)ve.push_back(i);
    for(auto i:ve){
        if(r<i.first){
            if(i.second>k){
                l = i.first;
                now = i.second;
                r = l + (now-k);
            }
        }else{
            now+=i.second;
            r=l+(now-k);
        }
        ans=max(ans,now-k);

    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}