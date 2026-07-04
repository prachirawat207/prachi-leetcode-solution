class Solution {
public:
    string frequencySort(string s) {
        int freq[128]={0};
        string ans="";
        for(char ch:s){
            freq[ch]++;
        }
      vector<pair<int,char>>v;
        for(int i=0;i<128;i++){
            if(freq[i]>0){
              v.push_back({freq[i],char(i)});
            }
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        for(auto ch:v){
            while(ch.first--){
                ans+=ch.second;
            }
        }
        return ans;
    }
};