class Solution {
public:
    vector<int> minOperations(string boxes) {
        int N = boxes.size();
        vector<int> l(N+2,0),r(N+2,0),res(N);
        int b=0,idx=0;
        for (int i=1; i<=N; i++){
            r[i] = (b+r[i-1]);
            b +=boxes[i-1]=='1';
        }
        b=0;
        for (int i=N; i>0; i--){
            l[i] = (b+l[i+1]);
            b +=boxes[i-1]=='1';
            res[i-1]= l[i]+r[i];
        }        
        return res;
    }
};