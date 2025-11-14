//
// Created by k0itoYuu on 2025/11/14.
//
#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector<int>ve[200005];
int vis[200005];
int visf[200005];
int fin[200005];
int step=0;int n;
queue<int>s;
vector<pp>ans;
int dfsf(int i){
    visf[i]=1;
    //cout<<i<<endl;
    if(i==1){
        s.push(i);
        fin[1]=1;
        return 1;
    }
    for(auto v:ve[i]){
        if(!visf[v]){
            fin[i]=max(dfsf(v),fin[i]);
        }
    }
    if(fin[i]==1)s.push(i);
    return fin[i];
}
void dfs(int u,int lt){
    int q=0;
    //cout<<u<<"!"<<" ";
    vis[u]=1;
    for(auto v:ve[u]){
        if(!vis[v]){
            if(fin[v]==1){
                q=v;
                continue;
            }
            dfs(v,lt+1);
        }
    }
    if(!vis[q]&&q!=0){

        dfs(q,lt+1);
    }
    if(!fin[u]){
        if(step%2==lt%2){
            ans.push_back({1,0});
            ans.push_back({2, u});
            ans.push_back({1,0});
            step+=2;
        }else{
            ans.push_back({2, u});
            ans.push_back({1,0});
            step++;
        }
    }

}
void solve(){
    cin>>n;
    step=0;
    ans.clear();
    for(int i=1;i<=n;i++){
        vis[i]=0;
        visf[i]=0;
        ve[i].clear();
        fin[i]=0;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    fin[n]=1;
    dfsf(n);
    dfs(1,0);
    if(step%2==0)ans.push_back({1,0});
    while(!s.empty()){
        auto i=s.front();
        //cout<<i<<" |";

        s.pop();
        if(i==n)break;
        ans.push_back({2,i});
        ans.push_back({1,0});
    }
    //cout<<endl;
    cout<<ans.size()<<endl;
    for(auto i:ans){
        if(i.first==1)cout<<i.first<<endl;
        else cout<<i.first<<" "<<i.second<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}