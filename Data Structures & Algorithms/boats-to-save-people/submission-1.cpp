class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0;
        int r = people.size()-1;
        int boat = 0;

        sort(people.begin(), people.end());

        while(l < r)
        {
            if(people[l] + people[r] <= limit)
            {
                boat++;
                people.erase(people.begin()+l);
                people.erase(people.begin()+(r-1));
                l = 0;
                r = people.size()-1;
            }
            else
            {
                r--;
            }
        }
        if(people.size() != 0)
        {
            boat += people.size();
        }
        return boat;
    }
};