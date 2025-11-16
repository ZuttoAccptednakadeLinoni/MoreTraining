//
// Created by k0itoYuu on 2025/11/16.
//
#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,z,fa[20004],c,val[20004];
struct edge {
    int x,y,z;
};
bool cmp(edge x, edge y) {
    return x.z > y.z;
}
vector<edge> v;
vector<int> tr[20004];
int find(int x) {
    if (x != fa[x]) return fa[x] = find(fa[x]);
    return x;
}
void Ex_kruskal() {
    c = n;
    for (int i = 1; i <= n + n; i++) fa[i] = i;
    sort(v.begin(),v.end(),cmp);
    for (auto i : v) {
        int fx = find(i.x),fy = find(i.y);
        if (fx == fy) continue;
        fa[fx] = fa[fy] = ++c;
        val[c] = i.z;
        tr[c].push_back(fx);
        tr[c].push_back(fy);
        if (c == n + n - 1) break;
    }
}
int dep[20004],f[20004][25];
void dfs(int x,int p) {
    dep[x] = dep[p] + 1;
    f[x][0] = p;
    for (int i = 1; i <= 20; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (auto y : tr[x]) {
        if (y == p) continue;
        dfs(y,x);
    }
}
int lca(int x,int y) {
    if (dep[x] < dep[y]) swap(x,y);
    for (int i = 20; i >= 0; i--) {
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        v.push_back({x,y,z});
    }
    Ex_kruskal();
    for (int i = c; i >= 1; i--) {
        if (!dep[i]) dfs(i,0);
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int nd = lca(x,y);
        if (nd == 0) cout << "-1\n";
        else cout << val[nd] << '\n';
    }
    return 0;
}
/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3
*/
/*
A 国有 n 座城市，编号从 1 到 n，城市之间有 m 条双向道路。每一条道路对车辆都有重量限制，简称限重。
现在有 q 辆货车在运输货物，司机们想知道每辆车在不超过车辆限重的情况下，最多能运多重的货物。
*/