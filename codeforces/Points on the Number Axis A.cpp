//
// Created by k0itoYuu on 2025/11/14.
//
#include<bits/stdc++.h>
using namespace std;

int arr[200005];
#define int long long
#define mod 998244353
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}
signed main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
        sum%=mod;
    }
    sort(arr+1,arr+n+1);
    cout<<(sum*binpow(n,mod-2))%mod;
}