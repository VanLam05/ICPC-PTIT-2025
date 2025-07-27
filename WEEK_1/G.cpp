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

int NEED(int a, int b, int m)
{
    if (a <= b)
        return b - a;
    return m - a + b;
}

inline void _VanLam_()
{
    int n, m;
    cin >> n >> m;

    vi a(n + 1);
    FOR(i, 1, n)
    {
        cin >> a[i];
    }

    auto SUCCESS = [&](int x) -> bool
    {
        int pre = 0;
        FOR(i, 1, n)
        {
            int cur = INF;
            if (a[i] >= pre)
            {
                cur = min(cur, a[i]);
            }

            if (x && (a[i] + 1) % m >= pre)
            {
                cur = min(cur, (a[i] + 1) % m);
            }

            if (x)
            {
                int need = NEED((a[i] + 1) % m, pre, m) + 1;
                if (need <= x)
                {
                    cur = min(cur, pre);
                }
            }

            if (cur == INF)
            {
                return false;
            }

            pre = cur;
        }
        return true;
    };

    int l = -1, r = m;
    while (r - l > 1)
    {
        int mid = l + r >> 1;
        if (SUCCESS(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r;
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