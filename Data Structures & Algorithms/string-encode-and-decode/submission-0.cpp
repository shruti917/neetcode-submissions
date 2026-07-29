
class Solution {
public:


    string encode(vector<string>& strs) {
        vector<int>count;
        string ans;


        for(auto s: strs){
            ans+= to_string(s.size());
            ans +=',';
        }
        ans+='#';

        for(auto s: strs){
            ans+= s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n=s.length();
        vector<string>ans;
        if(s=="#")return ans;
        int i=0;
        vector<int>num;

                while (s[i] != '#') {
            string temp = "";

            while (s[i] != ',') {
                temp += s[i];
                i++;
            }

            num.push_back(stoi(temp));
            i++; // skip ','
        }



        i++;

        


          for(auto len :num){
 ans.push_back(s.substr(i,len));
 i+=len;
  
        }
        return ans;
    }
};




