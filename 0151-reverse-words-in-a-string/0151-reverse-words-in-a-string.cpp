class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string ans="" ;
      reverse(s.begin(),s.end());
      for(int i=0;i<n;){
       while (i < n && s[i] == ' ')
                i++;

            string word = "";
        while(i<n&&s[i]!=' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.size()>0){
        ans+=" "+word;
        }
      } 
      return ans.substr(1); 
    }
};