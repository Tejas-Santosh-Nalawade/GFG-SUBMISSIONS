class Solution {
  public:
vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int xorVal = 0;  

    for (int i = 0; i < n; i++) {
        xorVal ^= arr[i];
        xorVal ^= (i + 1); 
    }

    int setBitIndex = xorVal & ~(xorVal - 1);
    
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
     
        if (arr[i] & setBitIndex) { 
            x ^= arr[i]; 
        }  
        else { 
            y ^= arr[i]; 
        } 
     
        if ((i+1) & setBitIndex) { 
            x ^= (i + 1); 
        }
        else { 
            y ^= (i + 1); 
        }
    }

    int missing, repeating;
    
    int xCnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == x) {
            xCnt++;
        }
    }
    
    if (xCnt == 0) {
        missing = x;
        repeating = y;
    }
    else {
        missing = y;
        repeating = x;
    }
    
    return {repeating, missing};
}
};