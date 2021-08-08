class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=s.size();
        int m=words.size();
        auto beg=s.begin(),end=s.end();
        for(int i=0,sum=0;i!=m;++i){
            if(end-beg<words[i].size())return false;
            if(!equal(words[i].begin(),words[i].end(),beg))return false;
            beg+=words[i].size();
            if(beg>=end)break;
        }
        if(beg<end)return false;
        return true;
    }
};