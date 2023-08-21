
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

struct ele
{
    int val;
    int ind;
    int arr;

    ele(int val, int ind, int arr)
        : val(val), ind(ind), arr(arr)
    {
    }
};

struct compareVal
{
    bool operator()(ele const &a, ele const &b)
    {
        if (a.val == b.val)
        {
            if (a.ind == b.ind)
            {
                return a.arr < b.arr;
            }
            return a.ind < b.ind;
        }
        return a.val < b.val;
    }
};

struct compareind
{
    bool operator()(ele const &a, ele const &b)
    {
        if (a.ind == b.ind)
        {
            if (a.val == b.val)
            {
                return a.arr > b.arr;
            }
            return a.val > b.val;
        }
        return a.ind < b.ind; // smaller order of index matter's
    }
};

bool cum(ele const &a, ele const &b)
{
    if (a.val > b.val && a.ind < b.ind)
    {
        return true;
    }

    return false;
}

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n;
    cin >> n;
    int m, days;
    cin >> m >> days;

    vi v(n);
    cin >> v;
    vi vv(m);
    cin >> vv;

    // cout << v << endl;
    // cout << vv << endl;

    priority_queue<ele, vector<ele>, compareVal> pq;
    priority_queue<ele, vector<ele>, compareVal> pq2;
    priority_queue<ele, vector<ele>, compareind> ans;

    rep(i, 0, n)
    {
        pq.push(ele(v[i], i, 1));
    }

    rep(i, 0, m)
    {
        pq.push(ele(vv[i], i, 2));
    }

    int max2 = 0;
    int max1 = 0;

    while (!pq.empty())
    {

        ele e = pq.top();
        // cout << e.val << " " << e.ind << " " << e.arr << endl;

        if (e.arr == 1)
        {
            if (e.ind < max1)
            {
                pq2.push(e);
            }
            else
            {
                ans.push(e);
                max1 = e.ind;
            }
        }
        else
        {
            if (e.ind < max2)
            {
                pq2.push(e);
            }
            else
            {
                ans.push(e);
                max2 = e.ind;
            }
        }
        pq.pop();
        if (ans.size() > days)
            ans.pop();
    }
    // cout << "pq2" << endl;
    // while (!pq2.empty())
    // {

    //     ele e = pq2.top();
    //     cout << e.val << " " << e.ind << " " << e.arr << endl;
    //     pq2.pop();
    // }

    // cout << "asn" << endl;
    // while (!ans.empty())
    // {

    //     ele e = ans.top();
    //     cout << e.val << " " << e.ind << " " << e.arr << endl;
    //     ans.pop();
    // }

    if (ans.size() < days)
    {
        int diff = days - ans.size();
        while (diff--)
        {
            ans.push(pq2.top());
            if (ans.size() > days)
                ans.pop();
            pq2.pop();
        }
    }

    // cout << days << endl;

    vector<ele> va;
    vector<ele> vb;

    while (!ans.empty())
    {
        ele e = ans.top();
        // cout << e.val << " ";
        // cout << e.ind << " " << e.arr << endl;
        if (e.arr == 1)
            va.push_back(e);
        else
            vb.push_back(e);
        ans.pop();
    }

    vector<int> fin;

    int i = 0, j = 0;
    while (i < va.size() && j < vb.size())
    {
        ele ea = va[i];
        ele eb = vb[j];
        if (ea.val < eb.val)
        {
            fin.push_back(ea.val);
            i++;
        }else if (ea.val == eb.val){
            int tempi = i;
            int tempj = j;
            ele base1 = va[i];
            ele base2 = vb[j];
            while(base1.val == base2.val){
                fin.push_back(base1.val);
                tempi++;
                tempj++;
                base1 = va[tempi];
                base2 = vb[tempj];
            }
            if(base1.val > base2.val){
                i = tempi;
            }else{
                j = tempj;
            }
        }
        else
        {
            fin.push_back(eb.val);
            j++;
        }
    }

    while (i < va.size())
    {
        ele ea = va[i];
        fin.push_back(ea.val);
        i++;
    }

    while (j < vb.size())
    {
        ele eb = vb[j];
        fin.push_back(eb.val);
        j++;
    }

    reverse(all(fin));

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