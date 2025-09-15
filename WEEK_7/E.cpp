// Author: Tiến Khôi (500M)
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
const int N = 2e5 + 5;
void Inp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(".inp", "r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
}
int a[N], b[N];
int n;
bool dq(int i, int x) {
    if (i >= n) return false;
    if (a[i - 1] + a[i + 1] - a[i] == x) {
        a[i] = x;
        return true;
    }
    bool check = dq(i + 1, x + a[i] - a[i - 1]);
    if (check) {
        a[i] = x;
        return true;
    }
    return false;
}
void solve()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    if (a[1] != b[1] || a[n] != b[n]) {
        cout << "No";
        return;
    }
    FOR(i, 2, n - 1) {
        int need;
        if (a[i] == b[i]) continue;
        else {
            bool check = dq(i, b[i]);
            if (!check) {
                cout << "No";
                return;
            } else {
                cout << "Yes";
                return;
            }
        }
    }
    return;
}
signed main()
{
    Inp();
    int Case = 1;
    //cin >> Case;
    while (Case--)
        solve();
    return 0;
}
