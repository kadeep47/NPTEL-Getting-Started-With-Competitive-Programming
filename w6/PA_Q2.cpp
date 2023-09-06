

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

typedef pair<int, int> Pair;

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
    int src;
    cin >> src;

    vector<vector<pair<int, int>>> v(n);
    vector<int> vis(n, 0);
    rep(i, 0, n)
    {
        int edgecnt;
        cin >> edgecnt;
        rep(j, 0, edgecnt)
        {
            int x, w;
            cin >> x >> w;
            v[i].push_back({w, x});
        }
    }

    vector<int> dis(n, inf);
    dis[src] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int wgt = pq.top().first;
        pq.pop();

        vis[node] = true;

        for (auto it : v[node])
            if ((wgt + (it.first)) < dis[it.second])
            {
                dis[it.second] = wgt + (it.first);
                pq.push({dis[it.second], it.second});
            }
    }

    int ans = *max_element(all(dis));
    if (ans == inf)
        ans = -1;
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T = 1;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}