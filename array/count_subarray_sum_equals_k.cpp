#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int k) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if(sum == k) count++;
        }
    }
    return count;
}

int count2(int arr[], int n, int k) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == k) count++;
        }
    }
    return count;
}

int count3Optimal(int arr[], int n, int k) {
    map<int, int> mpp;
    int prefixSum = 0, count = 0;
    mpp[0] = 1; // setting 0 in the map
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i]; // adding element to the prefix sum
        int remove = prefixSum - k; // calculating x - k
        count += mpp[remove]; // adding the number of subarrays to be removed
        mpp[prefixSum] += 1; // update the count of prefix sum in the map
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << count3Optimal(arr, n, k) << '\n';
}