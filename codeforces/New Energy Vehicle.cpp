//
// Created by k0itoYuu on 2025/11/24.
//
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
#define pp pair<int,int>
bool cmp(pp a,pp b){
    if(a.first!=b.first)return a.first<b.first;
}
int z[100005];
int d[100005];
queue<int>qu[100005];
void solve(){
    int n,m;
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    for(int i=1;i<=m;i++){
        cin>>z[i]>>d[i];
        qu[d[i]].push(z[i]);
        pq.push({z[i],d[i]});
    }
    int now=0;
    for(int i=1;i<=m;i++){
        //cout<<i<<endl;
        while(now<z[i]&&!pq.empty()){
            now+=arr[pq.top().second];
            pq.pop();
        }

        qu[d[i]].pop();
        if(!qu[d[i]].empty())pq.push({qu[d[i]].front(),d[i]});
    }
    while(!pq.empty()){
        now=pq.top().second;
        pq.pop();
    }
    cout<<now<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}