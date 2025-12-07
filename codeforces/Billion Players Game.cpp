//
// Created by k0itoYuu on 2025/11/23.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[200005];
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int q;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int e=0;
    sort(arr+1,arr+n+1);
    if(n%2==1){
        q=arr[n/2+1];
        e=q;
    }else{
        q=arr[n/2];
        e=arr[n/2+1];
    }
    if ((q>=l && q<=r) || (e>=l && e<=r)){
        for(int i=1;i<=n/2;i++){
            ans+=arr[n-i+1]-arr[i];
        }
    }else{
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            a+=abs(arr[i]-l);
        }
        for(int i=1;i<=n;i++){
            b+=abs(arr[i]-r);
        }
        ans=min(a,b);
       // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}