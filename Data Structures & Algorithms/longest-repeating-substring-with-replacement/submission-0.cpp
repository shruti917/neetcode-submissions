class Solution {
public:
    int characterReplacement(string s, int k) {
        

int n=s.length();
unordered_map<char,int>mp;
int maxi=0;
int l=0;
int res=0;

for(int i=0;i<n;i++){
mp[s[i]]++;
maxi=max(maxi, mp[s[i]]);

while((i-l+1)-maxi > k){
    mp[s[l]]--;
    l++;
}
res= max(res, i-l+1);
}
return res;
    }
};
