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
const int mxLog = 25;

inline void prepare()
{
}

struct Node
{
    Node *child[2];
    int cnt;

    Node()
    {
        child[0] = child[1] = nullptr;
        cnt = 0;
    }
};

int n, q, curXor;

int getBit(int n, int pos)
{
    return (n >> pos) & 1;
}

void insert(Node *&root, int val, int bit)
{
    if (!root)
        root = new Node();

    root->cnt++;

    if (bit < 0)
    {
        return;
    }

    int idx = getBit(val, bit);
    insert(root->child[idx], val, bit - 1);
}

int findMex(Node *root)
{
    int mex = 0, curBit;

    for (curBit = mxLog; curBit >= 0 && root != nullptr; curBit--)
    {
        Node *ZERO = root->child[getBit(curXor, curBit)];
        Node *ONE = root->child[1 ^ getBit(curXor, curBit)];

        mex <<= 1;
        int need = 1 << curBit;

        if (ZERO == nullptr || ZERO->cnt < need)
        {
            root = ZERO;
        }
        else
        {
            mex |= 1;
            root = ONE;
        }
    }

    debug(mex, curBit);
    mex <<= (curBit + 1);

    return mex;
}

bool vis[maxN];

inline void _VanLam_()
{
    cin >> n >> q;

    Node *root = new Node();
    FOR(i, 1, n)
    {
        int x;
        cin >> x;

        if (vis[x])
            continue;

        vis[x] = true;
        insert(root, x, mxLog);
    }

    while (q--)
    {
        int x;
        cin >> x;
        curXor ^= x;
        cout << findMex(root) << '\n';
    }
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