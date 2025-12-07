//
// Created by k0itoYuu on 2025/11/24.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[20][20];
int arr[20];
#define mod 998244353
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=arr[i]+(i==j);
        }

    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[j][i]%mod<<" ";
        }
        cout<<endl;
    }
}