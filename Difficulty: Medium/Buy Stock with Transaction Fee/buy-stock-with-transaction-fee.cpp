class Solution {
  public:
int maxProfit(vector<int> &arr, int k) {
    int n = arr.size();

    int noStock = 0, inHand = 0;

    for (int i = n - 1; i >= 0; i--) {
        int newNoStock = max(noStock, inHand - arr[i]);
        int newInHand = max(inHand, arr[i] - k + noStock);
        noStock = newNoStock;
        inHand = newInHand;
    }

    return noStock;
    }
};