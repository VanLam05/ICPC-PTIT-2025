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

const int INF = 14;
const int MOD = 1e9 + 7;
const int maxN = 1e3 + 5;

inline void prepare()
{
}

int n, m;
int dp[maxN][15][15][15][2];

int DP(int len, int d1, int d2, int d3, int isValid)
{
    if (!isValid)
        return 0;

    if (len == n)
        return d3 != INF;

    int &mem = dp[len][d1][d2][d3][isValid];

    if (mem != -1)
        return mem;

    mem = 0;

    FOR(nD, 1, m)
    {
        if (nD > d3)
        {
            mem += DP(len + 1, d1, d2, d3, 0);
        }
        else if (nD > d2)
        {
            mem += DP(len + 1, d1, d2, min(d3, nD), isValid);
        }
        else if (nD > d1)
        {
            mem += DP(len + 1, d1, min(d2, nD), d3, isValid);
        }
        else
        {
            mem += DP(len + 1, min(d1, nD), d2, d3, isValid);
        }

        mem %= MOD;
    }

    return mem;
}

inline void _VanLam_()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << DP(0, INF, INF, INF, 1) << '\n';
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