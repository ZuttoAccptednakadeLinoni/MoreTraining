//
// Created by k0itoYuu on 2025/11/15.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[200005];
int qz[200005];
int qzz[200005];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        qz[i]=qz[i-1]+arr[i];
    }
    int sum=qz[n];
    qzz[0]=1-qz[0]-1;
    for(int i=1;i<=n;i++){
        qzz[i]=(i+1)*(i+1)-qz[i]-i-1;
        qz[i]=i*i-qz[i]+i;
        //cout<<qz[i]<<" ";
    }
    cout<<endl;
    int ans=sum;
    int mi=INT_MAX;
    for(int i=1;i<=n;i++){
        mi=min(mi,qzz[i-1]);
        ans=max(ans,sum+(qz[i]-mi));
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}