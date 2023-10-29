#include<bits/stdc++.h>
using namespace std;

vector<int> next_permutation(vector<int>& arr, int n) {
    // for this time complexity is O(3*n)(for the two loops and the reverse function) and space complexity is O(1)
    int index = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for(int i = n - 1; i > index; i++) {
        if(arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans = next_permutation(arr, n);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}