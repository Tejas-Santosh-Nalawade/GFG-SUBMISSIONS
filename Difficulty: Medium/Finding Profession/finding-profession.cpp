class Solution {
  public:
    string profession(int level, int pos) {
           string s;
        int a = pos-1 ;
        s.push_back('D');
        while(a > 0){
            if(a % 2 != 0){
                if(s[s.length()-1] == 'D'){
                    s.push_back('E');
                }
                else{
                    s.push_back('D');
                }
                a = a/2;
            }
            else{
                if(s[s.length()-1] == 'D'){
                    s.push_back('D');
                }
                else{
                    s.push_back('E');
                }
                a = a/2;
            }
        }
        if(s[s.length()-1] == 'E'){
            return "Doctor";
        }
        else{
            return "Engineer";
        }
    }
};