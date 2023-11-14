#include<bits/stdc++.h>
using namespace std;

int rotated(vector<int>& arr, int n) {
    int index = -1;
    int ans = INT_MAX;
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[left] <= arr[right]) {
            if(arr[left] < ans) {
                index = left;
                ans = arr[left];
            }
            break;
        }
        if(arr[left] <= arr[mid]) {
            if(arr[left] < ans) {
                index = left;
                ans = arr[left];
            }
            left = mid + 1;
        }
        else {
            if(arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
            right = mid - 1;
        }
    }
    return index;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << rotated(arr, n) << '\n';
        return 0;
}