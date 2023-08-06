
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



void reversort(vi v, int n){
	int cost  =0 ;
	
	for(int i =0 ;i<n-1;i++){
		int mi = *min_element(v.begin()+i,v.end());
		auto it = find(v.begin()+i,v.end(),mi);
		reverse(v.begin()+i,++it);
		cost += ((it-v.begin()) - i);
	}
	
	cout << cost <<endl;
}

void solve()
{
    int cnt = 0;
    int flag = 0;
    int n;    cin >> n;
    vi v(n);    cin >> v;
    return reversort(v,n);
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
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}