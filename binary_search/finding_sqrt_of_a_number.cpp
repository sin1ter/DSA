// Given a positive integere n. Task is to find and return its square root. If 'n' is not a perfect sqaure, then return the floor value of sqrt(n).
#include<bits/stdc++.h>
using namespace std;

int find(int n) {
    int sq = sqrt(n);
    return sq;
}

int find_binarySearch(int n) {
    int low = 1;
    int high = n;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if(val <= (long long) n) low = mid + 1;
        else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    int n;
    cin >> n;
    cout << find_binarySearch(n) << endl;
}
