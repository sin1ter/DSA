#include<bits/stdc++.h>
using namespace std;

int search_using_XOR(vector<int>& arr, int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans ^= arr[i];
    }
    return ans;
}

int search_using_binarySearch(vector<int>& arr, int n) {
    if(n == 1) return arr[0];
    if(arr[0]!= arr[1])  return arr[0];
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];
    int left = 1; // not taking left = 0 cause checking the first elment manually.
    int right = n - 2; // as for the last element chekcing the last element manually so right = n - 2
    while(left <= right) {
        int mid = left + (right - left) / 2;
        //if arr[mid] is the single element.
        if(arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1]) return arr[mid];

        //Now in the left.
        if(mid % 2 == 1 and arr[mid] == arr[mid - 1]  or mid % 2 == 0 and arr[mid] == arr[mid + 1]) {
            // element the left half.
            left = mid + 1;
        }
        //Now in the right
        else {
            // element the right half.
            right = mid - 1;
        }
    }
    // as always remember to return dummy statemen
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // cout << search_using_XOR(arr, n) << '\n';
    cout << search_using_binarySearch(arr, n) << '\n';
}