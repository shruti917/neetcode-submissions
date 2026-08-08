class Solution {
public:
    string minWindow(string s, string t) {
 if (t.empty()) return "";
 unordered_map<char,int>mp_s,mp_t;

 for(char c:t){
    mp_t[c]++;
 }

 
 int l=0,have=0, need= mp_t.size();
int len = INT_MAX;
 pair<int, int> res = {-1, -1};

 for(int r=0;r<s.length();r++)
{
    char num=s[r];
    mp_s[num]++;
    if(mp_t.count(num) && mp_t[num]==mp_s[num]) have++;

    while(have==need){
        if(r-l+1 < len){
            len=r-l+1;
            res={l,r};
        }

        mp_s[s[l]]--;
        if(mp_t.count(s[l]) && mp_t[s[l]]>mp_s[s[l]]) have--;
l++;
    }
}
return len==INT_MAX? "": s.substr(res.first,len);
    }
};
