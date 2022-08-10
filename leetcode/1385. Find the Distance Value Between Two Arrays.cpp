// 1385. ���������ľ���ֵ
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//����
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        //��arr1���ҵ�����ֵ֮�����d�ĸ���
        for(int i = 0; i < arr1.size();i++){
            bool flag = true;
            for(auto &elem  : arr2) 
                if(abs(arr1[i] - elem) <= d)
                    flag = false;
            if(flag) ans++;
        }
        return ans;
    }
};
//����+���ֲ���+��ѧ
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        sort(arr1.begin(), arr1.end());
        int ans = 0;
        //��arr1���ҵ�����ֵ֮�����d�ĸ���
        for(int i = 0; i < arr1.size();i++){
            bool flag = true;
            int left= 0, right = arr2.size() - 1;
            while(left <= right){
                int mid = (left - right) / 2 + right;
                if(arr1[i] - arr2[mid] > d)
                    left = mid + 1;
                else if(arr2[mid] - arr1[i] > d)
                    right = mid - 1;
                else break;
            }
            if(left > right) ans++;//�Ѿ�ȫ������
        }
        return ans;
    }
};