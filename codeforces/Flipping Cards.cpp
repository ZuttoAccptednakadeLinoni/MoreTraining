//
// Created by k0itoYuu on 2025/11/19.
//
#include<bits/stdc++.h>
using namespace std;
struct pp{
    int a;
    bool b;
    int c;
};
int arr[200005][2];
bool cmp(pp a,pp b){
    return a.a<b.a;
}
int main(){
    int n;
    cin>>n;
    int a,b;
    vector<pp>v;
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
        v.push_back({arr[i][0],0,i});
        v.push_back({arr[i][1],1,i});
    }
    sort(v.begin(),v.end(),cmp);
    map<int,int>mp;
    int ans=0;
    int hf=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(auto i:v){
        if(hf<(n+1)/2&&mp[i.c]!=1){
            hf++;
            mp[i.c]=1;
            pq.push({arr[i.c][!i.b],i.c});
            ans=i.a;

            //cout<<hf<<" "<<ans<<endl;
            continue;
        }

        if(hf==(n+1)/2){
            while(!pq.empty()&&pq.top().first<ans){
                pq.pop();
            }
            if(mp[i.c]==1){
                ans=i.a;
                mp[i.c]=0;
                //pq.pop();
            }else{
                //cout<<pq.top().first<<endl;
                while(!pq.empty()&&pq.top().first<i.a){
                    mp[pq.top().second]=0;
                    pq.pop();
                }
                if(!pq.empty()&&pq.top().first>=i.a&&mp[pq.top().second]==1){
                    ans=i.a;
                    mp[i.c]=1;
                    mp[pq.top().second]=0;
                    pq.pop();
                    pq.push({arr[i.c][!i.b],i.c});
                }else{
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }

    }
    cout<<ans<<endl;
}
/*
5
1 4
2 5
2 8
7 11
9 10
*/