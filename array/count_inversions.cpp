// Givne an array of N integers, count the inversion of the arrray. 
// Inversion is for all i and j size of array, if i < j then you have to find pair (arr[i], arr[j]) such that arr[i] < arr[j]

#include<bits/stdc++.h>
using namespace std;

int inversions(vector<int>& arr, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j ++) {
            if(arr[j] < arr[i]) {
                count++;
            }
        }
    }
    return count;
    // Time complexity for this is O(n2).
    // Space complexity for this is O(1).
}

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid and right <= high) {
        if(arr[left] <= arr[right]) { 
            temp.push_back(arr[left]) 
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
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
        arr[i] = temp[i-low];
    }
    return count;
}

int mergesort(vector<int>& arr, int low, int high) {
    int count = 0;
    if(low >= high) return count;
    int mid = (low + high) / 2;
    count += mergesort(arr, low, mid);
    count += mergesort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int numberOfInversionsOptimal(vector<int>& arr, int n) {
    return mergesort(arr, 0, n - 1);
    //Time complexity is O(nlogn) 
    //Space complexity is O(n)
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = numberOfInversionsOptimal(arr, n);
    cout << ans << '\n';
        return 0;
}