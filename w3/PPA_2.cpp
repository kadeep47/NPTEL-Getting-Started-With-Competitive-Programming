
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

void ankita(vi v, vi vv)
{

    int crt = v[0];
    int i = 1;
    while (true)
    {
        cout << crt << " ";
        if (i % 2)
        {
            auto itvv = upper_bound(all(vv), crt);
            if (itvv == vv.end())
            {
                cout << "Ankita" << endl;
                return;
            }
            else
            {
                crt = vv[itvv - vv.begin()];
            }
        }
        else
        {
            auto itv = upper_bound(all(v), crt);
            if (itv == v.end())
            {
                cout << "Biswas" << endl;
                return;
            }
            else
            {
                crt = v[itv - v.begin()];
            }
        }
    }
}

void biswas(vi v, vi vv)
{
    // same as ankita  fxn
}

void solve()
{
    int cnt = 0;
    int flag = 0;

    int n;
    cin >> n;
    vi v(n);
    cin >> v;

    int m;
    cin >> m;
    vi vv(m);
    cin >> vv;

    sort(all(v));
    sort(all(vv));

    if (v[n - 1] < vv[m - 1])
    {
        cout << "Biswas";
    }
    else
    {
        cout << "Ankita";
    }
    cout << endl;

    if (vv[m - 1] < v[n - 1])
    {
        cout << "Ankita";
    }
    else
    {
        cout << "Biswas";
    }
    cout << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}