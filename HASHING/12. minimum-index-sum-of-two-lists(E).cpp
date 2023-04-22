class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m;
        vector<string> v;
        int min=INT_MAX;
        int sum=0;
        for(int i=0;i<list1.size();i++)
        m[list1[i]]=i;
        for(int i=0;i<list2.size();i++){
            if(m.find(list2[i]) != m.end()){
                sum=i+m[list2[i]];
                if(sum < min){
                    v.clear();
                    min=sum;
                    v.push_back(list2[i]);
                }
                else if(sum==min){
                    v.push_back(list2[i]);
                }
            }
        }
        return v;
    }
};
