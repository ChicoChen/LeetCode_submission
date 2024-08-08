class Solution {
public:
    // my performance is bad
    // maybe becuase of function call overhead?
    vector<vector<int>> path;
    vector<int> corner;
    void appendPath(int direction, int distance, int rows, int cols){
        int dimension = 1 - (direction % 2);
        int offset = (direction < 2)? 1: -1;
        for(int i= 0; i< distance; i++){
            corner[dimension] += offset;
            if(corner[0] < 0 || corner[0] >= rows){
                continue;
            }else if(corner[1] < 0 || corner[1] >= cols){
                continue;
            }
            else{ path.push_back(corner); }
        }
    }
    
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        corner = vector<int>{rStart, cStart};
        path.push_back(corner);

        int distance = 0;
        while(path.size() < rows * cols){
            distance++;
            appendPath(0, distance, rows, cols);
            appendPath(1, distance, rows, cols);
            distance++;
            appendPath(2, distance, rows, cols);
            appendPath(3, distance, rows, cols);
        }
        return path;
    }
};