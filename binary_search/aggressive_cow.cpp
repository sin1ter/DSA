#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &arr, int dist, int cows) {
    int n = arr.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = arr[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= dist) {
            cntCows++; //place next cow.
            last = arr[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int brute_aggressive_cows(vector<int>& arr, int n, int cows) {
    sort(arr.begin(), arr.end());
    int limit = arr[n - 1] - arr[0];
    for(int i = 1; i <= limit; i++) {
        if(canWePlace(arr, i, cows) == false) {
            return (i - 1);
        }
    }
    return limit;
}

int aggressiveCows(vector<int> &arr, int k) {
    int n = arr.size(); //size of array
    //sort the arr[]:
    sort(arr.begin(), arr.end());

    int low = 1, high = arr[n - 1] - arr[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(arr, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}


int main() {
    int n, cows;
    cin >> n >> cows;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    // int ans = brute_aggressive_cows(arr, n, cows);
    int ans = aggressiveCows(arr, cows);
    cout << ans << endl;

        return 0;
}