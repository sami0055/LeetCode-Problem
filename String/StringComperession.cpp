class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int ansindex=0;
        while(i<n)
        {
            int c=1;
             char ch=chars[i];
            int j=i+1;
            while(j<n && chars[i]==chars[j])
            {
                j++;
            }
            chars[ansindex++]=chars[i];
            if((j-i)>1)
            {
                string cnt=to_string(j-i);
                for(auto m:cnt)
                chars[ansindex++]=m;
            }

            i=j;
        }
        
      return ansindex;
    }
};