#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define ull unsigned long long

int main()
{
    int n;
    cin >> n;

    vector<ull> ugly_numbers;
    ugly_numbers.push_back(1);

    int i2 = 0, i3 = 0, i5 = 0;
    ull ugly_i2, ugly_i3, ugly_i5;
    ugly_i2 = ugly_numbers[i2] * 2;
    ugly_i3 = ugly_numbers[i3] * 3;
    ugly_i5 = ugly_numbers[i5] * 5;

    while (true)
    {
        ull next_ugly_number = min(min(ugly_i2, ugly_i3), ugly_i5);
        ugly_numbers.push_back(next_ugly_number);

        if (ugly_numbers.size() == n)
            break;

        if (next_ugly_number == ugly_i2)
        {
            i2++;
            ugly_i2 = ugly_numbers[i2] * 2;
        }

        if (next_ugly_number == ugly_i3)
        {
            i3++;
            ugly_i3 = ugly_numbers[i3] * 3;
        }

        if (next_ugly_number == ugly_i5)
        {
            i5++;
            ugly_i5 = ugly_numbers[i5] * 5;
        }
    }

    cout << ugly_numbers[n - 1] << endl;

    return 0;
}
