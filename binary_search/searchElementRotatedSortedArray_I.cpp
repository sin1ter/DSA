#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) return mid;
        if(arr[left] <= arr[mid]) {
            if(arr[left] <= x and x <= arr[mid]) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        else {
            if(arr[mid] <= x and x <= arr[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = search(arr, n, x);
    cout << ans << endl;
        return 0;
}