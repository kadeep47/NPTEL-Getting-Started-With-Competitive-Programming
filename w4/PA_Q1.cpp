 
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
#define deb(x) cout<<#x<<x<<endl;

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



void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2));

    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];

    map<int, int> m;
    set<int> left;
    set<int> right;
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
            res[1] = a[i][1];

        m[a[i][0]] = a[i][1];

        auto j = right.find(a[i][0]);

        if (j == right.end())
            left.insert(a[i][0]);
        else
            right.erase(j);

        auto k = left.find(a[i][1]);

        if (k == left.end())
            right.insert(a[i][1]);
        else
            left.erase(k);
    }

    res[0] = *(left.begin());

    for (int i = 0; i < n - 2; i++){
        res[i + 2] = m[res[i]];
    }

    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }

    cout << endl;
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
