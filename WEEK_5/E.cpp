// https://atcoder.jp/contests/agc014/tasks/agc014_e
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define mii map<int, int>
#define mib map<int, bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sub(x, l, r) (x).begin() + l, (x).begin() + r
#define rsub(x, l, r) (x).rbegin() + l, (x).rbegin() + r
#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define FORD(i, a, b) for (int i = a, _b = b; i >= _b; i--)

#define lcm(a, b) a / gcd(a, b) * b

#define Yes cout << "YES\n";
#define No cout << "NO\n";
#define YesNo Yes else No
#define NoYes No else Yes

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

#ifdef VanLam
#include <VanLam.h>
#define cer(...) debug_out(__VA_ARGS__)
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define __gcd(a, b) gcd(a, b)
#else
#define cer(...) 20
#define debug(...) 12
#define gcd(a, b) __gcd(a, b)
#endif

// #define int ll

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5;

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const noexcept
    {
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

class DSU
{
public:
    int n;
    vi par, sz;

    DSU(int n)
    {
        this->n = n;
        par.resize(n + 1);
        sz.resize(n + 1);

        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int FIND(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = FIND(par[u]);
    }
};

inline void prepare()
{
}

inline void _VanLam_()
{
    int n;
    cin >> n;
    vpi edges;
    edges.reserve(2 * n);

    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        edges.emplace_back(u, v);
    }

    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        edges.emplace_back(u, v);
    }

    vector<multiset<int>> adj(n + 1);
    unordered_map<pii, int, PairHash> mp;
    for (auto [u, v] : edges)
    {
        adj[u].insert(v);
        adj[v].insert(u);

        mp[{u, v}]++;
    }

    queue<pii> q;

    for (auto &it : mp)
    {
        if (it.se >= 2)
            q.push(it.fi);
    }

    DSU dsu(n);
    int steps = 0;

    while (steps < n - 1)
    {
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            x = dsu.FIND(x);
            y = dsu.FIND(y);

            if (x == y)
                continue;

            if (dsu.sz[x] > dsu.sz[y])
                swap(x, y);

            dsu.par[x] = y;
            dsu.sz[y] += dsu.sz[x];
            steps++;

            for (int z : adj[x])
            {
                int nz = dsu.FIND(z);

                auto itNz = adj[nz].find(x);
                if (itNz != adj[nz].end())
                {
                    adj[nz].erase(itNz);
                }

                if (nz == y)
                {
                    continue;
                }

                adj[nz].insert(y);
                adj[y].insert(nz);

                pii nEdge = {min(nz, y), max(nz, y)};
                if (++mp[nEdge] == 2)
                {
                    q.push(nEdge);
                }
            }

            adj[x].clear();
            break;
        }
        if (steps == n - 1)
        {
            break;
        }
        if (q.empty())
        {
            No return;
        }
    }

    Yes return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("VanLam.inp", "r"))
    {
        freopen("VanLam.inp", "r", stdin);
        freopen("VanLam.out", "w", stdout);
    }

    prepare();

    int Case = 1;
    // cin >> Case;
    while (Case--)
    {
        cer("- - - -", Case, "- - - -");
        _VanLam_();
        cer("= = = = = = = = = =");
    }

    return 0;
}