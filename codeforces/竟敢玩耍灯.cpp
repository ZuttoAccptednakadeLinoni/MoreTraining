//
// Created by k0itoYuu on 2025/11/14.
//
#include<bits/stdc++.h>
using namespace std;
int arr[200005];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        arr[i]=0;
    }
    for(int i=1;i<=m;i++){
        int q;
        cin>>q;
        if(arr[q]==1){
            cout<<"the lights are already on!\n";
        }else{
            int ans=0;
            int w=q;
            while(q<=n){
                if(!arr[q]){
                    arr[q]=1;
                    ans++;

                }
                q+=w;
            }
            cout<<ans<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
