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
#define pp pair<int,int>
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
        //cout<<u<<endl;
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
    //cout<<u<<endl;
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
    //cout<<"sum"<<sum<<endl;
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
    int q,w,ee;
    cin>>q>>w>>ee;
    n=q+w;
    m=ee;
    s=0,t=n+1;
    map<pp,int>mp;
    for(int i=1;i<=q;i++){
        add(0,i,1);
        add(i,0,0);
    }
    for(int i=q+1;i<=n;i++){
        add(i,t,1);
        add(t,i,0);
    }
    while(m--){
        cin>>a>>b;
        b+=q;
        if(!mp[{a,b}]){
            mp[{a,b}]++;
            add(a,b,1);
            add(b,a,0);
        }

    }
    cout<<dinic();
}