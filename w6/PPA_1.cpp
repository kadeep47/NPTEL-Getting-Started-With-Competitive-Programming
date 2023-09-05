
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

void solve()
{

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> edges(n);
    // cout << n << " "  << m <<endl;

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        edges[x - 1].push_back(y - 1);
        edges[y - 1].push_back(x - 1);
    }

    int i = 0;

    // for(auto it : edges){
    //     cout << i+1  << " -- " ;
    //     for(auto itt :  it) cout << itt+1 << "  ";
    //     cout <<endl;
    //     i++;
    // }


    vector<int> vis(n, 0);
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(0);
    vis[0] = 1 ;

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.top();
        q.pop();

        ans.push_back(node);
        for (auto it : edges[node])
        {
            if (vis[it] == 0)
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    rep(i, 0, ans.size()) ans[i]++;
    // ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    cout << ans;
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