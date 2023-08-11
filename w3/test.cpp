#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define fast ios_base::sync_with_stdio(false);
#define input cin.tie(NULL);
#define output cout.tie(NULL);
using namespace std;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

void asquare()
{
    ll n,c=0,ans=LONG_LONG_MAX;
    cin>>n;
    string sn;
    if(isPowerOfTwo(n)==true)
    cout<<"0\n";
    else
    {
        ll j=0,k=0,nn=1;
        string s=to_string(n);
        for(int i=0;i<=60;i++)
        {
            nn=(ll)pow(2,i);
            sn=to_string(nn);
            c=0,j=0,k=0;
            bool bb;
            // cout<<sn<<"\n";
            while(j!=s.length()&&k!=sn.length())
            {
                if(s[j]==sn[k])
                {
                    j++;
                    k++;
                    bb=true;
                }
                else
                {
                    j++;
                    c++;
                    bb=false;
                }
            }
            if(bb=true)
            {
                if(j==s.length())
                {
                    k--;
                    c+=sn.length()-k-1;
                }
                else if(k==sn.length())
                {
                    j--;
                    c+=s.length()-j-1;
                }
            }
            else
            {
                k--;
                c+=sn.length()-k-1;
            }
            if(c==1)
            {ans=1;break;}
            else ans=min(ans,c);
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    fast input output
    ll t;
    cin>>t;
    while(t--)
    {
        asquare();
    }
    return 0;
}