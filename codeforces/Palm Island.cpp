//
// Created by k0itoYuu on 2025/11/19.
//
#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int brr[200005];
int qz[2000005];
void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]]=i;
        qz[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>brr[i];
    }
    string ans="";
    int now=1;
    for(int i=n;i>0;i--){
        //cout<<i<<"||\n";
        string q="",e="";
        q.clear();
        e.clear();
        for(int j=1;j<mp[brr[i]];j++){
            if(qz[j]){
                q+='1';
            }
        }
        for(int j=mp[brr[i]]+1;j<=n;j++){
            if(qz[j])e+='2';
        }qz[mp[brr[i]]]=0;
        now++;
        if(q.size()+1==i)continue;
        ans+=q;
        ans+=e;

        for(int j=0;j<now-1;j++){
            ans+='1';
        }
        //for(int i=1;i<=n;i++)cout<<qz[i]<<" ";
//        cout<<endl;
//        cout<<ans<<" ans\n";

    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
/*
2
3
1 2 3
2 3 1
4
1 2 3 4
2 1 3 4
*/