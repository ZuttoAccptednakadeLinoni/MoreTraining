//
// Created by k0itoYuu on 2025/11/23.
//
#include <bits/stdc++.h>
#define rc p<<1|1
#define N 200005
#define int long long
int n,m, w[N],arr[N];
#define max_n 200005

int prime[max_n + 5] = {0};  //素数表，存储找到的素数
int f[max_n + 5] = {0};      //f[i]表示数字i的因数的个数
int cnt[max_n + 5] = {0};    //cnt[i]表示数字i 最小质因数的幂次
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