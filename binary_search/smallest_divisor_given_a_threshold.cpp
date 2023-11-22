// Given an array of integers arr and an integer threshold/limit, we will choose a positive integer divisor, divide all the array by it, and sum the division's result.
// Find the smallest divisor such that the result mentioned above is less than or equal to threshold/limit
#include<bits/stdc++.h>
using namespace std;

int mx(vector<int>& arr) {
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

bool possible(vector<int>& arr, int div, int limit) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int cel = ceil((double)arr[i] / (double)div);
        sum += cel;
    }
    if(sum > limit) return false;
    else return true;
}

int smallest_divisor(vector<int>& arr, int n, int limit) {
    int low = 1;
    int high = mx(arr);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(arr, mid, limit)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = smallest_divisor(arr, n, limit);
    cout << result << '\n';
}

//Time Complexity is O(log(max(arr[])) * N) 
//Space complexity is O(1)