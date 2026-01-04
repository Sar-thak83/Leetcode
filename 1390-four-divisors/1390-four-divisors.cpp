class Solution {
public:

    int sumDivi(int num){
        int Divisor=0;
        int sum=0;
        for( int fact=1;fact*fact <= num;fact++){
            if(num%fact==0){
                int other =num/fact;
                if(fact==other){
                    Divisor+=1;
                    sum+=fact;
                }
                else{
                    Divisor+=2;
                    sum+=(other+fact);
                }
            }
            if(Divisor>4){
                return 0;
            }
        }
        return Divisor==4?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;

        for(int & num : nums){
            ans +=sumDivi(num);
        }
        return ans;
        
    }
};