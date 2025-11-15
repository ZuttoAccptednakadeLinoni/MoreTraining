//
// Created by k0itoYuu on 2025/7/11.
//
#include<bits/stdc++.h>
using namespace std;
int fa[5005],eu,ev,cnt,ans,pd;
int n,m;
struct Edge{
    int u,v,w;
}edge[200005];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

int find (int x){
    while(x!=fa[x])x=fa[x]=fa[fa[x]];
    return x;
}
void kruskal(){
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++){
        eu=find(edge[i].u),ev=find(edge[i].v);
        if(eu==ev)continue;
        ans+=edge[i].w;
        fa[ev]=eu;
        if(++cnt==n-1){
            pd=1;
            break;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    kruskal();

    if(!pd)cout<<"orz";
    else cout<<ans;
}