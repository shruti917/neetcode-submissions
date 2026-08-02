class Solution {
public:
    
    string small_alpha(string s){
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++){
if(isalnum(s[i])) ans+= tolower(s[i]);
        }
        return ans;
    }

    bool isPalindrome(string s) {
        s= small_alpha(s);

        int i=0;
        int j=s.length()-1;

while(i<j){
    if(s[i] != s[j]) return false;
    i++;
    j--;
}
return true;

    }
};
