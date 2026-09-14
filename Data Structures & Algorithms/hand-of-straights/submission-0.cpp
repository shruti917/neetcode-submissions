class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n= hand.size();
        sort(hand.begin(),hand.end());
        unordered_map<int,int>mp;
        for(int c:hand)mp[c]++;


        for(int num: hand){
            if(mp[num]>0){
                for(int i=num;i<num+ groupSize;i++){
                    if(mp[i]==0)return false;
                    mp[i]--;
                }
            }
        }
        return true;


    }
};
