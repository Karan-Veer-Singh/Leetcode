class Solution {
public:
    string intToRoman(int num) 
    {
        int intCode[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string ans = "";
        int i = 0;
        
        while(num > 0)
        {
            int div = num/intCode[i];
            num = num%intCode[i];
            
            while(div--)
            {
                ans += code[i];
            }
            
            i++;
        }
        
        return ans;    
    }
};

// https://leetcode.com/problems/integer-to-roman/submissions/
