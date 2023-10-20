#include<bits/stdc++.h>
using namespace std;

void rotate_array(int arr[], int n, int k) {
    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void reverse(int arr[], int start, int end) {
    while (start < end){
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // rotate_array(arr, n, k); // time complexity for this is O(n) but space complexity is O(n) because of using extra array
    k %= n;
    reverse(arr, 0, n); // we can use the stl reverse function which is O(n) but why use inferior things when you can build superior things
    reverse(arr, 0, k);
    reverse(arr, k, n);

    /*so better solution will be reverse the array 
    then from the start and till k reverse the array
    and after that reverse the array from k to last element*/ 

    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}