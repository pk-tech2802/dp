// given array put +/- in front of each element return the no of ways to generate target sum using different combinations 
// vvimp  :- always pass by refference does not work be careful while using pass by refference 

#include <bits/stdc++.h>
using namespace std;
#define fo(i, s, e) for (int i = s; i < e; i++)
#define ll long long

void sol(vector<int> v, int sd, int s, int &cnt)
{

    if (v.size() == 0)
    {
        if (sd == s)
        {
            cnt++;
        }
        return;
    }

    int lst = v[v.size() - 1];
    v.pop_back();
    int s1 = sd - lst;
    int s2 = sd + lst;
    sol(v, s1, s, cnt);
    sol(v, s2, s, cnt);
    return;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> v;
    v = {1, 1, 2, 3};
    int cnt = 0, sd = 0, s = 1;
    sol(v, sd, s, cnt);
    cout << cnt << "\n";

    return 0;
}
