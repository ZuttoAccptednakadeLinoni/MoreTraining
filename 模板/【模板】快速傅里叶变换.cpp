//
// Created by k0itoYuu on 2025/8/7.
//
// 迭代版 4.5s
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=3e6;
const double PI=acos(-1);

struct complex{
    double x, y;
    complex operator+(const complex& t)const{
        return {x+t.x, y+t.y};}
    complex operator-(const complex& t)const{
        return {x-t.x, y-t.y};}
    complex operator*(const complex& t)const{
        return {x*t.x-y*t.y, x*t.y+y*t.x};}
}A[N], B[N];
char s1[N], s2[N];
int R[N], ans[N];

void FFT(complex A[],int n,int op){
    for(int i=0; i<n; ++i)
        R[i] = R[i/2]/2 + ((i&1)?n/2:0);
    for(int i=0; i<n; ++i)
        if(i<R[i]) swap(A[i],A[R[i]]);
    for(int i=2; i<=n; i<<=1){
        complex w1({cos(2*PI/i),sin(2*PI/i)*op});
        for(int j=0; j<n; j+=i){
            complex wk({1,0});
            for(int k=j; k<j+i/2; ++k){
                complex x=A[k], y=A[k+i/2]*wk;
                A[k]=x+y; A[k+i/2]=x-y;
                wk=wk*w1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){

        cin>>s1>>s2;
        int n=strlen(s1)-1, m=strlen(s2)-1;
        for(int i=0;i<(n+m)*5;i++){
            ans[i]=0;
            A[i].x=0;
            A[i].y=0;
            B[i].x=0;
            B[i].y=0;
        }
        for(int i=0; i<=n; i++)A[i].x=s1[n-i]-'0';
        for(int i=0; i<=m; i++)B[i].x=s2[m-i]-'0';
        for(m=n+m,n=1;n<=m;n<<=1);
        FFT(A,n,1); FFT(B,n,1);
        for(int i=0;i<n;++i)A[i]=A[i]*B[i];
        FFT(A,n,-1);

        int k=0;
        for(int i=0;i<n+m;i++){
            ans[i]=A[i].x/n+0.5;
        }
        for(int i=n+m-1;i>=2;i--){
            if(ans[i]*2<=ans[i-2]){
                ans[i-2]-=ans[i]*2;
                ans[i]=0;
            }else{
                ans[i]-=ans[i-2]/2;
                ans[i-2]%=2;
            }
        }
        for(int i=0; i<m+n||ans[k]>1||ans[k-1]>1||ans[k-2]>1||ans[k-3]>1||ans[k-4]>1; i++){
            //cout<<i<<endl;

            if(ans[i]>1){
                ans[i+2] += (ans[i])/2;
                ans[i+4] += (ans[i])/2;
            }
            ans[i]%=2;
            if(ans[i+4]*2<=ans[i-2+4]){
                ans[i-2+4]-=ans[i+4]*2;
                ans[i+4]=0;
            }else{
                ans[i+4]-=ans[i-2+4]/2;
                ans[i-2+4]%=2;
            }
            k=i+4;
        }
        while(k>1 && !ans[k-1]) k--;

        while(k>1 && !ans[k-1]) k--;
        for(int i=k-1; i>=0; i--)cout<<ans[i];
        cout<<"\n";
    }

}