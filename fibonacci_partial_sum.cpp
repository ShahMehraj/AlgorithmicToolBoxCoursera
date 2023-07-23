/*************PROBLEM STATEMET********************
 * Given two integer m and n, the task is to find
 * the last digit of the sum of all Fibonacci numbers
 * from F_m to F_n (both inclusive). The Fibonacci
 * sequence is defined as follows:
 * F(0) = 0
 * F(1) = 1
 * F(i) = F(i-1) + F(i-2) for i ≥ 2
*************SAMPLE TEST CASE********************
 * Input: 3 7
 * Output: 1
 * This is because:
 * F_3 + F_1 + ... + F_2 + F_7 = 31
 * 
 * Input: 10 10
 * Output: 5
 * This is because: F_10 = 55.
 **************************************************/
#include <iostream>
#include <vector>
#include <numeric>

#define NAIVE false

using std::cin;
using std::cout;

std::vector<int> pisano_10;

short Pisano(short m){
    int prev = 0, curr = 1, next;
    for(int i = 0; i <= m * m; i++){
        next = (prev + curr) % m;
        prev = curr;
        curr = next;
        pisano_10.push_back(prev);
        if(prev ==0 && curr == 1){
            return i + 1;
        }
    }
}
#if(NAVIE)
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
#endif
int last_digit_fibonacci_sum_fast(long long n){
    short period = Pisano(10);
    long q = n / period;
    long r = n % period;
    long sum = 0;
    if(q >= 1){
        sum = std::accumulate(pisano_10.begin(), pisano_10.end(), 0);
        sum = (sum % 10 * q % 10) % 10;
    }
    for(int i = 0; i < r; i++){
        sum = (sum % 10 + pisano_10[i] % 10) % 10;
    }
    return sum % 10;
}
long long get_fibonacci_partial_sum_fast(long long m, long long n){
    long sum_n = last_digit_fibonacci_sum_fast(n);
    long sum_m = last_digit_fibonacci_sum_fast(m - 1);
    short ans = (sum_n % 10 - sum_m % 10) % 10;
    if(ans < 0) ans += 10;
    return ans;
}

int main() {
    long long from, to;
    cin >> from >> to;
#if(NAVIE)
    cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
#endif
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
