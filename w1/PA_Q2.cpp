
// Author : Kumar Akashdeep
// Github : https://github.com/kadeep47

// Problem :
// Objective :

// Time Complexity :
// space Complexity :

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define st string
#define ld long double
#define pb push_back
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define drep(i, a, n) for (int i = n; i > a; --i)
#define deb(x) cout << #x << x << endl;

#define PI 3.14159265359
#define inf 9e18

template <typename T>
ostream &operator<<(ostream &output, const vector<T> &data)
{
    for (const T &x : data)
    {
        output << x << " ";
    }
    return output;
}
template <typename T>
istream &operator>>(istream &input, vector<T> &data)
{
    for (auto &item : data)
    {
        input >> item;
    }
    return input;
}
int setBits(int n) { return (__builtin_popcountll(n)); }
void print(bool x) { cout << (x ? "YES" : "NO") << '\n'; }
void print(int x) { cout << (x == -1 ? "NO" : "YES") << "\n"; }
constexpr int MOD = 1e9 + 7, mod = 998244353;

const int N = 1e6 + 1;

void precompute() {}

void scrap(vector<vi> v, int m, int n, vi &ans)
{

    for (int j = 0; j < n; j++)
    {
        ans.push_back(v[0][j]);
    }

    for (int i = 1; i < m; i++)
    {
        ans.push_back(v[i][n - 1]);
    }

    for (int j = n - 2; j >= 0; j--)
    {
        ans.push_back(v[m - 1][j]);
    }

    for (int i = m - 2; i >= 1; i--)
    {
        ans.push_back(v[i][0]);
    }
}

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n, m, s, x;
    cin >> n >> m >> s >> x;
    // cout << n << m << s << x << endl;
    vector<vi> v(m, vi(n, 0));

    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }

    vi ans;
    scrap(v, m, n, ans);

    int nn = ans.size();
    cout << ans << endl;

    reverse(ans.begin(), ans.begin() + (nn - s));
    cout << ans << endl;
    reverse(ans.begin() + (nn - s), ans.end());
    cout << ans << endl;
    reverse(all(ans));
    cout << ans << endl;

    vi fin;
    int end = n + m - 1;
    int base = 2;
    rep(i, 0, nn)
    {
        if (i < end && i % x == 0)
            fin.push_back(ans[i]);
        else
        {
            int ii = i;
            ii -= base;
            if (ii % x == 0)
                fin.push_back(ans[i]);
            base += 2;
        }
    }
    cout << fin << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T = 1;

    // cin >> T;

    for (int i = 1; i <= T; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}