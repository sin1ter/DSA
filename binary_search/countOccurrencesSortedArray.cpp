#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) {
            ans = mid;
            right = mid - 1;
        }
        else if(arr[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) {
            ans = mid;
            left = mid + 1;
        }
        else if(arr[mid] > mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
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
    if(lastOcc(arr, n, x) == -1) {
        cout << 0 << '\n';
    }
    else {
        int ans = lastOcc(arr, n, x) - firstOcc(arr, n, x) + 1;
        cout << ans << '\n';
    }
        return 0;
}