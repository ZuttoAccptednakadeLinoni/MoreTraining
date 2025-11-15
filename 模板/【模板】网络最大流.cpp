//
// Created by k0itoYuu on 2025/6/28.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10010
#define M 200010
int n,m,s,t;
int h[N],d[N],cur[N],idx=1;
struct edge{int v,c,ne;}e[M];

void add(int a,int b,int c){
    e[++idx]={b,c,h[a]};
    h[a]=idx;
}

bool bfs(){
    memset(d,0,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v;
            if(d[v]==0&&e[i].c){
                d[v]=d[u]+1;
                q.push(v);
                if(v==t)return true;
            }
        }
    }
    return false;
}

int dfs(int u, int mf){

    if(u==t)return mf;
    int sum=0;
    for(int i=cur[u];i;i=e[i].ne){
        cur[u]=i;
        int v=e[i].v;
        if(d[v]==d[u]+1 && e[i].c){
            int f=dfs(v,min(mf,e[i].c));
            e[i].c-=f;
            e[i^1].c+=f;
            sum+=f;
            mf-=f;
            if(mf==0)break;
        }
    }
    if(sum==0) d[u]=0;
    return sum;
}

int dinic(){
    int flow=0;
    while(bfs()){
        memcpy(cur,h,sizeof(h));
        flow+=dfs(s,1e9);
        //cout<<flow<<endl;
    }
    return flow;
}

signed main(){
    int a,b,c;
    cin>>n>>m>>s>>t;
    while(m--){
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,0);
    }
    cout<<dinic();
}