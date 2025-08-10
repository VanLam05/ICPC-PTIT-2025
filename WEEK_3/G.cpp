#include <iostream>
#include <set>
using namespace std;

const int maxN = 1e5 + 5, INF = 1e9 + 7;

int n, m;
int a[maxN];
multiset<int> seg[maxN * 4 + 5];

multiset<int> merge(const multiset<int> &a, const multiset<int> &b)
{
    multiset<int> res;
    for (const int &i : a)
        res.insert(i);
    for (const int &i : b)
        res.insert(i);
    return res;
}

void build(const int &id, const int &l, const int &r)
{
    if (l == r)
    {
        seg[id].insert(a[l]);
        return;
    }

    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    seg[id] = move(merge(seg[id << 1], seg[id << 1 | 1]));
}

void update(const int &id, const int &l, const int &r, const int &pos, const int &val)
{
    if (l > pos || r < pos)
        return;

    seg[id].erase(seg[id].lower_bound(a[pos]));
    seg[id].insert(val);

    if (l == r)
        return;

    int mid = l + r >> 1;
    if (pos <= mid)
        update(id << 1, l, mid, pos, val);
    else
        update(id << 1 | 1, mid + 1, r, pos, val);
}

int query(const int &id, const int &l, const int &r, const int &u, const int &v, const int &x)
{
    if (l > v || r < u)
        return INF;

    if (u <= l && r <= v)
    {
        auto it = seg[id].upper_bound(x);

        if (it == seg[id].end())
            return INF;

        return *it;
    }

    int mid = l + r >> 1;
    return min(query(id << 1, l, mid, u, v, x), query(id << 1 | 1, mid + 1, r, u, v, x));
}

inline void _VanLam_()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    int type, pos, val, u, v, x;

    for (int i = 1; i <= m; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> pos >> val;
            update(1, 1, n, pos, val);
            a[pos] = val;
        }
        else
        {
            cin >> u >> v >> x;

            int res = query(1, 1, n, u, v, x);
            cout << (res == INF ? -1 : res) << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    _VanLam_();

    return 0;
}