
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

bool powerOfTwo(int n)
{
if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}


void solve()
{
    ll n, c = 0, ans = LONG_LONG_MAX;
    cin >> n;
    string sn;
    if (powerOfTwo(n) == true)
        cout << "0" <<endl;
    else
    {
        ll j = 0, k = 0, nn = 1;
        string s = to_string(n);
        for (int i = 0; i <= 60; i++)
        {
            nn = (ll)pow(2, i);
            sn = to_string(nn);
            c = 0, j = 0, k = 0;
            bool bb;
            while (j != s.length() && k != sn.length())
            {
                if (s[j] == sn[k])
                {
                    j++;
                    k++;
                    bb = true;
                }
                else
                {

                    // irregularity in  matching the length
                    j++;
                    c++;
                    bb = false;
                }
            }
            if (bb = true)
            {
                if (j == s.length())
                {
                    k--;
                    c += sn.length() - k - 1;
                }
                else if (k == sn.length())
                {
                    j--;
                    c += s.length() - j - 1;
                }
            }
            else
            {

                // adding the remaining part in the stirng due to irregularity 
                k--;
                c += sn.length() - k - 1;
            }
            if (c == 1)
            {
                ans = 1;
                break;
            }
            else
                ans = min(ans, c);
        }
        cout << ans << endl;
    }
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