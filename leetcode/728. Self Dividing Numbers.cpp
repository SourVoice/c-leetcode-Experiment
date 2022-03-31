//728. ×Ô³ýÊý
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        function<bool(int)>isSelfDividing = [](int n){
            int tmp = n;
            while(tmp)
            {
                int divided = tmp % 10;
                if(divided==0||n%divided){
                    return false;
                }
                tmp /= 10;
            }
            return true;
        };
        for (int i = left;i<=right;i++){
            if (isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};