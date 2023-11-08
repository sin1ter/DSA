#include<bits/stdc++.h>
using namespace std;

int bruteforCe(vector<int>& arr, int n) {
    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int ans = 1;
            for(int k = i; k <= j; k++) {
                ans *= arr[k];
            }
            mx = max(ans, mx);
        }
    }
    return mx;
}

int bruteforceButBetter(vector<int>& arr, int n) {
    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        int ans = 1;
        for(int j = i + 1; j < n; j++) {
            ans *= arr[j];
        }
        mx = max(ans, mx);
    }
    return mx;
}

int opTimal(vector<int>& arr, int n) {
    int mx = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for(int i = 0; i < n; i++) {
        prefix *= arr[i];
        suffix *= arr[n - i - 1];
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        mx = max(mx, max(prefix, suffix));
    }
    
    return mx;
    // Time Complexity is O(N)
    // Space complexity is O(1)
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = opTimal(arr, n);
    cout << ans << "\n";
}