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

struct Node
{
    int pre, suf, sum;
    bool full;
    Node(int pre, int suf, int sum, bool full) : pre(pre), suf(suf), sum(sum), full(full) {}
};

class LazySegmentTree
{
public:
    int n;
    vector<Node> tree;
    vi lazy;

    LazySegmentTree(int n)
    {
        this->n = n;
        tree.assign(4 * n + 5, Node(0, 0, 0, true));
        lazy.assign(4 * n + 5, 0);
    }

    void push(int id, int l, int r)
    {
        if (lazy[id] == 0)
            return;

        if (lazy[id] == 1)
            tree[id] = Node(r - l + 1, r - l + 1, r - l + 1, true);

        if (lazy[id] == -1)
            tree[id] = Node(0, 0, 0, false);

        if (l != r)
        {
            lazy[id << 1] = lazy[id];
            lazy[id << 1 | 1] = lazy[id];
        }

        lazy[id] = 0;
    }

    Node Merge(const Node &a, const Node &b)
    {
        Node res(0, 0, 0, false);

        res.pre = a.pre;
        if (a.full)
            res.pre += b.pre;

        res.suf = b.suf;
        if (b.full)
            res.suf += a.suf;

        res.sum = max({a.sum, b.sum, a.suf + b.pre});
        res.full = a.full && b.full;
        return res;
    }

    void update(int id, int l, int r, int u, int v, int val)
    {
        push(id, l, r);
        if (l > v || r < u)
            return;

        if (l >= u && r <= v)
        {
            lazy[id] = val;
            push(id, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);

        tree[id] = Merge(tree[id << 1], tree[id << 1 | 1]);
    }

    int getFirstInd(int k)
    {
        Node cur = Node(0, 0, 0, true);

        if (tree[1].sum < k)
            return -1;

        int id = 1;
        int l = 1, r = n;

        while (l < r)
        {
            int mid = l + r >> 1;
            push(id, l, r);
            push(id << 1, l, mid);
            Node tmp = Merge(cur, tree[id << 1]);
            if (tmp.sum >= k)
            {
                id = id << 1;
                r = mid;
            }
            else
            {
                cur = tmp;
                id = id << 1 | 1;
                l = mid + 1;
            }
        }
        return r;
    }
};

inline void prepare()
{
}

inline void _VanLam_()
{
    int n, m;
    cin >> n >> m;

    LazySegmentTree seg(n);
    seg.update(1, 1, n, 1, n, 1);

    int res = 0;
    while (m--)
    {
        char type;
        cin >> type;

        if (type == 'A')
        {
            int k;
            cin >> k;
            if (k == 0)
            {
                continue;
            }
            int ind = seg.getFirstInd(k);

            if (ind == -1)
                res++;
            else
                seg.update(1, 1, n, ind - k + 1, ind, -1);
        }
        else if (type == 'L')
        {
            int l, r;
            cin >> l >> r;

            seg.update(1, 1, n, l, r, 1);
        }
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