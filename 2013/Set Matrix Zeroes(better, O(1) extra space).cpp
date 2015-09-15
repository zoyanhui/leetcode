class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int h = matrix.size();
        int w = 0;
        if (h > 0) w = matrix[0].size();
        
        bool c1 = false, r1 = false;
        for (int i = 0; i < h; i++) {
            if (matrix[i][0] == 0) {c1 = true; break;}
        }
        for (int i = 0; i < w; i++) {
            if (matrix[0][i] == 0) {r1 = true; break;}
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++){
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if (c1) for (int i = 0; i < h; i++) matrix[i][0] = 0;
        if (r1) for (int j = 0; j < w; j++) matrix[0][j] = 0;
    }
};