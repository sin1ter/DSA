#include <bits/stdc++.h>
using namespace std;

// int single_number(int arr[], int n) {
//     int mp[n + 1] = {0};
//     for(int i = 0; i < n; i++) {
//         mp[arr[i]]++;
//     }
//     int ans = 0;
//     for(int i = 0; i < n; i++) {
//         if (mp[arr[i]] == 1) {
//             ans = arr[i];
//             break;
//         }
//     }
//     return ans;
// }

int single_number_xor(int arr[], int n) {
    int xor1 = 0;
    for(int i = 0; i < n; i++) {
        xor1 ^= arr[i];
    }
    return xor1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // cout <<  single_number(arr, n); //The time complexity for this is O(n*logm) where m is the size of the map and space complexity is O(m) we can use also the map data structur
    cout << single_number_xor(arr, n);
}