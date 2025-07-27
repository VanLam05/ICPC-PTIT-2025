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
const int maxN = 5e3 + 5;

inline void prepare()
{
}

struct Node
{
    Node *child[26];
    int cnt, end;
    Node()
    {
        cnt = end = 0;
        FOR(i, 0, 25)
        {
            child[i] = nullptr;
        }
    }
};

int n, dp[maxN];
string s;
Node *root;

void insert(const string &s)
{
    Node *cur = root;
    for (char c : s)
    {
        int idx = c - 'a';
        if (cur->child[idx] == nullptr)
            cur->child[idx] = new Node();
        cur = cur->child[idx];
        cur->cnt++;
    }
    cur->end++;
}

void Calc(int pos)
{
    Node *cur = root;
    FOR(i, pos, n - 1)
    {
        int idx = s[i] - 'a';
        if (cur->child[idx] == nullptr)
        {
            return;
        }
        cur = cur->child[idx];
        dp[i + 1] += dp[pos] * cur->end;
        dp[i + 1] %= MOD;
    }
}

inline void _VanLam_()
{
    cin >> s;
    root = new Node();
    int k;
    cin >> k;
    FOR(i, 1, k)
    {
        string tmp;
        cin >> tmp;
        insert(tmp);
    }

    n = s.size();
    dp[0] = 1;

    FOR(i, 1, n)
    {
        Calc(i - 1);
    }
    cout << dp[n];
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