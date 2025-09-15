// Author: Tiến Khôi (500M)
#include <bits/stdc++.h>
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
const int N = 2e5 + 5;
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
ii e[N];
vector<int> adj[N];
bool Choose[N];
int deg[N], lt[N], cnt[N], tplt = 0;
void dfs(int u)
{
    lt[u] = tplt;
    for (auto v : adj[u])
        if (!lt[v])
            dfs(v);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    FOR(i, 1, m)
    cin >> e[i].f >> e[i].s;
    int k;
    cin >> k;
    FOR(i, 1, k)
    {
        int x;
        cin >> x;
        Choose[x] = true;
    }
    FOR(i, 1, m)
    {
        int u = e[i].f, v = e[i].s;
        if (Choose[i])
        {
            deg[u]++;
            deg[v]++;
            // cout << u << " " << v << '\n';
        }
        else
        {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    FOR(i, 1, n)
    if (!lt[i])
    {
        ++tplt;
        dfs(i);
    }
    FOR(i, 1, n)
    cnt[lt[i]] += (deg[i] % 2);
    // cout << i << " " << deg[i] << " " << lt[i] << '\n';
    int ans = 0;
    FOR(i, 1, tplt)
    ans += (cnt[i] % 2);
    if (!ans || ans == 2)
        cout << "Yes";
    else
        cout << "No";
}
signed main()
{
    Inp();
    int Case = 1;
    // cin >> Case;
    while (Case--)
        solve();
    return 0;
}
