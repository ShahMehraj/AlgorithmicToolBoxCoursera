/*************PROBLEM STATEMET********************
 * Given an integer n, the task is to find
 * the last digit of the sum of first n Fibonacci number.
 * The Fibonacci sequence is defined as follows:
 * F(0) = 0
 * F(1) = 1
 * F(i) = F(i-1) + F(i-2) for i ≥ 2
*************SAMPLE TEST CASE********************
 * Input: 3
 * Output: 4
 * This is because:
 * F_0 + F_1 + F_2 + F_3 = 0 + 1 + 1 + 2 = 4
 * 
 * Input: 100
 * Output: 5
 * This is because:
 * F_0 + F_1 ··· + F_100 = 927372692193078999175.
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

#if(NAIVE)
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
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

int main(){
    long long n = 0;
    cin >> n;
    cout << last_digit_fibonacci_sum_fast(n) << "\n";
#if(NAIVE)
    cout << fibonacci_sum_naive(n) << "\n";
#endif
    return 0;
}
