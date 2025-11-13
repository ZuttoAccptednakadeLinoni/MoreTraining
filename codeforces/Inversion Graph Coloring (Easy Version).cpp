//
// Created by k0itoYuu on 2025/11/12.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long MOD = 1000000007;
int arr[305];
int dp[305][305][305];
void solve(){
    int n;

    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                dp[i][j][k]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                dp[i][j][k]+=dp[i-1][j][k];
                if(arr[i]>=j){
                    dp[i][arr[i]][k]+=dp[i-1][j][k];
                    dp[i][arr[i]][k]%=MOD;
                }
                if(arr[i]<j&&arr[i]>=k){
                    dp[i][j][arr[i]]+=dp[i-1][j][k];
                    dp[i][j][arr[i]]%=MOD;
                }
                //cout<<dp[i][j][k];
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            ans+=dp[n][i][j];
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}