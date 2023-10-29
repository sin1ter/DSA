#include<bits/stdc++.h>
using namespace std;

vector<int> rearrageArrayElements(vector<int>& arr, int n) {
    // time complexity for this is O(n + n / 2) and space complexity is O(n/2 + n/2).
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            neg.push_back(arr[i]);
        }
        else if(arr[i] > 0) {
            pos.push_back(arr[i]);
        }
    }
    for(int i = 0; i < n / 2; i++) {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
    return arr;
}

vector<int> rearrageArrayElementsOptimal(vector<int>& arr, int n) {
    // time complexity for this is O(n) and space complexity is O(n).
    int posIndex = 0;
    int negIndex = 1;
    vector<int> newarr(n);
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            newarr[posIndex] = arr[i];
            posIndex += 2;
        }
        else if(arr[i] < 0) {
            newarr[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return newarr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans = rearrageArrayElements(arr, n);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}