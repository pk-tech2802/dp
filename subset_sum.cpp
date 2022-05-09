#include <bits/stdc++.h>
using namespace std;
#define fo(i, s, e) for (int i = s; i < e; i++)
#define ll long long
void sol(vector<int> v, int s)
{
    int n = v.size();
    int dp[n + 1][s + 1];
    fo(i, 0, n + 1)
    {
        fo(j, 0, s + 1)
        {
            dp[i][j] = 0;
        }
    }

    fo(i, 0, n + 1)
    {
        dp[i][0] = 1;
    }
    fo(j, 1, s + 1)
    {
        dp[0][j] = 0;
    }

    fo(j, 1, s + 1)
    {
        fo(i, 1, n + 1)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - v[i - 1]] + dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    fo(i, 0, n + 1)
    {
        fo(j, 0, s + 1)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> v;
    v = {1, 2, 3, 5, 6};
    int s = 20;
    sol(v, s);

    return 0;
}
