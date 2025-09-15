// Author: Tiến Khôi (500M)
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse,sse2,fma")
#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FOD(i, a, b) for (int i = (a); i >= (b); i--)
#define bit(x, y) ((x) >> (y)) & 1
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define f first
#define s second
#define M 1000000007
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
void Inp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(".inp", "r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
}
vector < int > adj[N];
map < ii, int > F;
int a[N], dad[N], depth[N];
void dfs(int u, int par) {
    F[{u, u}] = F[{par, par}] + a[u] * a[u];
    dad[u] = par;
    depth[u] = depth[par] + 1;
    for (auto v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}
struct iii {
    int u, v, id;
} tv[N];
bool comp(iii a, iii b) {
    return (depth[a.u] < depth[b.u]);
}
int ans[N];
int Cal(int u, int v) {
    if (!u) return 0;
    if (F[{u, v}]) return F[{u, v}];
    return (F[{u, v}] = Cal(dad[u], dad[v]) + a[u] * a[v]);
}
void solve()
{
    int n, q;
    cin >> n >> q;
    FOR(i, 1, n)  cin >> a[i];
    FOR(i, 2, n) {
        int j;
        cin >> j;
        adj[i].pb(j);
        adj[j].pb(i);
    }
    dfs(1, 0);
    FOR(i, 1, q) {
        cin >> tv[i].u >> tv[i].v;
        tv[i].id = i;
    }
    sort(tv + 1, tv + q + 1, comp);
    FOR(i, 1, q) {
        int u = tv[i].u, v = tv[i].v, id = tv[i].id;
        ans[id] = Cal(u, v);
    }
    FOR(i, 1, q) cout << ans[i] << '\n';
}
signed main()
{
    Inp();
    int Case = 1;
    //cin >> Case;
    while (Case--)
        solve();
    return 0;
}
