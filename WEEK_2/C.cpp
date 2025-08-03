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

// #define int ll

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5;

inline void prepare()
{
}

class HalfEdge
{
public:
    struct Point
    {
        double x, y;
        
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    };

    HalfEdge() : N(0), V(0), M(0) {}

    int N;
    vector<pair<Point, Point>> edges;
    map<pair<int, int>, int> verId;
    vector<Point> points;

    int getVerId(int x, int y)
    {
        pair<int, int> key = {x, y};
        auto it = verId.find(key);
        if (it != verId.end())
            return it->second;

        int id = points.size();
        points.push_back(Point(x, y));

        verId[key] = id;
        return id;
    }

    void addEdge(int x1, int y1, int x2, int y2)
    {
        int u = getVerId(x1, y1);
        int v = getVerId(x2, y2);

        edges.push_back({Point(u, v), Point(0, 0)});

        // edges.back().first = {u, v};
        // edges.back().second = {0, 0};
        N++;
    }

    int V, M;
    struct Half
    {
        int to, rev;
        double angle;
        bool isUsed;
    };
    vector<vector<Half>> adj;

    void buildHalfEdges()
    {
        V = points.size();
        M = edges.size();

        adj.assign(V, vector<Half>());

        for (int i = 0; i < M; i++)
        {
            int u = edges[i].first.x;
            int v = edges[i].first.y;

            Point &A = points[u], &B = points[v];

            double angle_uv = atan2(B.y - A.y, B.x - A.x);
            double angle_vu = atan2(A.y - B.y, A.x - B.x);

            adj[u].push_back({v, (int)adj[v].size(), angle_uv, false});
            adj[v].push_back({u, (int)adj[u].size() - 1, angle_vu, false});
        }

        for (int i = 0; i < V; i++)
        {
            auto &vec = adj[i];
            sort(vec.begin(), vec.end(), [](const Half &a, const Half &b)
                 { return a.angle < b.angle; });
        }

        map<pair<int, int>, int> halfId;
        for (int u = 0; u < V; u++)
        {
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].to;
                halfId[{u, v}] = i;
            }
        }

        for (int u = 0; u < V; u++)
        {
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].to;
                int rev = halfId[{v, u}];
                adj[u][i].rev = rev;
            }
        }
    }

    vector<double> getArea()
    {
        buildHalfEdges();

        vector<double> areas;

        for (int u = 0; u < V; u++)
        {
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                if (adj[u][i].isUsed)
                    continue;

                int cu = u, ci = i;

                vector<int> face;

                while (true)
                {
                    if (adj[cu][ci].isUsed)
                        break;

                    adj[cu][ci].isUsed = true;
                    int v = adj[cu][ci].to;
                    face.push_back(cu);

                    int rev = adj[cu][ci].rev;
                    int next = (rev - 1 + (int)adj[v].size()) % (int)adj[v].size();

                    cu = v;
                    ci = next;

                    if (cu == u && ci == i)
                        break;
                }

                if (face.size() < 3)
                    continue;

                double area = 0.0;
                int K = face.size();
                for (int j = 0; j < K; j++)
                {
                    Point &A = points[face[j]];
                    Point &B = points[face[(j + 1) % K]];

                    area += (A.x * B.y - A.y * B.x);
                }

                area /= 2.0;
                if (area > 1e-9)
                    areas.push_back(area);
            }
        }

        return areas;
    }
};

inline void _VanLam_()
{
    int n;
    cin >> n;

    HalfEdge halfEdge;
    FOR(i, 1, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        halfEdge.addEdge(x1, y1, x2, y2);
    }

    vector<double> areas = halfEdge.getArea();
    double res = 0.0;
    for (double area : areas)
    {
        res += area * area;
    }

    cout << fixed << setprecision(6) << res;
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