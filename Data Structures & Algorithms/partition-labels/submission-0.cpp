class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>res;
        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)mp[s[i]]=i;
        int i=0;
        while(i<n){
          int size=  mp[s[i]];
          for(int j=i;j<=size;j++){
            if(mp[s[j]]> size)
            size=mp[s[j]];
          }
          res.push_back(size-i+1);
          i=size+1;
        }
        return res;
    }
};
