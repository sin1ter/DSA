#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& arr, int n, int target) {
    int left = 0;
    int right = n - 1;
    int ans = n; 
    while(left <= right) {
        int mid = (right + left)/2;
        if(arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = lower_bound(arr, n, target);
    cout << result << '\n';
}