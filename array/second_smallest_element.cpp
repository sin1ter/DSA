#include<bits/stdc++.h>
using namespace std;

int second_smallest(int arr[], int n) {
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest and arr[i] < ssmallest) {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << second_smallest(arr, n);
}