#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& arr, int pages) { 
    int n = arr.size();
    int student = 1, pagesStudent = 0;
    for(int i = 0; i < n; i++) {
        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int brute(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for(int i = low; i <= high; i++) {
        int countStudent = countStudents(arr, i);
        if(countStudent == m) return i;
    }
    return low;
    //time complexity is O(sum(arr) - max(arr) + 1)
    //space complexity is O(1)
}

int binarySearch_book(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(countStudents(arr, mid) > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
    // Time complexity O(n*log(sum(arr)-max(arr)) + 1)
    // Space complexity O(1)
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int ans = brute(arr, n, m);
    int ans = binarySearch_book(arr, n, m);
    cout << ans << '\n';

        return 0;
}   
