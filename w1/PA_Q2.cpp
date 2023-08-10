#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int m, n, s, x, temp;
    cin >> m >> n >> s >> x;

    int count = 2 * n + 2 * m - 4;
    vector<int> a(count);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                cin >> a[(j + s) % count];
            else if (i == m - 1)
                cin >> a[(m + 2 * n - j - 3 + s) % count];
            else if (j == 0)
                cin >> a[(2 * m + 2 * n - i - 4 + s) % count];
            else if (j == n - 1)
                cin >> a[(n + i - 1 + s) % count];
            else
                cin >> temp;
        }
    }

    for (int k = 0; k < count; k++)
    {
        int i, j;

        if (k <= n - 1)
        {
            i = 0;
            j = k;
        }
        else if (k <= n + m - 2)
        {
            i = k - n + 1;
            j = n - 1;
        }
        else if (k <= 2 * n + m - 3)
        {
            i = m - 1;
            j = m + 2 * n - k - 3;
        }
        else
        {
            i = 2 * m + 2 * n - k - 4;
            j = 0;
        }

        if ((i + j) % x == 0)
            cout << a[k] << " ";
    }

    cout << endl;
}

int32_t main()
{
    solve();
    return 0;
}