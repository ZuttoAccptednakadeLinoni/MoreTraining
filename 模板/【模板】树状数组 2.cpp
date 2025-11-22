//
// Created by k0itoYuu on 2025/11/23.
//
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[500005];

int lowbit(int x) {
    return x&-x;
}
void change(int x,int k) {
    while(x<=n) {
        s[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x) {
    int t=0;
    while(x) {
        t+=s[x];
        x-=lowbit(x);
    }
    return t;
}
int main() {
    cin>>n>>m;
    int op,x,y,k;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=m; i++) {
        cin>>op>>x;
        if(op==1) {
            cin>>y>>k;
            change(x,k);
            change(y+1,-k);
        } else cout<<a[x]+query(x)<<endl;
    }
}