class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mymap;
        for(int i=0; i<strs.size(); ++i){
            string ss = strs[i];
            sort(ss.begin(), ss.end());
            mymap[ss].push_back(strs[i]);
        }
        vector<vector<string>>res;

        map<string,vector<string>>::iterator it = mymap.begin();

        for( ; it!=mymap.end(); ++it){
            sort(it->second.begin(),it->second.end());
            res.push_back(it->second);
        }

        return res;

    }
};