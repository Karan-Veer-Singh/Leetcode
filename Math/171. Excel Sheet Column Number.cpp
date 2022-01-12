class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int columnNumber = 0;
        
        for(char c : columnTitle)
        {
            int d = c - 'A' + 1;
            columnNumber = (columnNumber*26) + d;
        }
        
        return columnNumber;
    }
};

// https://leetcode.com/problems/excel-sheet-column-number/submissions/
