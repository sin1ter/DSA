// Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if ‘arr[i]’ is the peak element, ‘arr[i – 1]’ < ‘arr[i]’ and ‘arr[i + 1]’ < ‘arr[i]’. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int>& arr, int n) {
    if(n == 1) return 0;
    if(arr[0] > arr[1]) {
        return 0;
    }
    if(arr[n - 1] > arr[n - 2]) {
        return n - 1;
    }
    int left = 1; // as always handleing the 0th index manually so left = 1
    int right = n - 2; // as always handleing the n - 1 index so right = n - 1
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]) return mid;
        if(arr[mid - 1] < arr[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;              
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << peakElement(arr, n) << endl;
}