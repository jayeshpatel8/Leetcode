void merge_interval(vector<vector<int>>& it,vector<vector<int>>& res, int merge_idx){
    int i=merge_idx,j = (res.size()-1);

    for ( ;i< it.size(); i++){
        if (res[j][1] > it[i][1])
            continue;
        else 
        {
            if (res[j][1] >= it[i][0])
                res[j][1] = max (it[i++][1],res[j][1]);
            break;
        }
    }
    for (; i< it.size(); i++)
         res.push_back(it[i]);
     
}    
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s= intervals.size();
        vector<vector<int>> res;
        
        int i;
        for ( i=0; i<s;i++){
            if (newInterval[0]<intervals[i][0])
            {
                res.push_back(newInterval); 
                
                if (i) {
                    int j= res.size()-1;
                    if (res[j-1][1] >= res[j][0]){
                        res[j-1][1] = max(res[j][1],res[j-1][1]);                        
                        res.pop_back();           
                    }                      
                }
                break;                
            }
            res.push_back(intervals[i]);
        }
        if (i==s)
        {
            res.push_back(newInterval);
            if (res.size() > 1) {
                int j= res.size()-1;
                if (res[j-1][1] >= res[j][0]){
                    res[j-1][1] = max(res[j][1],res[j-1][1]);
                    res.pop_back();           
                }         
            }               
        }
        else
            merge_interval(intervals,res,i);
        
        return res;
    }
};