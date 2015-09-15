class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!needle || !haystack) return haystack;
        char *ret = NULL;
        int len1 = 0, len2 = 0;
        char *h = haystack, *n = needle;
        while(*h != '\0') 
        {
            len1++; h++;
        }
        while(*n != '\0') 
        {
            len2++; n++;
        }
        if(len2 == 0) return haystack;
        if(len1 < len2) return NULL;
        //if(find(haystack, needle, ret));
        find(haystack, needle, haystack+len1, len2, ret);
        return ret;
    }
private:
    bool find(char *hh, char *nh, const char *ht, const int len2, char *&ret)
    {
        
        while(*hh != '\0')
        {
            if(hh + len2 > ht) return false;  //*ht == '\0';
            if(*hh == *nh)
            {
                char *h = hh, *n = nh, *he = hh+len2-1, *ne = nh+len2-1;
                
                while(h <= he && *h == *n && *he == *ne)
                {
                    h++;  n++; he--; ne--;
                }
                if(he < h)
                {                    
                    ret = hh;
                    return true;
                }
               
            }
            hh++;
        }
        return false;
    }
    bool find(char *haystack, char *needle, char *&ret)
    {
        if(*needle == '\0') return true;
        while(*haystack != '\0')
        {
            if(*haystack == *needle)
            {
                char *h = haystack, *n = needle;
                while(*n != '\0' && *h != '\0' && *h == *n)
                {
                    n++; h++;
                }
                if(*n == '\0')
                {
                    ret = haystack;
                    return true;
                }
                else
                {
                    haystack = h;
                }
            }
            haystack++;
        }
        return false;
    }
};