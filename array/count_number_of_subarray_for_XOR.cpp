#include<bits/stdc++.h>
using namespace std;

int count_subarray_brute_force(vector<int>& arr, int b, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = i; j < n; j++) {
            cur ^= arr[j];
            if(cur == b) {
                count++;
            }
        }
    }
    return count;
}

int count_subarray_Optimal(vector<int>& arr, int b, size_t n) {
    map<int, int> mpp;
    int count = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur ^= arr[i];
        if(cur == b) count++;
        int temp = cur ^ b;
        count += mpp[temp];
        mpp[cur]++;
    }
    return count;
}

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << count_subarray_Optimal(arr, b, n);
}