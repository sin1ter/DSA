#include<bits/stdc++.h>
using namespace std;

int second_largest1(int arr[], int n) {
    sort(arr, arr + n);
    int largest = arr[n - 1];
    int s_largest = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] != largest) {
            s_largest = arr[i];
            break;
        }
    }
    return s_largest;
}

int second_largest2(int arr[], int n) {
    int largest = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    int slargest = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > slargest and arr[i] != largest) {
            slargest = arr[i];
        }
    }
    return slargest;
}

int second_largest3(int arr[], int n) {
    int largest = arr[0];
    int slargest = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest and arr[i] > slargest) {
            slargest = arr[i];
        }
    }
    return slargest;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // cout << second_largest1(arr, n); // For this time complexity O(N * log(N) + N) (sorting n * log(n) and for the forloop n) and space complexity O(N)
    // cout << second_largest2(arr, n); // For this time complexity O(2 * N) and space complexity is O(1)
    cout << second_largest3(arr, n); // For this time complexity O(N) and space complexity O(1)
   

}