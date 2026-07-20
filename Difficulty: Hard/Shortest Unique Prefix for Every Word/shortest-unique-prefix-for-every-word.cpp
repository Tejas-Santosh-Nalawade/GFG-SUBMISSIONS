class Solution {
  public:
class Node {
private:
    vector<Node*> children;
    int freq;
    char ch;

public:
    Node(char x) {
        freq = 0;
        ch = x;
        children = vector<Node*>(26, nullptr);
    }

    void insert(string& word) {
        Node* curr = this;
        for(char c : word) {
            if(curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node(c);
            }
            curr = curr->children[c-'a'];
            curr->freq++;
        }
    }

    int findPrefix(string& word) {
        Node* curr = this;
        for(int i = 0; i < word.length(); i++) {
            curr = curr->children[word[i]-'a'];
            
            if(curr->freq == 1) {
                return i;
            }
        }
        return word.length() - 1;
    }
    
    void deleteTrie(Node* root) {
        if (root==nullptr) return;
        
        for (int i=0; i<26; i++) {
            deleteTrie(root->children[i]);
            delete root->children[i];
        }
    }
};

vector<string> findPrefixes(vector<string>& arr) {
    int n = arr.size();
    
    Node* root = new Node('*');
    
    for(int i=0; i<n; i++) {
        root->insert(arr[i]);
    }
    
    vector<string> result;
    
    for(int i=0; i<n; i++) {
        string word = arr[i];
        
        int endIndex = root->findPrefix(word);
        
        result.push_back(word.substr(0, endIndex + 1));
    }
    
    root->deleteTrie(root);
    
    return result;
}
};