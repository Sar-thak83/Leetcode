class Solution {
public:
    bool isPalindrome(int x) {
        long long ans =0, temp=x;
        if(x<0)
        {
            return false;
        }
        while(temp!=0)
        {
            int digit = temp%10;
            ans = (ans * 10) + digit;
            temp/=10;
        }
        if (x==ans)
        {
            return true ;
        }
        else 
        {
            return false ;
        }
    }
};