class Solution {
  public:
    string removeSpaces(string& s) {
        auto new_end = remove(s.begin(), s.end(), ' ');
        s.erase(new_end, s.end());
    
        return s; 
    }
};