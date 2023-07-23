/*************PROBLEM STATEMET********************
 * Given two integers n and m, the task is to find
 * the nth Fibonacci number modulo m. The Fibonacci
 * sequence is defined as follows:
 * F(0) = 0
 * F(1) = 1
 * F(i) = F(i-1) + F(i-2) for i ≥ 2
*************SAMPLE TEST CASE********************
 * Input: 10 3
 * Output: 1
 * Input: 9999999999999 2
 * Output: 0
 **************************************************/
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
#define NAIVE 0

long long Pisano(int m){
    int prev = 0, curr = 1, next;
    for(int i = 0; i <= m * m; i++){
        next = (prev + curr) % m;
        prev = curr;
        curr = next;
        if(prev ==0 && curr == 1){
            return i + 1;
        }
    }
}

#if(NAIVE)
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 2; ++i) {
        long long tmp_previous = previous % m;
        previous = current % m;
        current = (tmp_previous % m + current % m) % m;
        //cout << previous << " " << current << "\n";
    }

    return current % m;
}
#endif
 long long get_fibonacci_huge_fast(long long n, long long m){
    n = n % Pisano(m);
	if(n <= 1) return n;
    long prev = 0, curr = 1, next;
    for(int i = 0; i < n - 1; i++){
        next = (prev + curr) % m;
        prev = curr;
        curr = next;    
    }
    return next % m;
 }
signed main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_fast(n, m) << '\n';
#if(NAIVE)
    cout << get_fibonacci_huge_naive(n, m) << '\n';
#endif
    return 0;
}
