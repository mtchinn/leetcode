string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string ret("");
        int mymin = INT_MIN;
        for(int i=0; i<strs.size(); ++i)
            if(strs[i].size()<mymin)
                mymin = strs[i].size();
        int low = 1;
        int high = mymin;
        while(low<=high){
            int mid = (low+high)/2;
            string str = strs[0].substr(0,mid);
            if(isCommonPrefix(strs,str)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        ret = strs[0].substr(0,(low+high)/2);
        return ret;
    }
    bool isCommonPrefix(vector<string>& strs, string pre){
        for(int i=0; i<strs.size(); ++i){
            if(strs[i].find(pre)!=0)
                return false;
        }
        return true;
    }