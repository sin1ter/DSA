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
    //when the array got negatives and zeros this is the optimal soluiton.
    map<long long, int> prefixSum;
    long long sum = 0;
    int maxlen = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i]; // calculating the prefix sum till index i
        if(sum == k) {
            maxlen = max(maxlen, i + 1); // if the sum = k update the maxlen
        }
        long long rem = sum - k; // calculating the sum of remainging part x - k
        if(prefixSum.find(rem) != prefixSum.end()) { // calculating the length and update maxlen
            int len = i -  prefixSum[rem];
            maxlen = max(maxlen, len);
        }
        if(prefixSum.find(sum) == prefixSum.end()) { //Finally, update the map chekcing the conditions
            prefixSum[sum] = i;
        }
    }
    return maxlen;
}

int longestSubarray2pointer(int arr[], int n, int k) {
    long long sum = arr[0];
    int left = 0, right = 0;
    int maxlen = 0;
    while(right < n) {
        while(left <= right and sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            maxlen = max(maxlen, right -left + 1);
        }
        right++;
        if(right < n) {
            sum += arr[right];
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
    // cout << longest_subarray(arr, n, k) << '\n'; // For this time complexity is O(n^2) and space complexity is O(1).
    // cout << longestSubarray(arr, n, k); // for this time complexity is O(n*logn) and space complexity for this is O(n).
    cout << longestSubarray2pointer(arr, n, k); // for this time complexity is O(2*n) and space complexity is O(1)
}