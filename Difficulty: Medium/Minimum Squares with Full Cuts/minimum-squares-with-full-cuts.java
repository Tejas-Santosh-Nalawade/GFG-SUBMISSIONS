class Solution {
    public int minSquares(int n, int m) {
        // code here
        int min = Math.min(n,m);
                int max = Math.max(n,m);
                if(min == 0) return 0;
                return (max/min) + minSquares(min,max%min);
            }
}