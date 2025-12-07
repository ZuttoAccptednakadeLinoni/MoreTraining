//
// Created by k0itoYuu on 2025/11/20.
//
#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1|1
#define N 200005
#define int long long
int n,m, w[N],arr[N];
#define max_n 200005

int prime[max_n + 5] = {0};  //素数表，存储找到的素数
int f[max_n + 5] = {0};      //f[i]表示数字i的因数的个数
int cnt[max_n + 5] = {0};    //cnt[i]表示数字i 最小质因数的幂次
struct node {
    int l,r,gcd;
} tr[N*4];
void pushup(int p){
    tr[p].gcd=gcd(tr[lc].gcd,tr[rc].gcd);
}
void build(int p,int l,int r) {
    tr[p]= {l,r,w[l]};
    if(l==r)return;
    int m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p].gcd=gcd(tr[rc].gcd,tr[lc].gcd);
}

void update(int p,int x,int y,int k) {
    if(x<=tr[p].l&&tr[p].r<=y) {
        tr[p].gcd=k;
        return;
    }
    int m=(tr[p].l+tr[p].r)>>1;
    if(x<=m)update(lc,x,y,k);
    if(y>m)update(rc,x,y,k);
    pushup(p);
}
int query(int p,int x,int y) {
    if(x<=tr[p].l&&tr[p].r<=y)return tr[p].gcd;
    int m=(tr[p].l+tr[p].r)>>1;
    int sum=0;
    if(x<=m)sum=gcd(sum,query(lc,x,y));
    if(y>m)sum=gcd(sum,query(rc,x,y));
    return sum;
}
void solve(){
    int op,x,y,k;
    //cout<<f[200000]<<" ";
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        w[i]=0;
    }
    arr[n+1]=INT_MAX;
    for(int i=1;i<=n;i++){
        if(arr[i] < arr[i - 1]){
            w[i]=i-1;
        }
    }
    build(1,1,n);
//    cout<<tr[1].gcd<<" ";
    if(tr[1].gcd!=0)cout<<f[tr[1].gcd]<<endl;
    else cout<<n<<endl;
    while(m--) {
        int a,b;
        cin>>a>>b;
        arr[a]=b;
        if(arr[a] < arr[a - 1]){
            update(1,a,a,a-1);
            w[a]=a-1;
        }else{
            update(1,a,a,0);
            w[a]=0;
        }
        if(arr[a+1]<arr[a]){
            update(1,a+1,a+1,a);
            w[a]=a;
        }else if(a!=n){
            update(1,a+1,a+1,0);
            w[a]=0;
        }
//        for(int i=1;i<=n;i++)cout<<w[i]<<" ";
//        cout<<endl;
//        cout<<tr[1].gcd<<" ";

        if(tr[1].gcd!=0)cout<<f[tr[1].gcd]<<endl;
        else cout<<n<<endl;

    }

}
void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {                //若数字i是素数
            prime[++prime[0]] = i;      //存放在prime数组中
            f[i] = 2;                   //素数的因数只有1和本身,所以f[i] = 2
            cnt[i] = 1;                 //i = 1 * i，所以最小质因数的幂次为1
        }
        for (int j = 1; j <= prime[0]; j++) {  //遍历之前找到的素数，若prime[j] 小于数字i的最小质因数，则我们标记prime[i * prime[j]] = 1
            if (i * prime[j] >  max_n) break;  //我们只要在2到max_n范围内的素数，若超过max_n，此时直接跳出
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                //这部分解释见下文
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {  //prime[j]是素数，因此i和prime[j]的因数最多是1和prime[j]，又i % prime[j] != 0，所以i和prime[j]互素
                f[i * prime[j]] = f[i] * f[prime[j]];
                //两元素互素，因此他们的因数除1外没有交集，所以i * prime[j]的因数个数 = i的因数个数 * prime[j]的因数个数

                cnt[i * prime[j]] = 1;
                //因为从prime数组1号位开始向后遍历素数并且i % prime[j] != 0，所以prime[j]始终小于i的最小质因数，
                //所以i * prime[j]最小质因数的幂次为prime[j]的幂次，即为1
            }
        }
    }
    f[1]=1;
    return ;
}
signed main() {
    init();
    int t;
    cin>>t;
    while(t--)solve();
}