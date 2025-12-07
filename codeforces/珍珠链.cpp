//
// Created by k0itoYuu on 2025/11/22.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[500005];
int cf[500005];
int brr[500005];
#define pp pair<int,int>
void solve(){
    int n;
    cin>>n;int f=1;
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]<i)f=0;
        brr[i]=arr[i]-i;
        pq.push({brr[i],i});
        cf[i]=arr[i]-arr[i-1];
    }
    if(!f){
        cout<<-1<<endl;
        return;
    }
    //for(int i=1;i<=n;i++)cout<<cf[i]<<" ";
    //cout<<endl;
    int ans=0;
    int now=1;
    int k=0;
    int ad=0;
    while(!pq.empty()){
        auto i=pq.top();
        pq.pop();
        if(i.second<now||(!pq.empty()&&i.first==pq.top().first))continue;
        //cout<<"||"<<i.first<<" "<<i.second<<endl;
        int qw=i.first-k;
        //cout<<"qw"<<qw<<endl;
        if(qw<ad){
            ans+=qw;
            ad-=qw;
        }else{
            ans+=qw;
            ad=0;
        }
        ans+=i.second-now+1;
        k=i.first;
        //cout<<ad<<"?";
        for(int j=now;j<=i.second;j++){
            //cout<<arr[j]<<" "<<j+k<<"\\";
            ad+=arr[j]-j-k;
        }
        //cout<<ad<<"!";
        now=i.second+1;
        //cout<<now<<" "<<k<<" "<<ans<<endl;
    }
    cout<<ans+ad<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
/*
3
5
1 2 4 5 6
8
1 2 4 5 5 8 10 9
3
3 2 1
*/