//Given an integer array size of N and sorted in ascending order(may contain duplicate values) and a target value k.
//Now the array is rotated in some pivot point unknown to you . Return true if k is present and otherwise return false.
#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) return true;
        //Edge Case.
        if(arr[left] == arr[mid] and arr[mid] == arr[right]) {
            left = left + 1;
            right = right - 1;
            continue;
        }
        // if left part is sorted
        if(arr[left] <= arr[mid]) {
            //element exist.
            if(arr[left] <= x and x <= arr[mid]) {
                right = mid - 1;
            } 
            //element doesn't exist.
            else {
                left = mid + 1;
            }
        } 
        // if right part is sorted.
        else {
            //element exist.
            if(arr[mid] <= x and x <= arr[right]) {
                left = mid + 1;
            }
            //element doesn't exist.
            else {
                right = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(search(arr, n, k)) cout << "True\n";
    else cout << "False\n";
}