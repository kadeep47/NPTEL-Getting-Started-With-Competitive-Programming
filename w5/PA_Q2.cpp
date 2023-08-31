
// Author : Kumar Akashdeep
// Github : https://github.com/kadeep47

// Problem :
// Objective :

// Time Complexity :
// space Complexity :

#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define ll unsigned long long
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

vector<int> ans;

void dfs(vector<vector<int>> edge, vector<int> v, int n, int root, int crt)
{

    if (edge[root][0] == -1 && edge[root][1] == -1)
    {
        ans.push_back(crt);
        return;
    }
    if (edge[root][0] != -1)
    {
        dfs(edge, v, n, edge[root][0], crt*10 + v[edge[root][0]]);
    }
    if (edge[root][1] != -1)
    {
        dfs(edge, v, n, edge[root][1], crt*10 + v[edge[root][1]]);
    }
}

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    // cout << v << endl;

    vector<vector<int>> edge;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        edge.push_back({x, y});
    }

    // for(auto it : edge){
    //     cout << it[0]<< " " << it[1] <<endl;
    // }


    int root = 0;
    int crt = v[0];
    dfs(edge, v, n, root,crt);
    // cout << ans <<endl;

    int fin = 0;

    rep(i,0,ans.size()){
        fin+= ans[i];
    }

    cout << fin ;
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