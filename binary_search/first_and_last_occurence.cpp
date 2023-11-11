#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n -1 ;
    int ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
    //for the firstOccurence used the lower bound concept because lower bound find the smallest index of greater or equal to the target. 
    // if the lowerbound point to the last or doesn't exist the lower bound and upperbound doesn't exist.
}

int lastOccurence(vector<int>& arr, int n, int x) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] > x) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;

    // for the lastOccurence used the upper bound concept because upper bound find the smallest index of which is greater than the target.
    // upper bound point to the index which is greater than the target so if we do one decrement we will find the last occurence of the target
    // fascinating isn't it?
}   

// without lower bound and upper bound 
int firstOcc(vector<int>& nums, int n, int target) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            ans = mid;
            right = mid - 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& nums, int n, int target) {
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            ans = mid;
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lb = firstOcc(arr, n, x);
    int ub = lastOcc(arr, n, x);
    /*
    for lower bound and upper bound
    if(lb == n or arr[lb] != x) lb = -1, ub = -1; // for this time complexity is O(2*logn) and space complexity is O(n).
    else {
        cout << lb << " " << ub - 1 << '\n';
    }
    */
   if(lb == -1) cout << -1 << " " << -1 << '\n'; // because if the first occurence is not there there will not be last occurence.
   else {
    cout << lb << ' ' << ub << '\n';
   }
        return 0;
}