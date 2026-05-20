class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long>seen;
        for(int i=0;i<arr.size();i++)
        {
            long long num=arr[i];
            if(num==0)
            {
                if(target==0&&!seen.empty())
                
                {
                    return true;
                }
            }
            else{
                if(target%num==0)
                {
                    long long  required =target/num;
                    if(seen.find(required)!=seen.end())
                    {
                        return true;
                    }
                }
            }
            seen.insert(num);
            
        }
        return false;
    }
};
