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
const int maxN = 1e5 + 5;

int n;
int a[maxN];
bool isPrimes[maxN];
vi Primes;
inline void prepare()
{
    FOR(i, 2, maxN - 1)
    isPrimes[i] = 1;

    for (int i = 2; i * i < maxN; i++)
    {
        if (!isPrimes[i])
            continue;
        for (int j = i * i; j < maxN; j += i)
            isPrimes[j] = 0;
    }

    FOR(i, 2, maxN - 1)
    {
        if (isPrimes[i])
            Primes.push_back(i);
    }
}

set<int> getPrimes(int n)
{
    debug(n);
    set<int> res;
    for (int p : Primes)
    {
        if (p * p > n)
            break;

        if (n % p != 0)
            continue;

        res.insert(p);
        while (n % p == 0)
        {
            n /= p;
        }
    }

    if (n > 1)
    {
        res.insert(n);
    }

    return res;
}

bool isDivisible(int p)
{
    vi coef(p, 0);
    FOR(i, 0, n)
    {
        int idx;
        if (i == 0)
            idx = 0;
        else
        {
            if (p == 2)
                idx = 1;
            else
                idx = ((i - 1) % (p - 1)) + 1;
        }

        int val = (a[i] % p + p) % p;
        coef[idx] = (coef[idx] + val) % p;
    }

    FOR(i, 0, p - 1)
    {
        if (coef[i] != 0)
            return 0;
    }

    return 1;
}

inline void _VanLam_()
{
    cin >> n;
    int GCD = 0;
    FORD(i, n, 0)
    {
        cin >> a[i];
        GCD = gcd(GCD, abs(a[i]));
    }

    set<int> res = getPrimes(GCD);
    for (int p : Primes)
    {
        if (p > n)
            break;

        if (res.count(p))
            continue;

        if (isDivisible(p))
            res.insert(p);
    }

    for (int ans : res)
        cout << ans << '\n';
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