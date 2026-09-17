class Solution {
public:
    bool checkValidString(string s) {
        int minopen=0;
        int maxopen=0;
        
        for(char c: s){
            if(c=='('){
                minopen++;
                maxopen++;
            }
            else if(c==')'){
                minopen--;
                maxopen--;
            }
            else{
             minopen--;
                maxopen++;
            }
            if(minopen<0) minopen=0;
            else if(maxopen<0)return false;
        }
        return minopen==0;
    }
};
