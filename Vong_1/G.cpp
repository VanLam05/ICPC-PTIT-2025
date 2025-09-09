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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int maxN = 2e6 + 5;

inline void prepare()
{
}

int BIT[maxN];
int n, m, k;

void update(int i, int val)
{
    for (; i <= n; i += i & -i)
    {
        BIT[i] += val;
    }
}

int get(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
    {
        sum += BIT[i];
    }

    return sum;
}

int col[maxN], row[maxN];
bool vis[maxN];
vector<int> point[maxN];

inline void _VanLam_()
{
    cin >> n >> m >> k;
    FOR(i, 1, n)
    row[i] = m + 1;
    FOR(i, 1, m)
    col[i] = n + 1;

    FOR(i, 0, k - 1)
    {
        int x, y;
        cin >> x >> y;

        if (x == 1 && y == 1)
            assert(false);

        point[y].push_back(x);

        row[x] = min(row[x], y);
        col[y] = min(col[y], x);
    }

    int res = 0;
    FOR(i, 1, col[1] - 1)
    {
        res += row[i] - 1;
    }

    FOR(i, col[1], n)
    {
        update(i, 1);
        vis[i] = 1;
    }

    debug(res);

    FOR(y, 1, row[1] - 1)
    {
        int tmp = get(col[y] - 1);
        res += tmp;
        debug(y, tmp);
        for (int x : point[y])
        {
            if (!vis[x])
                update(x, 1);
            vis[x] = 1;
        }
    }

    cout << res;
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