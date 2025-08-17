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

class KMP
{
public:
    static vector<int> LPS(const string &s)
    {
        int n = s.size();
        vector<int> pi(n, 0);
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];

            j += (s[i] == s[j]);
            pi[i] = j;
        }
        return pi;
    }

    static vector<vector<int>> Automaton(const string &s, const char &ch = 'a')
    {
        int n = s.size();
        vector<int> lps = LPS(s);
        vector<vector<int>> aut(n + 1, vector<int>(26, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int c = 0; c < 26; c++)
            {
                if (i > 0 && c + ch != s[i])
                    aut[i][c] = aut[lps[i - 1]][c];
                else
                    aut[i][c] = i + (c + ch == s[i]);
            }
        }

        return aut;
    }
};

bool isSubstring(const string &str, const string &path)
{
    if (path.size() > str.size())
        return false;

    string s = path + '#' + str;
    vi lps = KMP::LPS(s);

    for (int len : lps)
    {
        if (len == path.size())
            return true;
    }

    return false;
}

string merge(const string &a, const string &b)
{
    if (isSubstring(a, b))
        return a;

    if (isSubstring(b, a))
        return b;

    string s = b + '#' + a;
    vi lps = KMP::LPS(s);
    int overlap = lps.back();

    return a + b.substr(overlap);
}

int calcLength(const string &a, const string &b, const string &c)
{
    string s = merge(a, b);
    s = merge(s, c);

    return s.size();
}

inline void _VanLam_()
{
    vector<string> s(3);

    FOR(i, 0, 2)
    {
        cin >> s[i];
    }

    vi index = {0, 1, 2};
    int res = INF;

    do
    {
        res = min(res, calcLength(s[index[0]], s[index[1]], s[index[2]]));
    } while (next_permutation(all(index)));

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