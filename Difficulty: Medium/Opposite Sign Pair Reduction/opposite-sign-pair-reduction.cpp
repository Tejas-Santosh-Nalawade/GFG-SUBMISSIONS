class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int>s;
        
        for(int element:arr){
            while(!s.empty() && s.back() * element < 0){
                int top = s.back();
                
                if(abs(top) > abs(element)){
                    element = top;
                    s.pop_back();
                    
                }
                else if (abs(top) < abs(element)){
                    s.pop_back();
                }
                else{
                    s.pop_back();
                    element = 0;
                    break;
                }
            }
            if(element !=0){
                s.push_back(element);
            }
        }
        return s;
    }
};