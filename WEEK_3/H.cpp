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
const int maxN = 2e2 + 5;

inline void prepare()
{
}

struct Edge
{
    int to, cost, rev;
    Edge(int to, int cost, int rev)
    {
        this->to = to;
        this->cost = cost;
        this->rev = rev;
    }
};

class Dinic
{
public:
    int n;
    vector<vector<Edge>> adj;
    vi level, it;

    Dinic(int n)
    {
        this->n = n;
        adj.assign(n, vector<Edge>());
        level.assign(n, -1);
        it.assign(n, 0);
    }

    void addEdge(int u, int v, int cost)
    {
        adj[u].emplace_back(v, cost, adj[v].size());
        adj[v].emplace_back(u, 0, adj[u].size() - 1);
    }

    bool bfs(int start, int end)
    {
        fill(all(level), -1);
        queue<int> q;
        level[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (const Edge &e : adj[u])
            {
                if (level[e.to] == -1 && e.cost > 0)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[end] != -1;
    }

    int dfs(int u, int t, int f)
    {
        if (u == t)
            return f;

        for (int &i = it[u]; i < adj[u].size(); i++)
        {
            Edge &e = adj[u][i];
            if (e.cost > 0 && level[e.to] == level[u] + 1)
            {
                int d = dfs(e.to, t, min(f, e.cost));
                if (d > 0)
                {
                    e.cost -= d;
                    adj[e.to][e.rev].cost += d;
                    return d;
                }
            }
        }

        return 0;
    }

    int maxFlow(int s, int t)
    {
        int flow = 0;
        while (bfs(s, t))
        {
            fill(all(it), 0);
            while (true)
            {
                int f = dfs(s, t, INF);
                if (f == 0)
                    break;
                flow += f;
            }
        }
        return flow;
    }
};

#define ai3 array<int, 3>

inline void _VanLam_()
{
    int n, m;
    cin >> n >> m;

    vector<ai3> edge(m);
    int tot = 0;
    FOR(i, 0, m - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        tot += w;
        edge[i] = {u, v, w};
    }

    int l = 0, r = tot / n + 1;
    while (r - l > 1)
    {
        int mid = l + r >> 1;

        int s = 0;
        int edgeStart = 0;
        int colorStart = edgeStart + m;
        int T = colorStart + n;

        Dinic dinic(T + 1);

        FOR(i, 0, m - 1)
        {
            int u = edge[i][0], v = edge[i][1], w = edge[i][2];
            dinic.addEdge(s, edgeStart + i, w);
            dinic.addEdge(edgeStart + i, colorStart + u, w);
            dinic.addEdge(edgeStart + i, colorStart + v, w);
        }

        FOR(i, 0, n - 1)
        {
            dinic.addEdge(colorStart + i, T, mid);
        }

        int need = n * mid;
        int f = dinic.maxFlow(s, T);
        if (f == need)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    int res = tot - l * n;
    cout << res << '\n';
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