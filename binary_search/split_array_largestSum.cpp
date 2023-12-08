#include<bits/stdc++.h>
using namespace std;
int countPartitions(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 1;
    int ss = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] + ss <= k) {
            ss += arr[i];
        }
        else {
            count++;
            ss = arr[i];
        }
    }
    return count;
}

int brute(vector<int>& arr, int n, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for(int i = low; i < high; i++) {
        if(countPartitions(arr, i) == k) {
            return i;
        }
    }
    return low;
}

int binarySearch(vector<int>& arr, int n, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(countPartitions(arr, mid) > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
     
    // int ans = brute(arr, n, k);
    int ans = binarySearch(arr, n, k);
    cout << ans << '\n';
}

//feel proud you did that by yourself. from previous experience...
//some of the code I wrote even I don't know what the hell is going on
// but I made it. :)