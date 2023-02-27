/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* help(vector<vector<int>>& grid, int rowstart, int rowend, int colstart, int colend)
    {
        if(rowstart > rowend || colstart > colend) return NULL;
        int val = grid[rowstart][colstart];
        bool flag = true;
        for(int i = rowstart; i <= rowend; i++)
        {
            for(int j = colstart; j <= colend; j++)
            {
                if(grid[i][j] != val)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }
        if(flag) return new Node(val, true);
        int rowmid = (rowstart + rowend)/2;
        int colmid = (colstart + colend)/2;
        Node* topleft = help(grid, rowstart, rowmid, colstart, colmid);
        Node* topright = help(grid, rowstart, rowmid, colmid+1, colend);
        Node* bottomleft = help(grid, rowmid+1, rowend, colstart, colmid);
        Node* bottomright = help(grid, rowmid+1, rowend, colmid+1, colend);
        return new Node(false, false, topleft, topright, bottomleft, bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return help(grid, 0, n-1, 0, n-1);
    }
};
