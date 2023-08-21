class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // add and remove take O(1) and we might do this for every number in nums
        // => time: O(1)xn = O(n), space: O(n)
        deque<int> q;
        vector<int> res;
        int l=0, r=k, maxIndex=0;
        // create first window
        for(int i=0; i<k; i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                    q.pop_back();
            }
            q.push_back(i);                        
        }
        res.push_back(nums[q.front()]);

        // check each window
        for(int r=k; r<nums.size(); r++){
            l++;
            if(!q.empty() && l > q.front())
                q.pop_front();

            while(!q.empty() && nums[r] >= nums[q.back()]){
                    q.pop_back();
            }
            q.push_back(r);  
                  
            res.push_back(nums[q.front()]);
        }

        return res;

    //         vector<int> result;
    // if (k == 0) return result;
    // deque<int> w;
    // for (int i = 0, n = (int)nums.size(); i < n; i++) {
    //     while (!w.empty() && w.front() <= i-k)
    //         w.pop_front();
    //     while (!w.empty() && nums[w.back()] <= nums[i])
    //         w.pop_back();
    //     w.push_back(i);
    //     if (i >= k-1)
    //         result.push_back(nums[w.front()]);
    // }
    // return result;
    }
};


// [1,3,-1,-3,5,3,6,7]
//  l
//              r

//  Q[7]  Resrult[3, 3, 5, 5, 6, 7]