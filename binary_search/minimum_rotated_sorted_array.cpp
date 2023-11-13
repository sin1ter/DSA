#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int n) {
    int ans = INT_MAX;
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[left] <= arr[mid]) {
            ans = min(ans, arr[left]);
            left = mid + 1;
        }
        else {
            ans = min(ans, arr[mid]);
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = findMin(arr, n);
    cout << result << '\n';
}