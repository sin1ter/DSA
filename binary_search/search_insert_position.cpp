// Given a sorted array of distinct values and a target value x. Need to search for the index of the target value in the array.
// If found, return the index else determine the index where it would be inserted in the array while maintaining the sorted order.

#include<bits/stdc++.h>
using namespace std;

int search_position(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = search_position(arr, n, x);
    cout << result << "\n";
}