class Solution {
public:
    string replaceSpace(string s) {
        auto iter=s.begin();
        string temp="%20";
        auto tbeg=temp.begin();
        auto tend=temp.end();
        auto n=temp.size();
        while(iter!=s.end()){
            if(*iter==' '){
                iter=s.insert(iter, tbeg,tend);
                iter+=n;
                iter=s.erase(iter);
            }else{
                ++iter;
            }
        }
        return s;
    }
};