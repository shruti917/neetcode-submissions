class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        unordered_map<char,int>st1;
        unordered_map<char,int>st2;

        for(int i=0;i<n;i++){
            st1[s1[i]]++;
        }

        for(int i=0;i<n;i++){
st2[s2[i]]++;
        }
        if(st1== st2) return true;
        int j=n;

        while(j<m){

st2[s2[j-n]]--;
if(st2[s2[j-n]]==0)st2.erase(s2[j-n]);

      st2[s2[j]]++;
      if(st1== st2) return true;
      j++;


        }
        return false;

    }
};
