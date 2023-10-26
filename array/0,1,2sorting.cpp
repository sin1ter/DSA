#include<bits/stdc++.h>
using namespace std;

void dnf(int arr[], int n) {
    int left = 0, mid = 0, high = n - 1;
    while(mid <= high and left <= high) {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[left]);
            left++, mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dnf(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}