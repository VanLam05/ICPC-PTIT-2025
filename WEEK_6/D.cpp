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

int bPow(int n, int k, int mod = MOD)
{
    if (k <= 0)
        return 1;

    int res = bPow(n, k >> 1, mod);
    res = res * res % mod;
    if (k & 1)
        res = res * n % mod;
    return res;
}

int Fact[maxN], invFact[maxN];

inline void prepare()
{
    Fact[0] = 1;
    FOR(i, 1, maxN - 1)
    {
        Fact[i] = Fact[i - 1] * i % MOD;
    }
    invFact[maxN - 1] = bPow(Fact[maxN - 1], MOD - 2);
    FORD(i, maxN - 2, 0)
    {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

int C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return Fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

inline void _VanLam_()
{
    int n, m, A, B;
    cin >> n >> m >> A >> B;

    int res = 0;

    FOR(i, 0, n - 2)
    {
        int tmp1 = C(n - 2, i) * C(m - 1, i) % MOD;
        int tmp2 = (i + 2) * bPow(n - i - 2, n - i - 2 - i + 2 - 1) % MOD;
        (tmp2 *= bPow(m, n - i - 3)) %= MOD;
        (res += tmp1 * tmp2 % MOD) %= MOD;
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