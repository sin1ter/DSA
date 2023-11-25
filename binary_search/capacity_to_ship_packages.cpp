// A conveyor belt has packages that must be shipped from one port to another within days.
// The i'th package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt(in the order given by weights).
// we may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days.

#include<bits/stdc++.h>
using namespace std;

int findDays(vector<int>& arr, int cap) {
    int n = arr.size();
    int days = 1; int load = 0;
    for(int i = 0; i < n; i++) {
        if(load + arr[i] > cap) {
            days++;
            load = arr[i];
        }
        else {
            load += arr[i];
        }
    }
    return days;
}
// for the brute force solution, we just have to iterate from the max element to the summation of the array
// and check whether it is possible or not by checking at each step using the findDays function.
int shipWithinDays(vector<int>& arr, int days) {
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int no_of_days = findDays(arr, mid);
        if(no_of_days <= days) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}


int main() {
    int n, days;
    cin >> n >> days;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = shipWithinDays(arr, days);
    cout << result << '\n';
} 