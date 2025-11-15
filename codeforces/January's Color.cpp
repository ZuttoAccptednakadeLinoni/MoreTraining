//
// Created by k0itoYuu on 2025/11/15.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
int arr[300005];
vector<int>ve[300005];
int vis[300005];
int root[300005];
#define pp pair<int,int>
pp p[300005];
int st[300005];
bool cmp(int a,int b){
    return arr[a]<arr[b];
}
void dfs(int u){
    vis[u]=1;
    if(ve[u].size()==1)return;
    for(auto v:ve[u]){
        if(!vis[v]){
            dfs(v);
            root[v]=u;
            if(arr[v]<arr[p[u].first]){
                p[u].second=p[u].first;
                p[u].first=v;
            }else if(arr[v]<arr[p[u].second]){
                p[u].second=v;
            }

        }
    }
    int now=0;
    int q=0;


    arr[u]=min(arr[p[u].first]+arr[p[u].second],arr[u]);
    if(arr[u]<arr[p[root[u]].first]){
        p[root[u]].second=p[root[u]].first;
        p[root[u]].first=u;
    }else if(arr[u]<arr[p[root[u]].second]){
        p[root[u]].second=u;
    }
    st[u]=arr[p[u].first]+arr[p[u].second];
    //cout<<u<<" "<<arr[u]<<endl;
}
const int N=500005;

int dep[N],fa[N][22];

void dfss(int x,int f){ //树增dep,fa
    dep[x]=dep[f]+1; fa[x][0]=f;
    //x上面2,4,8...的祖先fa
    for(int i=1; i<=20; i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int y : ve[x])
        if(y!=f) dfss(y,x);
}
int lca(int x,int y){ //树增lca
    if(dep[x]<dep[y]) swap(x,y);
    //x先大步后小步向上跳，直到与y同层
    for(int i=20; ~i; i--)
        if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return y;
    //x,y一起向上跳，直到lca的下面
    for(int i=20; ~i; i--)
        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int qz[300005];
int viss[300005];
void dfsw(int u){
    viss[u]=1;
    int y=0;
    //cout<<u<<"|";
    if(u!=1){
        if(u==p[root[u]].first){
            y=p[root[u]].second;
        }else y=p[root[u]].first;
        //cout<<y<<endl;
        qz[u]=qz[root[u]]+arr[y];
    }
    for(auto v:ve[u]){
        if(!viss[v]){
            dfsw(v);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    arr[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ve[i].clear();
        vis[i]=0;
        root[i]=0;
        p[i].first=0;
        p[i].second=0;
        dep[i]=0;
        viss[i]=0;
        qz[i]=0;
        for(int j=0;j<21;j++){
            fa[i][j]=0;
        }
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    dfss(1,0);
    dfs(1);
    //viss[1]=1;
    dfsw(1);
//    for(int i=1;i<=n;i++){
//        cout<<p[i].first<<" "<<p[i].second<<endl;
//    }
//    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
//    cout<<endl;
//    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
//    cout<<endl;
//    //for(int i=1;i<=n;i++)cout<<root[i]<<" ";
//    //cout<<endl;
//    for(int i=1;i<=n;i++){
//        if(!ve[i].empty()){
//            sort(ve[i].begin(),ve[i].end(),cmp);
//            //for(auto u:ve[i])cout<<u<<" ";
//            //cout<<"!"<<endl;
//        }
//    }
//for(int i=1;i<=n;i++)cout<<qz[i]<<" ";
//cout<<endl;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        if(b==1){
            cout<<qz[a]-qz[b]<<endl;
        }else{
            //cout<<"lca"<<lca(a,b)<<endl;
            if(lca(a,b)==b){
                cout<<qz[a]-qz[b]<<endl;
            }
            else cout<<-1<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
3
 5 5
 1 2 3 4 5
 1 2
 1 3
 2 4
 2 5
 3 1
 2 1
 4 1
 5 1
 5 2
 5 5
*/