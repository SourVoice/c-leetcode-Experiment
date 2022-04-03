//744. Find Smallest Letter Greater Than Target
#include <iostream>
#include <vector>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        function <void(vector<char>&)> removeDuplicates = [](vector<char>& v) {
            auto end = v.end();
            for (auto it = v.begin(); it != end;  it++){
                end = remove(it + 1, end, *it);
            }
            v.erase(end, v.end());
        };
        removeDuplicates(letters);
        int n = letters.size();
        int left = 0, right = n -1;
        int mid = 0;
        while(left<=right){
            mid = (left+right)/2;
            if(letters[mid]<target)
                left = mid+1;
            else if(letters[mid]>target)
                right = mid-1;
            if(letters[mid] == target)
                return mid!=n -1 ? letters[mid+1] : letters[0];
        }
        cout<<left;
        return left>=n? letters[0]: letters[left];
   }
};