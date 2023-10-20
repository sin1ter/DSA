#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> temp;
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(arr[count] != arr[i]) {
            count++;
            arr[count] = arr[i];
        }
    }
    cout << count + 1 << "\n";
    for(int i = 0; i < count + 1; i++) {
        cout << arr[i] << ' ';
    }

}