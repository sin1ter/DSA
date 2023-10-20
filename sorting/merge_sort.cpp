#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    //copying element from the left and right side
    while(left <= mid and right <= high) {
        if(arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    //copying remaining element from the array of the left side
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //copying remaining element from the array of the right side
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    //merge back to original array
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergesort(int arr[], int low, int high) {
    if(low == high) return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
        return 0;
}