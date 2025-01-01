class Solution {
public:
    bool isCommonPrefix(vector<string>& strs, int len){
        string str1 = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].rfind(str1, 0) != 0) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int _min = INT_MAX;
        for(string str : strs) _min = min(_min, (int)str.size());
        int low = 1, high = _min;
        while(low <= high){
            int middle = (low+high)/2;
            if(isCommonPrefix(strs, middle)){
                low = middle + 1;
            }else{
                high = middle - 1;
            }
        }
        return strs[0].substr(0, high);
    }
};
