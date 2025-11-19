//
// Created by k0itoYuu on 2025/11/18.
//
#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    set<vector<int>>s;
    vector<int>a(n+1),b(n+1);
    while(m--){
        for(int i=1;i<=n;i++)cin>>b[i];
        set<vector<int>>ss;
        for(auto &it:s){
            for(int i=1;i<=n;i++){
                a[i]=it[b[i]];
            }
            ss.insert(a);
        }
        ss.insert(b);
        for(auto &it:ss) s.insert(it);
    }
    cout<<s.size()<<endl;
}
/*
5 4
1 2 3 4 5
5 1 3 4 2
3 4 1 5 2
5 2 4 1 3
*/