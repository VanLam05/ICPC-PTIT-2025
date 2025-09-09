// Author: Tiến Khôi (500M)
#include <bits/stdc++.h>
// #define int long long
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
const int N = 1005;
void Inp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vector<int> adj[N];
int res;
int F[N], G[N], H[N], Pre_sum[N];
bool vis[N];
int child[N], dp[N], D[N];
int val = 0;
int Reroot(int u)
{
    int ans = 0, num_child = 1;
    D[u] = 0;
    FOR(i, 0, adj[u].size() - 1)
    {
        int v = adj[u][i];
        if (!vis[v])
        {
            val += dp[v] + (D[u] + num_child) * child[v] + H[v] * num_child;
            D[u] += H[v] + child[v];
            num_child += child[v];
        }
    }
    return num_child;
}
int Cal(vector<int> v)
{
    int n = v.size(), sum_node = 0;
    val = 0;
    vector<int> c(n);
    FOR(i, 0, n - 1)
    {
        int u = v[i];
        v[i] = Reroot(u);
        sum_node += v[i];
        c[i] = D[u];
    }
    int mid = n / 2;
    v.insert(v.end(), v.begin(), v.end());
    c.insert(c.end(), c.begin(), c.end());
    F[2 * n] = Pre_sum[2 * n] = 0;
    int r = 2 * n - 1;
    FOD(l, 2 * n - 1, 0)
    {
        Pre_sum[l] = Pre_sum[l + 1] + v[l];
        F[l] = F[l + 1] + Pre_sum[l] + c[l];
        if (r - l + 1 > mid)
        {
            Pre_sum[l] -= v[r];
            F[l] = F[l] - (mid + 1) * v[r] - c[r];
            --r;
        }
    }
    mid = n - mid - 1;
    G[0] = c[0] + v[0];
    Pre_sum[0] = v[0];
    int l = 0;
    FOR(r, 1, 2 * n - 1)
    {
        Pre_sum[r] = Pre_sum[r - 1] + v[r];
        G[r] = G[r - 1] + Pre_sum[r] + c[r];
        if (r - l + 1 > mid)
        {
            Pre_sum[r] -= v[l];
            G[r] = G[r] - (mid + 1) * v[l] - c[l];
            ++l;
        }
    }
    int ans = 0;
    FOR(i, 0, n - 1)
    {
        int l = n + i - 1, r = i + 1;
        ans += v[i] * (G[l] + F[r]) + (sum_node - v[i]) * c[i];
    }
    ans /= 2;
    return val + ans;
}
vector<int> node;
int root;
void dfs_size(int u, int par)
{
    child[u] = 1;
    dp[u] = H[u] = 0;
    FOR(i, 0, adj[u].size() - 1)
    {
        int v = adj[u][i];
        if (v != par)
        {
            dfs_size(v, u);
            dp[u] += dp[v] + (H[u] + child[u]) * child[v] + H[v] * child[u];
            H[u] += H[v] + child[v];
            child[u] += child[v];
        }
    }
}
void dfs(int u, int par)
{
    node.pb(u);
    vis[u] = true;
    FOR(i, 0, adj[u].size() - 1)
    {
        int v = adj[u][i];
        if (v != par)
            dfs(v, u);
    }
    res = min(res, Cal(node));
    node.pop_back();
    vis[u] = false;
}
void solve()
{
    int n;
    cin >> n;
    FOR(i, 1, n)
    adj[i].clear();
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    res = INT_MAX;
    FOR(u, 1, n)
    {
        root = u;
        dfs_size(u, 0);
        dfs(u, 0);
    }
    cout << res << '\n';
}
signed main()
{
    Inp();
    int Case = 1;
    cin >> Case;
    while (Case--)
        solve();
    return 0;
}
