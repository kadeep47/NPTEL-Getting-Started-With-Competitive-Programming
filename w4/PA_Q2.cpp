

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

int bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int n, int m, int r, int c)
{

    cout << endl;
    vis[r][c] = 1;
    queue<pair<pair<int, int>, int>> q;

    q.push({{r, c}, 1});
    int area = grid[r][c];

    int dirx[] = {-1, 0, 1, 0};
    int diry[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dirx[i];
            int nc = c + diry[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] != 0)
            {
                vis[nr][nc] = 1;
                area += grid[nr][nc];

                q.push({{nr, nc}, area});
            }
        }
    }

    return area;
}

int find(vector<vector<int>> &grid, int n, int m)
{
    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (grid[i][j] != 0)
            {
                int temp = bfs(grid, vis, n, m, i, j);

                ans = max(ans, temp);
            }
        }
    }

    return ans;
}

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> grid;
    rep(i, 0, n)
    {
        vector<int> v;
        rep(i, 0, m)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        grid.push_back(v);
    }

    cnt = find(grid, n, m);
    cout << cnt << endl;
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