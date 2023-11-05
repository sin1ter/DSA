#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr, int n) {
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> ans;
//     for(int i = 0; i < n; i++) {
//         int start = arr[i][0];
//         int end = arr[i][1];

//         if(!ans.empty() and end <= ans.back()[1]) {
//             continue;
//         }
//         for(int j = i + 1; j < n; j++) {
//             if(arr[j][0] < end) {
//                 end = max(end, arr[j][1]);
//             }
//             else {
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }

vector<vector<int>> mergeOverlappingIntervalsOptimal(vector<vector<int>>& arr, int n) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        arr.push_back({start, end});
    }

    vector<vector<int>> ans = mergeOverlmergeOverlappingIntervalsOptimalappingIntervals(arr, n);
    for(auto x: ans) {
        cout << "[" << x[0] << ", " << x[1] << "]" << endl;
    }
    cout << endl;
}