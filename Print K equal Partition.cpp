class Solution {
public:
    // vector<vector<int>> res;
    bool found=true;
    bool finalr=false;
    void help(int idx,int k,vector<int> &nums,vector<vector<int>> &res,int sof,vector<int> &sub)
    {
        
        if(idx>=nums.size())
        {
            if(sof==k)
            {
                bool found=true;
                for(int j=0;j<sub.size()-1;j++)
                {
                    // cout<<sub[j]<<" ";
                    if(sub[j]!=sub[j+1])
                    {
                        found=false;
                        break;
                    }
                }
                cout<<endl;
                if(found)finalr=true;
                return;
            }
            return;
        }
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()>0)
            {
                sub[i]=sub[i]+nums[idx];
                res[i].push_back(nums[idx]);
                help(idx+1,k,nums,res,sof,sub);
                sub[i]=sub[i]-nums[idx];
                res[i].pop_back();
            }
            else
            {
                sub[i]=sub[i]+nums[idx];
                res[i].push_back(nums[idx]);
                help(idx+1,k,nums,res,sof+1,sub);
                sub[i]=sub[i]-nums[idx];
                res[i].pop_back();
                break;
            }
        }
        return;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        vector<vector<int>> res;
        for(int i=0;i<k;i++)
        {
            vector<int> temp;
            res.push_back(temp);
        }
        vector<int> sub(k,0);
        help(0,k,nums,res,0,sub);
        return finalr;
    }
};