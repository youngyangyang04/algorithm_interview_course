/* ************************************************************************
> File Name:     第四节面试题：两数之和&四数相加（map在哈希法中的应用，哈希法的经典问题）
> Author:        SunXiuyang
> Leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

// 两数之和 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                return {iter->second,i};
            }
            map.insert({nums, i});
        }
        return {};
    }
};

// 四数相加II
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap; //key:a+b的数值，value:a+b数值出现的次数
        for (int a : A) {
            for (int b : B) {
                if (umap.find(a + b) != umap.end()) {
                    umap[a + b]++;
                } else {
                    umap[a + b] = 1;
                }
            }
        }
        int count = 0;
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)]; 
                }
            }
        }
        return count;
    }
};

