#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
#define RI register int
#define CI const int&
using namespace std;
const int N=100005,INF=1e17;
int n,m,a[N],b[N],f[N<<1][12][12]; bool vis[N<<1][12][12];
inline int DP(CI x,CI y,CI z)
{
    if (x>2*n) return 0; if (vis[x][y][z]) return f[x][y][z];
    if (x%2==1)
    {
        int ret=-INF; if (y<m&&y+x/2-z+1<=n)
            ret=max(ret,DP(x+1,y+1,z)+a[y+x/2-z+1]);
        ret=max(ret,DP(x+1,y,z)); f[x][y][z]=ret;
    } else
    {
        int ret=INF; if (z<m&&z+(x+1)/2-y+1<=n)
            ret=min(ret,DP(x+1,y,z+1)-b[z+(x+1)/2-y+1]);
        ret=min(ret,DP(x+1,y,z)); f[x][y][z]=ret;
    }
    return vis[x][y][z]=1,f[x][y][z];
}
signed main()
{
    //freopen("A.in","r",stdin); freopen("A.out","w",stdout);
    RI i,j,k; for (scanf("%lld%lld",&n,&m),i=1;i<=n;++i) scanf("%lld",&a[i]);
    for (i=1;i<=n;++i) scanf("%lld",&b[i]);
    sort(a+1,a+n+1,greater <int>()); sort(b+1,b+n+1,greater <int>());
    return printf("%lld",DP(1,0,0)),0;
}

