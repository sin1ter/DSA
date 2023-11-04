#include<bits/stdc++.h>
using namespace std;

int longest_length(vector<int>& arr, int n) {
    map<int, int> mpp;
    int longestLen = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0) longestLen = i + 1;
        else if(mpp.find(sum) != mpp.end()) {
            longestLen = max(longestLen, i - mpp[sum]);
        }
        else {
            mpp[sum] = i;
        }
    }
    return longestLen;
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
    cout << longest_length(arr, n) << '\n';
}  