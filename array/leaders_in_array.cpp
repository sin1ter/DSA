#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr, int n) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        bool leaders = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                leaders = false;
                break;
            }
        }
        if(leaders) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> leadersOptimal(vector<int>& arr, int n) {
    vector<int> res;
    int max = arr[n - 1];
    res.push_back(arr[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] > max) {
            res.push_back(arr[i]);
            max = arr[i];
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans = leaders(arr, n);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}