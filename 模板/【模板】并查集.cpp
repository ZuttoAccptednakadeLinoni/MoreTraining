//
// Created by k0itoYuu on 2025/8/3.
//
#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,m,x,y,z;
int fa[N];

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void unset(int x,int y){
    fa[find(x)]=find(y);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    while(m--){
        cin>>z>>x>>y;
        if(z==1) unset(x,y);
        else{
            if(find(x)==find(y)) puts("Y");
            else puts("N");
        }
    }
}