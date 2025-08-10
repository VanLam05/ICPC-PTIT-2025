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
const int maxN = 1e6 + 5;

inline void prepare()
{
}

int tot, res;
vi a(12), tmp(12);
vb used(12);

void backTrack(int pos)
{
    if (pos == 12)
    {
        res++;
        return;
    }

    FOR(i, 0, 11)
    {
        if (used[i])
            continue;

        tmp[pos] = a[i];
        used[i] = true;

        if (pos == 3)
        {
            if (tmp[0] + tmp[1] + tmp[2] + tmp[3] == tot)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 6)
        {
            if (tmp[0] + tmp[4] + tmp[5] + tmp[6] == tot)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 8)
        {
            if (tmp[7] + tmp[1] + tmp[4] + tmp[8] == tot)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 10)
        {
            if (tmp[3] + tmp[9] + tmp[10] + tmp[6] == tot)
            {
                backTrack(pos + 1);
            }
        }
        else if (pos == 11)
        {
            if (tmp[7] + tmp[2] + tmp[9] + tmp[11] == tot && tmp[8] + tmp[5] + tmp[10] + tmp[11] == tot)
            {
                backTrack(pos + 1);
            }
        }
        else
        {
            backTrack(pos + 1);
        }

        used[i] = false;
    }
}

inline void _VanLam_()
{
    fill(used.begin(), used.end(), false);
    tot = 0, res = 0;
    FOR(i, 0, 11)
    {
        cin >> a[i];
        tot += a[i];
    }

    if (tot % 3 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    tot /= 3;
    backTrack(0);
    cout << res / 12 << '\n';
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
    cin >> Case;
    while (Case--)
    {
        cer("- - - -", Case, "- - - -");
        _VanLam_();
        cer("= = = = = = = = = =");
    }

    return 0;
}