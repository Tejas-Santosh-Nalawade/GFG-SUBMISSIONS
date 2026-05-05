class Solution {
  public:
long sumXOR(vector<int>& arr)
{
    long sum = 0;
    for (int i = 0; i < 32; i++) 
    {

        int zc = 0, oc = 0; 
        
        for (int j = 0; j < arr.size(); j++)
        {
            if ((arr[j] >> i) & 1)
                    oc++;
                else
                    zc++;
        }
        
        sum += (long) oc * zc * (1 << i); 
    }
    return sum;
}

};