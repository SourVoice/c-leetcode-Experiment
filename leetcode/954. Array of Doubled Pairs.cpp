//954. 二倍数对数组
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<iostream>
using namespace std;

//map+sort,此处只能使用map,map使用红黑树,内部有序
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](int a, int b)
            { return a < b; });
        map<double, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(auto &[k,v] : mp){
           if(v<0) return false;
           if(v == 0) continue;
           if(k > 0){
               if(!mp.count(k*2)) return false;
               mp[k*2]-=v;
           } 
           else{
                if(!mp.count(k/2.0)) return false;
                mp[k/2.0]-=v; 
           }
        }
        return true;
    }
};

//哈希表 + 绝对值排序
class Solution2 {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        if(mp[0]&1)//0 can only match 0 so it's num can't be even
            return false;
        vector<int> v;
        v.reserve(mp.size());
        for(auto &[k,_]: mp){
            v.push_back(k);
        }
        sort(v.begin(),v.end(),[](int a, int b){ return abs(a) < abs(b); });   
        for(auto &e : v)
            cout<<e<<" ";
        for(auto &e: v){
            if(mp[e*2]< mp[e])
                return false;
            mp[e*2]-=mp[e];
        }
        return true;
    }
};