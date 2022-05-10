#include <bits/stdc++.h>
using namespace std;
#define fo(i, s, e) for (int i = s; i < e; i++)
#define ll long long
int sol(vector<vector<int>> &dp, vector<int> &v, int s, int i, int j, int &cnt)
{
    cnt++;
    if (j == 0)
    {
        return dp[i][j] = 1;
    }
    else if (i == 0)
    {
        return dp[i][j] = 0;
    }

    if (dp[i][j])
    {
        return dp[i][j];
    }

    if (j >= v[i - 1])
    {
        return dp[i][j] = sol(dp, v, s, i - 1, j, cnt) + sol(dp, v, s, i - 1, j - v[i - 1], cnt);
    }
    return dp[i][j] = sol(dp, v, s, i - 1, j, cnt);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> v;
    v = {1, 2, 3, 5, 6};
    int s = 6;
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    int i1 = 5, j1 = 6, cnt = 0;
    int ans = sol(dp, v, s, i1, j1, cnt);

    fo(i, 0, n + 1)
    {
        fo(j, 0, s + 1)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << cnt << "\n";

    return 0;
}
