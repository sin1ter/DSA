#include<bits/stdc++.h>
using namespace std;

vector<int> sorted(vector<int>& arr, vector<int>& brr, int n, int m) {
    //brute force
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

void sorted_better(vector<int>& arr, vector<int>& brr, int n, int m) {
    //Time complexity is O(n + m) + O(n logn) + O(m logm) and space complexity is O(1)
    int i = n - 1;
    int j = 0;
    while(i >= 0 and j < m) {
        if(arr[i] > brr[j]) {
            swap(arr[i], brr[j]);
            i--; j++;
        }
        else {
            break;
        }
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
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
    sorted_better(arr, brr, n, m);
    for(auto x: arr) {
        cout << x << ' ';
    }
    for(auto x: brr) {
        cout << x << ' ';
    }
    cout << '\n';
}