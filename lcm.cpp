#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
#define int long long 

#if(0)
int lcm_naive(int a, int b) {
  for (int l = 1; l <= a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (int) a * b;
}
#endif

int lcm_fast(int a, int b){
  return (a * b) / std::__gcd(a, b);
}

signed main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << '\n';
  return 0;
}
