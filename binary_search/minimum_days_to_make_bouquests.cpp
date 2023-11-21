#include<bits/stdc++.h>
using namespace std;


// brute force 
// Time complexity is O((max(arr[]) - min(arr[]) + 1) * N)) where max(arr[]) > maximum element of the array and min(arr[]) minimum element of the array
// Space complexity is O(1)
bool possible(vector<int>& bloomDay, int day, int m, int k) {
    int count = 0;
    int n = bloomDay.size();
    int no_of_bouquets = 0;
    for(int i = 0; i < n; i++) {
        if(bloomDay[i] <= day) {
            count++;
        }
        else {
            no_of_bouquets += count / k;
            count = 0;
        }
    }
    no_of_bouquets += count / k;
    if(no_of_bouquets >= m) return true;
    else return false;
}

int minimum_day(vector<int>& arr, int m, int k) {
    int n = arr.size();
    long long val = m * 1LL * k * 1LL;
    if(val > n) return -1;

    int mini = INT_MAX, maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        mini = min(arr[i], mini);
        maxi = max(maxi, arr[i]);
    }

    for(int i = mini; i <= maxi; i++) {
        if(possible(arr, i, m, k)) return i;
    }
    return -1;
}
// brute force solution ended.

// optimized solution
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long val = m * 1LL * k * 1LL;
    if(val > n) return -1;

    int mini = INT_MAX, maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    int low = mini, high = maxi;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(bloomDay, mid, m, k)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    // Time complexity is O(N*log(max - min + 1))
    // Space complexity is O(1)
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = minimum_day(arr, m, k);
    int result1 = minDays(arr, m, k);
    cout << result1 << '\n';
}