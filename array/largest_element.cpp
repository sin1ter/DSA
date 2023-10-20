#include<bits/stdc++.h>
using namespace std;

int largest_element(int arr[], int n) {
    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // sort(arr, arr + n); // for this time complexity is O(N*log(N)) and space complexity is O(N)
    // cout << "largest element in the arrry: " << arr[n - 1] << '\n';
    cout << "Largest element in the array: " << largest_element(arr, n) << '\n'; // for this time complexity is O(N) and space complexity is O(1)
}