#include<bits/stdc++.h>
using namespace std;

vector<int> sorted(vector<int>& arr, vector<int>& brr, int n, int m) {
    vector<int> ans;
    int left = 0;
    int right = 0;
    while(left < n and right < m) {
        if(arr[left] <= brr[right]) {
            ans.push_back(arr[left]);
            left++; 
        }
        else if(arr[left] > brr[right]) {
            ans.push_back(brr[right]);
            right++;
        }
    }
    while(left < n) {
        ans.push_back(arr[left]);
        left++;
    }
    while(right < m) {
        ans.push_back(brr[right]);
        right++;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), brr(m);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> brr[i];
    }
    vector<int> ans = sorted(arr, brr, n, m);
    for(auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}