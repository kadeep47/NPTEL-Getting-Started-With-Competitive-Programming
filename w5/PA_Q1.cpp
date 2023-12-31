
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

// vector<int> parent;
// vector<int> size;

// int findp(int a)
// {
//     if (a == parent[a])
//         return a;
//     return parent[a] = findp(parent[a]);
// }

// void unionbysize(int a, int b)
// {
//     a = findp(a);
//     b = findp(b);
//     if (a != b)
//     {
//         if (a > b)
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }

void dfs(vector<vector<int>> adj, vector <int> &vis, int node){
    vis[node] = 1;
    rep(i,0,adj[node].size()){
        if(vis[adj[node][i]] == 0) dfs(adj,vis,adj[node][i]);
    }
}

void solve()
{
    int flag = 0;
    int n;
    cin >> n;
    int m;
    cin >> m;

    // cout << n  <<  " "<< m <<endl;

    vector<vector<int>> adj(n);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        // cout << x  << " " << y <<  endl;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // for(auto it : adj){
    //     for(auto itt : it){
    //         cout << itt << " " ;
    //     }cout <<endl;
    // }

    // rep(i,0,n){
    //     cout << i << "  --  " ;
    //     rep(j,0,adj[i].size()){
    //         cout << adj[i][j] <<  " ";
    //     }cout<<endl;
    // }

    vector<int> vis(n, 0);

    int cnt = 0;

    rep(i, 0, n)
    {
        if (vis[i] == 0)
        {
            dfs(adj, vis, i);
            cnt++;
        }
    }

    cout << cnt;
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