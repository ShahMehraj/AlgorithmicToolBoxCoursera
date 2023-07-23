/*************PROBLEM STATEMET********************
 * Given an integer n, the task is to find the last
 * digit of sum of squares of first n Fibonacci numbers.
 * The Fibonacci sequence is defined as follows:
 * F(0) = 0
 * F(1) = 1
 * F(i) = F(i-1) + F(i-2) for i ≥ 2
*************SAMPLE TEST CASE********************
 * Input: 7
 * Output: 3
 * This is because:
 * F_0^2 + F_1^2 + .. + F_7^2 = 273
 * 
 * Input: 73
 * Output: 1
 * This is because:
 * F_0 + F_1 ··· + F_73 = 1052478208141359608061842155201
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
        pisano_10.push_back(prev * prev);
        if(prev ==0 && curr == 1){
            return i + 1;
        }
    }
}

#if(NAIVE)
int fibonacci_sum_squares_naive(long long n){
    int sum = 0;
    int prev = 0, curr = 1, next;
    for(int i = 2; i <= n; i++){
        next = (prev + curr) % 10;
        prev = curr;
        curr = next;
        sum = (sum % 10 + (prev % 10) % 10 * (prev % 10) % 10) % 10;
    }
    return sum % 10;

}
#endif

int fibonacci_sum_squares_fast(long long n){
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

int main() {
    long long n = 0;
    cin >> n;
#if(NAIVE)
    cout << fibonacci_sum_squares_naive(n) << "\n";
#endif
    cout << fibonacci_sum_squares_fast(n) << "\n";
}
