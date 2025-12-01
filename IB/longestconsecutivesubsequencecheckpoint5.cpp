int Solution::longestConsecutive(const vector<int> &nums) 
{
    set<int >s;
        
        for(int num : nums){
            s.insert(num);
        }
        int longstreak = 0;
        for(int num : nums){
            if(!s.count(num-1)){
                int currentnum = num;
                int currentstreak = 1;
                
                while(s.count(currentnum +1)){
                    currentnum += 1;
                    currentstreak += 1;
                }
                longstreak = max(longstreak,currentstreak);
            }
        }
        return longstreak;
    
    
}
