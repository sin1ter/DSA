// Given an array of numbers, you need to return the count of reverse pairs. 
// Reverse Pairs are those pairs where i < j and arr[i] > 2 * arr[j]

#include<bits/stdc++.h>
using namespace std;

int reversePairs(vector<int>& arr, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i] > 2 * arr[j]) {
                count++;
            }
        }
    }
    return count;
    // Time complexity for this is O(n2)
    // Space complexity for this is O(1)
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid and right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int>& arr, int low, int mid, int high) {
    int right = mid + 1;
    int count = 0;
    for(int i = low; i <= mid; i++) {
        while(right <= high and arr[i] > 2 * arr[right]) {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int>& arr, int low, int high) {
    int count = 0;
    if(low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int count_reverse_pairs(vector<int>& arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = count_reverse_pairs(arr, n);
    cout << ans << '\n';
}