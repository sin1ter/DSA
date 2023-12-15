#include<bits/stdc++.h>
using namespace std;

int partitions(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 1;
    int sub = 0;
    for(int i = 0; i < n; i++) {
        if(sub + arr[i] <= k) {
            sub += arr[i];
        }
        else {
            count++;
            sub = arr[i];
        }
    }
    return count;
}

int binarySearchPaintersPartitions(vector<int>& arr, int n, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(partitions(arr, mid) > k) {
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

    int ans = binarySearchPaintersPartitions(arr, n, k);
    cout << ans << '\n';
}

// Time complexity is O(log(sum(arr[]) -  max(arr[]) + 1))
// Space complexity is O(1)                     