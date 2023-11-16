// Given a positive integere n. Task is to find and return its square root. If 'n' is not a perfect sqaure, then return the floor value of sqrt(n).
#include<bits/stdc++.h>
using namespace std;

int find(int n) {
    int sq = sqrt(n);
    return sq;
}

int find_binarySearch(int n) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(mid * mid <= n) left = mid + 1;
        else {
            right = mid - 1;
        }
    }
    return right; // dummy return statemetn.
}

int main() {
    int n;
    cin >> n;
    cout << find_binarySearch(n) << endl;
}
