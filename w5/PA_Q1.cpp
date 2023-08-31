
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

vector<int> parent;
vector<int> size;

int findp(int a){
    if(a == parent[a]) return a;
    return parent[a] = findp(parent[a]);
}

void unionbysize(int a ,int b){
    a = findp(a);
    b = findp(b);
    if(a!=b){
        if(a>b) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> edge;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        edge.push_back({x-1, y-1});
    }

    parent.resize(n);
    size.resize(n);

    rep(i, 0, n)
    {
        parent[i] = i;
        size[i] = 0;
    }

    for (auto it : edge)
    {
        unionbysize(it[0], it[1]);
    }
    int ans = 0;

    rep(i,0,n){
        if(parent[i] == i) ans++;
    }

    cout << ans ;
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