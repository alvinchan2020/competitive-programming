#include <iostream>
#include <string>
#include <algorithm>

#define NIL -1

using namespace std;

int fib(int);

int main()
{
    int N;
    cin >> N;

    cout << fib(N) << endl;

    return 0;
}

int fib(int n)
{
    int memory[n + 1];
    fill_n(memory, n + 1, NIL);

    memory[0] = 0;
    memory[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        memory[i] = memory[i - 1] + memory[i - 2];
    }

    return memory[n];
}