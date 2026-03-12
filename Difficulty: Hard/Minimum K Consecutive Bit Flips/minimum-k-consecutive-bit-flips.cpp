class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
    int n = arr.size(); 
    int res = 0, flag = 0;
    queue<int> q; 

    for (int i = 0; i < n; i++) {
        
        if(i >= k) {
            flag ^= q.front();
            q.pop();
        }
        
        if(flag == 1)
            arr[i] ^= 1;
        
        if(arr[i] == 0) {
            
            if(i + k > n) 
                return -1;
            
            res += 1;
            
            flag ^= 1;
            
            q.push(1);
        }
        else {
            
            q.push(0);
        }
    }

    return res; 
}
};