//
// Created by k0itoYuu on 2025/11/14.
//
#include<bits/stdc++.h>
using namespace std;
int arr[200005];
bool cmp(int a,int b){
    return a/100<b/100;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    sort(arr,arr+m,cmp);

    int q=0;
    for(int i=0;i<n;i++){
        if(i%2==1){
            cout<<arr[m-1-q]<<" "<<arr[q]<<" "<<arr[m-1-q]<<" "<<arr[q]<<" "<<arr[m-1-q]<<" "<<arr[q]<<"\n";
            q++;
        }
        else cout<<arr[q]<<" "<<arr[m-1-q]<<" "<<arr[q]<<" "<<arr[m-1-q]<<" "<<arr[q]<<" "<<arr[m-1-q]<<"\n";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
