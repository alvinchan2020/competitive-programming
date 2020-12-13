#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NIL -1

int LCS_len(char str1[], char str2[], int len1, int len2, vector<vector<int>> &dp)
{
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}

vector<char> backtrack(char str1[], char str2[], int len1, int len2, vector<vector<int>> &dp)
{
    vector<char> lcs;

    int i = len1;
    int j = len2;

    while (true)
    {
        if (i == 0 && j == 0)
            break;
        else if (i == 0 && j != 0)
        {
            lcs.push_back(str2[j - 1]);
            j--;
        }
        else if (i != 0 && j == 0)
        {
            lcs.push_back(str1[i - 1]);
            i--;
        }
        else if (str1[i - 1] == str2[j - 1])
        {
            lcs.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                lcs.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                lcs.push_back(str2[j - 1]);
                j--;
            }
        }
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int A, B;
        cin >> A >> B;

        char str1[A + 1];
        char str2[B + 1];
        cin >> str1;
        cin >> str2;

        vector<vector<int>> dp(A + 1, vector<int>(B + 1, NIL));

        int len = LCS_len(str1, str2, A, B, dp);

        /*
        for (int i = 0; i <= A; i++)
        {
            for (int j = 0; j <= B; j++)
            {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        */

        vector<char> lcs = backtrack(str1, str2, A, B, dp);

        for (char c : lcs)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
