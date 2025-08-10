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
const int MOD = 998244353;
const int maxN = 1e5 + 5;

int mobius[maxN], prime[maxN];
inline void prepare()
{
    vi Primes;
    mobius[1] = 1;
    FOR(i, 2, maxN - 1)
    {
        if (!prime[i])
        {
            prime[i] = i;
            Primes.push_back(i);
            mobius[i] = -1;

            for (int p : Primes)
            {
                if (p * i >= maxN)
                    break;
                prime[p * i] = p;
                if (i % p == 0)
                {
                    mobius[p * i] = 0;
                    break;
                }
                else
                    mobius[p * i] = -mobius[i];
            }
        }
    }
}

inline void _VanLam_()
{
    int n, m;
    cin >> n >> m;
    vi L(n), R(n);
    FOR(i, 0, n - 1)
    {
        cin >> L[i] >> R[i];
    }

    int res = 0;

    FOR(d, 1, m)
    {
        if (mobius[d] == 0)
            continue;

        int S = m / d;
        vi left(n), right(n), C(n);
        int base = 0, sumC = 0;
        bool flg = true;

        FOR(i, 0, n - 1)
        {
            left[i] = (L[i] + d - 1) / d;
            right[i] = R[i] / d;
            if (left[i] > right[i])
            {
                flg = false;
                break;
            }
            base += left[i];
            C[i] = right[i] - left[i];
            sumC += C[i];
        }

        if (!flg || S < base)
            continue;

        S = min(S - base, sumC);

        vi cur(S + 1, 0), nDP(S + 1, 0);
        cur[0] = 1;

        FOR(idx, 0, n - 1)
        {
            vi pre(S + 1);
            pre[0] = cur[0];
            FOR(i, 1, S)
            {
                pre[i] = (pre[i - 1] + cur[i]) % MOD;
            }

            FOR(s, 0, S)
            {
                int val = pre[s];
                if (s - C[idx] - 1 >= 0)
                {
                    (val += MOD - pre[s - C[idx] - 1]) %= MOD;
                }
                nDP[s] = val;
            }
            swap(cur, nDP);
            fill(all(nDP), 0);
        }

        int ans = 0;
        FOR(s, 0, S)
        {
            (ans += cur[s]) %= MOD;
        }
        if (mobius[d] == 1)
            (res += ans) %= MOD;
        else
            (res += MOD - ans) %= MOD;
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