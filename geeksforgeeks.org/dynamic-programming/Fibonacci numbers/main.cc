#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define NIL -1

int fib(int, int *);

int main()
{
    int N;
    cin >> N;

    int memory[N + 1] = {};
    fill_n(memory, N + 1, -1);

    cout << fib(N, memory) << endl;

    return 0;
}

int fib(int n, int *memory)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (memory[n] != NIL)
        return memory[n];
    else
    {
        int result = fib(n - 1, memory) + fib(n - 2, memory);
        memory[n] = result;
        return result;
    }
}
