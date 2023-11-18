//Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number x when raised to the power N equals M. if the nth root is not an integer,return -1.

#include<bits/stdc++.h>
using namespace std;

// return 1 if == m
// return 0 if < m
// return 2 if > m
int func(int mid, int n, int m) {
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * mid;
    if (ans > m)
      return 2;
  }
  if(ans == m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int left = 1;
  int right = m;
  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(func(mid, n, m) == 1) return mid;
    else if(func(mid, n, m) == 0) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    int ans = NthRoot(n, m);
    cout << ans << '\n';
}