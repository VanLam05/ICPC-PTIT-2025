// Author: Tiến Khôi (500M)
#include <bits/stdc++.h>
#define int long long
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
const int N = 1005;
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
struct iii
{
    bool cor;
    int deg, hash;
};
const int base = 311;
int Pow[N];
void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    s = '*' + s;
    int ans = 0;
    map<int, bool> Vis;
    FOR(i, 1, n)
    {
        int Hash = 0, Deg = 0, cnt = 0;
        stack<int> st;
        FOR(j, i, n)
        {
            Hash = (Hash * base % M + s[j]) % M;
            if (s[j] == '(')
            {
                st.push(0);
                ++cnt;
            }
            else
            {
                int tmp = 0;
                while (!st.empty() && st.top())
                {
                    tmp = max(tmp, st.top());
                    st.pop();
                }
                if (st.empty())
                    break;
                st.pop();
                --cnt;
                Deg = max(Deg, tmp + 1);
                st.push(tmp + 1);
                if (!cnt && Deg == k)
                {
                    if (!Vis[Hash])
                    {
                        ++ans;
                        Vis[Hash] = true;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    Inp();
    Pow[0] = 1;
    FOR(i, 1, 1000)
    Pow[i] = Pow[i - 1] * base % M;
    int Case = 1;
    cin >> Case;
    while (Case--)
        solve();
    return 0;
}
