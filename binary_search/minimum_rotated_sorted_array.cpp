#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int n) {
    int left = 0;
    int right = n - 1;
    int ans = INT_MAX;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[left] <= arr[right]) { // if the arr[left] <= arr[mid] and arr[mid] <= arr[right] so the array is sorted so if the arr[left] <= arr[right] so we can say that arr[left] will be the minimum.
            ans = min(ans, arr[left]);
            break;
        }
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
    //Time Complexity is O(logn)
    //Space Complexity is O(1)
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