        class Solution {
        public:
            vector<vector<string>> partition(string s) {
                // Start typing your C/C++ solution below
                // DO NOT write int main() function
                const char* pstr = s.c_str();
                return partition(pstr,0,s.length()-1);
            }
        private:
            vector<vector<string>> partition(const char* ptr, int start,int end)
            {
                vector<vector<string>> vec;
                if(isPalindrome(ptr,start,end))
                {
                    string tempS(ptr,start,end-start+1);
                    vector<string> v(1,tempS);
                    vec.push_back(v);
                }
                for(int i=start; i < end; i++)
                {
                    if(!isPalindrome(ptr,start,i))
                       continue;
                    string sTemp(ptr,start,i-start+1);
                    vector<vector<string>> vecL,vecR;
                     vecR = partition(ptr,i+1,end);
                     for(vector<vector<string>>::iterator iterR = vecR.begin();iterR!=vecR.end();iterR++)
                        {
                            vector<string> temp;
                            temp.push_back(sTemp);

                            for(vector<string>::iterator it = (*iterR).begin(); it!=(*iterR).end();it++)
                            {
                                temp.push_back(*it);
                            }
                                                        vec.push_back(temp);
                        }
         
                  }
                   sort(vec.begin(),vec.end());
              
                for(vector<vector<string>>::iterator it = vec.begin(); it!=vec.end()-1;)
                            {
                                if(*it == *(it+1))
                                {
                                  it = vec.erase(it);
                                  
                                 }
                                 else
                                   it++;
                                
                            }

                               return vec;
            }
            bool isPalindrome(const char* ptr,int start, int end)
            {
                while(start < end)
                {
                    if(ptr[start] != ptr[end])
                       return false;
                    start++;
                    end--;
                }
                return true;
            }
            int getCut(const char* ptr, int start, int end)
            {
               if((end - start) < 1)
                 return 0;
               if(isPalindrome(ptr,start,end))
                 return 0;
               int minC = end - start;
               for(int i = start; i < end; i++)
               {
                 int temp = getCut(ptr, start, i) + getCut(ptr, i+1, end) + 1;
                 if(temp <minC)
                    minC = temp;
               }
               return minC;
             }
        };