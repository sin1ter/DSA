#include<bits/stdc++.h>
using namespace std;

// int longest_subarray(int arr[], int n, int k) {
//     int len = 0;
//     int sum = 0;
//     for(int i = 0; i < n; i++) {
//         sum = 0;
//         for(int j = i; j < n; j++) {
//             sum += arr[j];
//             if(sum == k) {
//                 len = max(len, j - i + 1);
//             }
//         }

//     }
//     return len;
// }

int longestSubarray(int arr[], int n, int k) {
    int maxlen = 0;
    int sum = 0;
    map<int, int> presumMap;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == k) {
            maxlen = max(maxlen, i + 1);
        }
        int rem = sum - k;
        if(presumMap.find(rem) != presumMap.end()) {
            int len = i - presumMap[rem];
            maxlen = max(maxlen, len);
        }
        if(presumMap.find(sum) == presumMap.end()) {
            presumMap[sum] = i;
        }
    }
    return maxlen;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // cout << longest_subarray(arr, n, k) << '\n'; // For this time complexity is O(n^2) and space complexity is O(1)
    cout << longestSubarray(arr, n, k);
}