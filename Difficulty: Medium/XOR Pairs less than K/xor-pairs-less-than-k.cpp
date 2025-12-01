class Solution {
  public:
  
    class TrieNode
    {
        public : 
            TrieNode *child[2];
            int cnt;
            TrieNode(){
                child[0] = child[1] = NULL;
                cnt = 0;
            }
    };
        
        void insertTrie(TrieNode *root, int n){ 
            for(int i=31; i>=0; i--){
                bool x=(n) & (1 << i);
                if(!root->child[x]){
                    root->child[x] = new TrieNode();
                }
                root->child[x]->cnt+=1;
                root = root->child[x];
            }
        }
        
        int cntSmaller(TrieNode *root, int n, int k){
            int cntPairs = 0;
            for(int i=31; i>=0 && root; i--){
                bool x = n & (1<<i);
                bool y = k & (1<<i);
                if(y){
                    if(root->child[x]){
                        cntPairs +=root->child[x]->cnt;
                    }
                    root = root->child[1-x];
                }
                else{
                    root= root->child[x];
                }
            }
            return cntPairs;
        }
    int cntPairs(vector<int>& arr, int k) {
        TrieNode *root = new TrieNode();
        int cntPairs = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            cntPairs +=cntSmaller(root,arr[i],k);
            insertTrie(root, arr[i]);
        }
        return cntPairs;
    }
};