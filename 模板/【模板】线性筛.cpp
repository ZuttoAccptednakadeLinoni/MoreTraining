#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10000000
int prime[10000000];
int a[N];
vector<int>v; 
void init(){
    int i,j,len=0;
    prime[0]=1;
    prime[1]=1;
    for(i = 2;i < N ;i++){
        prime[i] = 0;
    }
    for(i = 2; i < N; i++)
    {
        if(!prime[i]){
            a[len++] = i;
        } 
        for(j = 0; j< len &&a [j]*i < N; j++)
        {
            prime[a[j]*i] = 1;
            if(i % a[j] == 0) break;
        }
    }
}

signed main(){
    int i;
    
    init();
    for(i=0;i<N;i++){
        if(!prime[i])v.push_back(i);
    }
    int t;
    cin>>t;
    while(t--)solve();
} 
