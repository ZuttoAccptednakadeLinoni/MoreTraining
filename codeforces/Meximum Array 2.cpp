//
// Created by k0itoYuu on 2025/11/23.
//
#include<bits/stdc++.h>
using namespace std;
int arr[105];
int brr[105];
int crr[105];
int ans[105];
#define pp pair<int,int>
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        arr[i]=k+1;
        arr[i]=0,brr[i]=0,crr[i]=0,ans[i]=0;
    }
    map<pp,int>ma;
    map<pp,int>mb;
    for(int i=1;i<=q;i++){
        int c,l,r;
        cin>>c>>l>>r;
        if(c==1){
            for(int j=l;j<=r;j++)brr[j]=1;

        }else {
            for(int j=l;j<=r;j++)crr[j]=1;
        }
    }

int now=0;
    for(int i=1;i<=n;i++){
        if(brr[i]==1&&crr[i]==1)ans[i]=k+1;
        if(brr[i]==0&&crr[i]==1) {
            ans[i] = now;
            now++;
            now = (now) % k;
            //cout<<now<<endl;
        }
        if((brr[i]==1)&&crr[i]!=1)ans[i]=k;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}