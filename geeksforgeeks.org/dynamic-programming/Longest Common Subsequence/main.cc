#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define NIL -1

int lcs_len(char str1[], char str2[], int len1, int len2, vector<vector<int>> &memory);

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int A, B;
        cin >> A >> B;

        char str1[A + 1];
        char str2[B + 1];
        cin >> str1;
        cin >> str2;

        vector<vector<int>> memory(A, vector<int>(B, NIL));

        int answer = lcs_len(str1, str2, A, B, memory);

        cout << answer << endl;
    }
    return 0;
}

int lcs_len(char str1[], char str2[], int len1, int len2, vector<vector<int>> &memory)
{
    if (len1 == 0)
        return 0;
    if (len2 == 0)
        return 0;

    if (memory[len1 - 1][len2 - 1] != NIL)
        return memory[len1 - 1][len2 - 1];

    int answer;
    if (str1[len1 - 1] == str2[len2 - 1])
        answer = lcs_len(str1, str2, len1 - 1, len2 - 1, memory) + 1;
    else
        answer = max(lcs_len(str1, str2, len1 - 1, len2, memory), lcs_len(str1, str2, len1, len2 - 1, memory));

    memory[len1 - 1][len2 - 1] = answer;

    return answer;
}
