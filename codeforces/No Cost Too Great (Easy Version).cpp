//
// Created by k0itoYuu on 2025/11/13.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int prime[200005];
int a[N];
vector<int>v;
void init(){
    int i,j,len=0;
    prime[0]=1;
    prime[1]=1;
    for(i = 2;i < N ;i++){
        prime[i] = 0;
    }
    for(i = 2; i < N; i++)
    {
        if(!prime[i]){
            a[len++] = i;
        }
        for(j = 0; j< len &&a [j]*i < N; j++)
        {
            prime[a[j]*i] = 1;
            if(i % a[j] == 0) break;
        }
    }
}
int arr[200005];

void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    map<int,int>mpj;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        int q=arr[i];
        int w=0;
        while(q!=1){
            if(q%v[w]==0){
                mp[v[w]]++;
                while(q%v[w]==0)q/=v[w];
            }else{
                if(!prime[q]){
                    mp[q]++;
                    q=1;
                }else w++;
            }

        }
        w=0;
        q=arr[i]+1;
        while(q!=1){
            //cout<<q<<endl;
            if(q%v[w]==0){
                mpj[v[w]]++;
                while(q%v[w]==0)q/=v[w];
            }else{
                if(!prime[q]){
                    mpj[q]++;
                    q=1;
                }else w++;
            }
        }
        //cout<<"!@";
    }
    //cout<<"!!";
    for(int i=1;i<=n;i++){
        int q;
        cin>>q;
    }
    int ans=2;
    //cout<<mx<<endl;
    for(auto i:mp){
        //cout<<i.first<<" "<<i.second<<endl;
        if(i.second>1){
            ans=0;
        }else if(i.second==1&&mpj[i.first]){
            ans=min(ans,1ll);
        }else{
            ans=min(ans,2ll);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    int i;
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    init();
    for(i=0;i<N;i++){
        if(!prime[i])v.push_back(i);
    }

    int t;
    cin>>t;
//    cout<<v.size();
//    for(int i=1;i<=50;i++){
//        cout<<i<<" ";
//    }
    while(t--)solve();
}