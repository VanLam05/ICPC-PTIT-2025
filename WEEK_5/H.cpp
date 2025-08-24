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
const int maxN = 1e3 + 5;

inline void prepare()
{
}

int n, m, r, c;
int board[maxN][maxN], pre[maxN][maxN];

bool SUCCESS(int med)
{
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            int cur = board[i][j] <= med ? 1 : -1;

            pre[i][j] = cur + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }

    FOR(i, r, n)
    {
        FOR(j, c, m)
        {
            int sum = pre[i][j] - pre[i - r][j] - pre[i][j - c] + pre[i - r][j - c];

            if (sum > 0)
            {
                return true;
            }
        }
    }
    return false;
}

inline void _VanLam_()
{
    cin >> n >> m >> r >> c;

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            cin >> board[i][j];
        }
    }

    int l = 0, r = INF;
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