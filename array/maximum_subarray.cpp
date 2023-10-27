#include<bits/stdc++.h>
using namespace std;

int maximum_subarray(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        int currentSum = 0;
        for(int j = i; j < n; j++) {
            currentSum += arr[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

void kadanes_algo(int arr[], int n, int& maximum, int& ansStart, int& ansEnd) {
    maximum = INT_MIN;
    int current_sum = 0;
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(current_sum == 0) start = i;
        current_sum += arr[i];
        if(current_sum > maximum) {
            maximum = current_sum;
            ansStart = start, ansEnd = i;
        }
        if(current_sum < 0) current_sum = 0;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maximum, ansStart, ansEnd;
    kadanes_algo(arr, n, maximum, ansStart, ansEnd);
    cout << maximum << '\n';
    if(ansStart <= ansEnd) {
        for(int i = ansStart; i <= ansEnd; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        cout << "NO subarray found";
    }
}