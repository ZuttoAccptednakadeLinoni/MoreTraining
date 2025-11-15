//
// Created by k0itoYuu on 2025/7/16.
//
//
// Created by k0itoYuu on 2025/7/16.
//
//
// Created by k0itoYuu on 2025/7/14.
//
#include<bits/stdc++.h>
using namespace std;
struct pd{
    int u,d,m;
};
#define pp pair<int,int>
int n,m,a,b,c;
int arr[200005];
const int N=200005,M=300005;
struct edge{int v,w,ne;};
edge e[M];//边集
int idx,h[N];//点的第一条出边
void add(int a,int b,int c){
    e[idx]={b,c,h[a]};
    h[a]=idx++;
}
void solve(){
    idx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        add(a,b,c);

    }
    queue<pd>q;
    int ans=INT_MAX;
    q.push({1,0,0});
    //cout<<1<<endl;
    while(!q.empty()){
        auto a=q.front();
        //cout<<a.u<<" "<<a.m<<endl;
        q.pop();
        if(a.u==n){
            ans=min(ans,a.m);
            continue;
        }
        for(int i=h[a.u];~i;i=e[i].ne){
            //cout<<e[i].w<<endl;
            if(e[i].w<=a.d+arr[a.u]){
                q.push({e[i].v,a.d+arr[a.u],max(a.m,e[i].w)});
            }

        }
    }
    if(ans==INT_MAX)ans=-1;
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}