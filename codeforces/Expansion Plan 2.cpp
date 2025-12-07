//
// Created by k0itoYuu on 2025/11/23.
//
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    x=abs(x);
    y=abs(y);
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='8'){
            a++;
        }else{
            b++;
        }
    }
    if(x<=n&&y<=n&&x+y<=(2*a+b))cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}