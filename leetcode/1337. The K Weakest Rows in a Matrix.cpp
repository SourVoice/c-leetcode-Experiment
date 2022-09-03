// 1337. 矩阵中战斗力最弱的 K 行
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;
        for (int i = 0; i < mat.size(); i++) {
            rows.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }
        sort(rows.begin(), rows.end(), [&](const pair<int, int>& a, const pair<int, int>&b){
            return a.first==b.first ? a.second < b.second: a.first < b.first;
        });
        vector<int> ans;
        for(int i  = 0; i < k; i++){
            ans.push_back(rows[i].second);
        }
        return ans;
    }
};
// 简洁版, see std::lexicographical_compare
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> rows;
        int n = mat[0].size();
        for(int i = 0; i < m; i++) rows.push_back(i);
        sort(rows.begin(), rows.end(),[&](const int& a, const int& b){ return mat[a] == mat[b]? a < b: mat[a] < mat[b];});// vector的< >由std::lexicographical_compare实现
        return vector<int>(rows.begin(), rows.begin() + k);
    }
};