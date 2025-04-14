//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
// Depth-first search function for topological sorting and cycle detection
bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis, 
                                    vector<int> &rec, string &ans) {
    
    // Mark the node as visited and part of the current recursion stack
    vis[u] = rec[u] = 1;  

    for (int v = 0; v < 26; v++) {
        if (graph[u][v]) {  
            if (!vis[v]) {  
                // Recurse and check for cycle
                if (!dfs(v, graph, vis, rec, ans))  
                    return false;
            } else if (rec[v]) {
                 // A cycle is detected if v is already in the current recursion stack
                return false; 
            }
        }
    }
    // Add the character to the result after visiting all dependencies
    ans.push_back(char('a' + u));
    // Remove from recursion stack
    rec[u] = 0;  
    return true;
}

// Function to find the correct order of characters in an alien dictionary
string findOrder(vector<string> &words) {
    
    // Adjacency matrix for character precedence
    vector<vector<int>> graph(26, vector<int>(26, 0));
    // Marks if a character exists in the dictionary
    vector<int> exist(26, 0);  
    // Marks if a character has been visited
    vector<int> vis(26, 0);   
    // Recursion stack to detect cycles
    vector<int> rec(26, 0);   
    // Resultant character order
    string ans = "";          

    // Step 1: Mark all characters that appear in the input
    for (string word : words) {
        for (char ch : word) {
            exist[ch - 'a'] = 1;
        }
    }

    //Build the graph 
    for (int i = 0; i + 1 < words.size(); i++) {
        const string &a = words[i], &b = words[i + 1];
        int n = a.size(), m = b.size(), ind = 0;

        // Find the first different character between a and b
        while (ind < n && ind < m && a[ind] == b[ind])
            ind++;

        if (ind != n && ind == m)
            return "";

        
        if (ind < n && ind < m)
            graph[a[ind] - 'a'][b[ind] - 'a'] = 1;
    }

    
    for (int i = 0; i < 26; i++) {
        if (exist[i] && !vis[i]) {
            if (!dfs(i, graph, vis, rec, ans)) {
                // Return empty string if a cycle is found
                return "";  
            }
        }
    }
    // Reverse to get the correct topological order
    reverse(ans.begin(), ans.end());  
    return ans;
}
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends