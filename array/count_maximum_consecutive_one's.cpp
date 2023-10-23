#include<bits/stdc++.h>
using namespace std;

int count_one(int arr[], int n) {
    int count = 0;
    int mx = -1;
    for(int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
        }
        
        else {
            count = 0;
        }
        mx = max(mx, count);
    }
    return mx;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << count_one(arr, n);
}