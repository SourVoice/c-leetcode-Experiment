//806. 写字符串需要的行数
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int rowLength = 0;
        int row = 1;
        for(auto &ch : s){
            rowLength += widths[ch - 'a'];
            if(rowLength > 100){
                rowLength = widths[ch - 'a'];
                row++;
            }
        }
        vector<int> ans;
        ans.push_back(row);
        ans.push_back(rowLength);
        return ans;
    }
};