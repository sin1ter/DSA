#include<bits/stdc++.h>
using namespace std;

int kth_brute(vector<int> arr, int n, int k) {
    for(int i = 0; i < n; i++) {
        if(arr[i] <= k) {
            k++;
        }
        else break;
    }
    return k;
}
// time complexity for this is O(n)
// space complexity is O(1)

int kth_missing_number(vector<int> arr, int n, int k) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    // return low + k; both works.
    return high + 1 + k; 
}
// time complexity is O(logn)
// space complexity is O(1)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // cout << kth_brute(arr, n, k) << endl;
    cout << kth_missing_number(arr, n, k) << endl;
        return 0;
}