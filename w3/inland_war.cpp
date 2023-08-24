
#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
int main()
{
    int n, m;

    cin >> n >> m;
    vector<pair<int, int>> requests;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        requests.push_back(make_pair(a, b));
    }

    sort(requests.begin(), requests.end(), comp);

    int ans = 0;
    int lastbridge = -1;

    for (auto request : requests)
    {

        if (lastbridge > request.first)
            continue;
        else
        {

            lastbridge = request.second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}