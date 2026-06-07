#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        vector<int>res;
        vector<int>dralunetic=nums;

        while(!nums.empty()){
            int bestMex=0;
            int bestK=1;
            
            unordered_set<int>s;
            int mex=0;

            for(int k=1;k<=(int)nums.size();k++){
                s.insert(nums[k-1]);
                
                while(s.count(mex))
                    mex++;
                
                if (mex>bestMex){
                    bestMex=mex;
                    bestK=k;
                }
            }
            res.push_back(bestMex);
            nums.erase(nums.begin(),nums.begin()+bestK);
        }
        return res;
    }
};