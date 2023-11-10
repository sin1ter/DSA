// Given an sorted array of n integers and an integer x. Find the floor and ceiling of x in arr[0...1]
// The floor of x is largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array which is greater than or equal to x.
#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = n;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= x) {
            ans = arr[mid];
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int findFloor(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= x) {
            ans = arr[mid];
            left = mid + 1;
        }
        else {
            right = mid - 1;
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
    int cans = findCeil(arr, n, x);
    int fans = findFloor(arr, n, x);
    cout << cans << " " << fans << '\n';
        return 0;
}