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

#define Yes cout << "Yes\n";
#define No cout << "No\n";
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

#define int ll

const int INF = 1e18 + 7;
const int MOD = 1e9 + 7;
const int maxN = 1e5 + 5;

inline void prepare()
{
}

#define ai3 array<int, 3>

int n, m, X, Y;
vector<ai3> adj[maxN];
int dist[maxN];

inline void _VanLam_()
{
    cin >> n >> m >> X >> Y;
    FOR(i, 1, m)
    {
        int u, v, t, k;
        cin >> u >> v >> t >> k;
        adj[u].push_back({v, t, k});
        adj[v].push_back({u, t, k});
    }

    fill(dist, dist + maxN, INF);
    dist[X] = 0;

    min_heap<pii> mnHeap;
    mnHeap.push({0, X});

    while (!mnHeap.empty())
    {
        auto [d, u] = mnHeap.top();
        mnHeap.pop();

        if (d != dist[u])
            continue;

        for (auto [v, t, k] : adj[u])
        {
            int nD = (d + k - 1) / k * k + t;
            if (nD < dist[v])
            {
                dist[v] = nD;
                mnHeap.push({nD, v});
            }
        }
    }

    if (dist[Y] == INF)
        dist[Y] = -1;

    cout << dist[Y];
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