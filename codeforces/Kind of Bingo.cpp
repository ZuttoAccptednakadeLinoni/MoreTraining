//
// Created by k0itoYuu on 2025/11/14.
//
#include<bits/stdc++.h>
using namespace std;

int mex[100005];
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
//	vector<bool>v(n*m+5);
    for(int i=0;i<=n*m;i++){
        mex[i]=0;
    }

    int ans=-1;
    for(int i=0;i<n*m;i++){
        int q;
        cin>>q;
/*		mp[(int)(q-1)/m]++;
	//	cout<<q/m<<" "<<mp[(int)(q-1)/m]<<endl;
		if(mp[(q-1)/m]==m-k){
			mpp[(q-1)/m]=i+1;//cout<<mpp[(q-1)/m]<<endl;

		}
*/		mex[(q-1)/m]++;

        if(mex[(q-1)/m]>=m-k&&ans==-1){
            ans=i+1;
        }
    }
    if(k>=m){
        cout<<m<<endl;
        return;
    }
    cout<<max(ans,m)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}