#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    cout << 3 << endl;
    cout << "L 2" << endl;
    cout << "R 2" << endl;
    cout << "R " << 2 * s.size() - 1 << endl;
    return 0;
}
