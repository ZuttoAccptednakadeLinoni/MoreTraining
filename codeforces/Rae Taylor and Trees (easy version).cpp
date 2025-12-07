//
// Created by k0itoYuu on 2025/11/22.
//
#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int brr[200005];
int crr[200005];
int ans[200005];
#define pp pair<int,int>
bool cmp(int a,int b){
    return arr[a]<arr[b];
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        brr[i]=i;
        crr[i]=0;
        ans[i]=0;
    }
    sort(brr+1,brr+1+n,cmp);
    int now=n+1;
    priority_queue<pp>pq;
    for(int i=1;i<=n;i++){
        int q=brr[i];
        //cout<<q<<endl;
        if(q>now)continue;
        for(int j=q+1;j<now;j++){
            ans[j]=q;
            //pq.push({arr[j],j});
        }

        if(arr[q]!=1){
            if(pq.empty()||pq.top().first<arr[q]){
                //cout<<pq.top().first<<" "<<arr[q]<<endl;
                cout<<"No\n";
                return;
            }
            ans[q]=pq.top().second;
        }
        for(int j=q+1;j<now;j++){
            //ans[j]=q;
            pq.push({arr[j],j});
        }now=q;
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        if(arr[i]!=1)cout<<arr[i]<<" "<<arr[ans[i]]<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}