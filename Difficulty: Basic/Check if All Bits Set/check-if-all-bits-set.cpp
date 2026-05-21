class Solution {
  public:
    bool isBitSet(int n) {
         return (pow(2,(int)log2(n)+1)-1)==n;
        
    }
};