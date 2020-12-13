#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

void make_change(int n, int m, vector<int> coins, ull dp[])
{
    for (const int coin : coins)
    {
        for (int i = coin; i <= n; i++)
        {

            dp[i] += dp[i - coin];
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
        {
            cin >> coins[i];
        }

        ull dp[n + 1] = {1};

        make_change(n, m, coins, dp);

        cout << dp[n] << endl;
    }

    return 0;
}