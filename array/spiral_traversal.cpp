#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix, int n) {
    
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while(left <= right and top <= bottom) {
        for(int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom) {            
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    
    vector<int> result = spiralMatrix(arr, n);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
}