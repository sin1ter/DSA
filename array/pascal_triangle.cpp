#include<bits/stdc++.h>
using namespace std;

int NcR(int row, int col) {
    // Given row number r and column number c. Print the element at position(r, c) in Pascal's Triangle.
    row--; col--;
    long long res = 1;
    for(int i = 0; i < col; i++) {
        res *= (row - i);
        res /= (i + 1);
    }
    return res;
}

void printrow(int row) {
    // Given the row number r. Print all the row's element.
    long long ans = 1;
    cout << ans << " ";
    for(int i = 1; i < row; i++) {
        ans *= (row - i);
        ans /= i;
        cout << ans << ' ';
    } 
}

vector<int> generateRow(int row) {
    // Generating row for the triangle
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int i = 1; i < row; i++) {
        ans *= (row - i);
        ans /= i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int row) {
    vector<vector<int>> ans;
    for(int i = 1; i <= row; i++) {
        ans.push_back(generateRow(i));
    }
    return ans;
    // Time complexity is O(n2) and space complexity is O(1).
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> result =  pascalTriangle(n);
    for(auto row : result){
        for(auto num: row){
            cout << num << ' ';
        }
        cout << endl;
    }
        return 0;
}
