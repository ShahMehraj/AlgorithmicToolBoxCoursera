#include <iostream>
using std::cin;
using std::cout;

#if(0)
int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
#endif

int get_fibonacci_last_digit_fast(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int next;

    for (int i = 2; i <= n; ++i) {
        next = (previous % 10 + current % 10) % 10;
        previous = current % 10;
        current = next % 10;
    }

    return next % 10;
}
int main() {
    int n;
    cin >> n;
    cout << get_fibonacci_last_digit_fast(n) << '\n';
}
