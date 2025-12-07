//
// Created by k0itoYuu on 2025/11/18.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,arr[200005],ans;
void solve() {
    int n;
    cin>>n;
    int ans=0;
    int m=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        m=max(m,arr[i]);
    }
    for(int i=1;i<n;i++){
        ans+=max(arr[i],arr[i+1]);
    }
    ans+=max(arr[1],arr[n]);
    cout<<ans-m<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> T;
    while (T--) solve();
    return 0;
}