#include<bits/stdc++.h>
using namespace std;

void move_zeroes(int arr[], int n) {
    int j = -1;
    for(int i = 0; i < n; i++) { // if the 0 in the xth place time complexity for this is O(x)
        if(arr[i] == 0) {
            j = i;
            break; 
        }
    }
    for(int i = j + 1; i < n; i++) { // and for this time complexity will be O(n - x)
        if(arr[i] != 0) {
            swap(arr[j], arr[i]);
            j++;
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
    move_zeroes(arr, n); // so overall complexity is O(x + n - x) = O(n) and space complexity O(1)
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}