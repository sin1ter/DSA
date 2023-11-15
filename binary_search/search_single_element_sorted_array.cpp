#include<bits/stdc++.h>
using namespace std;

int search_using_XOR(vector<int>& arr, int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans ^= arr[i];
    }
    return ans;
}

int search_using_binarySearch(vector<int>& arr, int n) {
    if(n == 1) return arr[0];
    if(arr[0]!= arr[1])  return arr[0];
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1]) return arr[mid];
        if(mid % 2 == 1 and arr[mid] == arr[mid - 1]  or mid % 2 == 0 and arr[mid] == arr[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // cout << search_using_XOR(arr, n) << '\n';
    cout << search_using_binarySearch(arr, n) << '\n';
}