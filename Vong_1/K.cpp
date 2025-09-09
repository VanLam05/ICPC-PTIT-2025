// Authors: Trà Cũ Vị Sưa
#include <bits/stdc++.h>
// #define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FOD(i, a, b) for (int i = (a); i >= (b); i--)
#define bit(x, y) ((x) >> (y)) & 1
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define f first
#define s second
#define M 1000000007
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 6e5 + 5;
void Inp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("1.inp", "r", stdin);
    // freopen("1.out", "w", stdout);
}
int C[N];
struct Tree
{
    int max_val, val, lazy, pos;
} T[4 * N];
int check = 0;
void Update_val(int id, int l, int r, int x, int u)
{
    T[id].val = x + C[l] - C[u] + 1;
    T[id].max_val = max(T[id].max_val, x + C[r] - C[u] + 1);
    // if (!check) cout << l << " " << r << " " << x << " " << u << " " << T[id].val << '\n';
    T[id].lazy = x;
    T[id].pos = u;
    return;
}
void Lazy(int id, int l, int r)
{
    if (!T[id].pos)
        return;
    int mid = (l + r) / 2;
    Update_val(id * 2, l, mid, T[id].lazy, T[id].pos);
    Update_val(id * 2 + 1, mid + 1, r, T[id].lazy, T[id].pos);
    T[id].lazy = T[id].pos = 0;
    return;
}
void Update(int id, int l, int r, int u, int v, int x)
{
    if (r < u || l > v)
        return;
    if (u <= l && r <= v)
    {
        Update_val(id, l, r, x, u);
        // cout << l << " " << r << " " << T[id].val << " " << T[id].lazy << " " << T[id].pos << '\n';
        return;
    }
    int mid = (l + r) / 2;
    Lazy(id, l, r);
    Update(id * 2, l, mid, u, v, x);
    Update(id * 2 + 1, mid + 1, r, u, v, x);
    T[id].max_val = max(T[id].max_val, max(T[id * 2].max_val, T[id * 2 + 1].max_val));
    T[id].val = max(T[id].val, T[id * 2].val);
}
int Get(int id, int l, int r, int u)
{
    if (l > u)
        return 0;
    // if (v == 4) cout << l << " " << r << " " << T[id].val << " " << T[id].cnt << '\n';
    // if (check) cout << id << " " << l << " " << r << " " << T[id].val << '\n';
    if (r <= u)
        return T[id].max_val;
    // if (l == r) return T[id].val;
    int mid = (l + r) / 2;
    Lazy(id, l, r);
    return max(Get(id * 2, l, mid, u), Get(id * 2 + 1, mid + 1, r, u));
}
void solve()
{
    int q;
    cin >> q;
    vector<int> num;
    ii tv[q + 1];
    FOR(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        tv[i] = {l, r};
        num.pb(l);
        num.pb(r);
        num.pb(l - 1);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    FOR(i, 1, q)
    {
        int l = tv[i].f, r = tv[i].s;
        l = lower_bound(num.begin(), num.end(), l) - num.begin() + 1;
        r = lower_bound(num.begin(), num.end(), r) - num.begin() + 1;
        C[l] = tv[i].f;
        C[l - 1] = tv[i].f - 1;
        C[r] = tv[i].s;
    }
    FOR(i, 1, q)
    {
        int l = tv[i].f, r = tv[i].s;
        l = lower_bound(num.begin(), num.end(), l) - num.begin() + 1;
        r = lower_bound(num.begin(), num.end(), r) - num.begin() + 1;
        //
        int val = Get(1, 1, num.size(), l - 1);
        // cout << "l = " << l << " r = " << r << " val = " << val << '\n';
        Update(1, 1, num.size(), l, r, val);
        // if (l == 5) return;
    }
    int ans = 0;
    // cout << Get(1, 1, num.size(), 1, 3) << '\n';
    check = 1;
    FOR(i, 1, num.size())
    {
        ans = max(ans, Get(1, 1, num.size(), i));
        // cout << Get(1, 1, num.size(), i) << '\n';
        // cout << i << " " << Get(1, 1, num.size(), i, i) << '\n';
    }
    cout << ans;
}
signed main()
{
    Inp();
    int Case = 1;
    // cin >> Case;
    while (Case--)
        solve();
    return 0;
}
