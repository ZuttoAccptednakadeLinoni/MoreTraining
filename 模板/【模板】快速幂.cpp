//
// Created by k0itoYuu on 2025/7/4.
//
#include<iostream>
using namespace std;
#define int long long
#define mod 998244353
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}