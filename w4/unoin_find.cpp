
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
vector<int> ranker;

void maker(ll a)
{
    parent[a] = a;
    // size[a] = 1;
    ranker[a] =0;
}

ll find_parent(ll a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find_parent(parent[a]);
}


void unionbyrank(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (ranker[a] < ranker[b])
            swap(a, b);
        parent[b] = a;
        if (ranker[a] == ranker[b])
            ranker[a]++;
    }
}

// void  unionbysize(ll a, ll b)
// {
//     a = find_parent(a);
//     b = find_parent(b);
//     if (a != b)
//     {
//         if (a < b)
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<pair<int, int>> v;

    parent.resize(n);
    size.resize(n);
    ranker.resize(n);

    rep(i,0,n){
        maker(i);}
        
        // rep(i,0,n){ //  already given parent array question 
        //     int a ;
        //     cin >> a;
        //     parent[i] = a ;
        // }


    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        // unionbysize(a,b);
        unionbyrank(a,b);
    }


    // rep(i,0,n){ // disjoint set counter 
    //     if(i = find_parent(i)) cnt++;
    // }


    cout<< "parent of 3 " << find_parent(3) << endl;
    rep(i,0,n){
        cout << parent[i] << " ";
    }cout <<endl;


    rep(i,0,n){
        if(i = find_parent(3)){
            cout <<  "ranke r" << ranker[i ] <<endl;
        }
        cout << ranker[i] << " ";
    }cout <<endl;

    // cout << cnt << endl;
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