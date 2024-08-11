class Solution {
public:
    //learn form solution
    //todo: learn from other solution
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> task;
        int maxCount = 0;
        //iterate through the tasks to find maximum occurence
        //assume that the correspomding task is T
        for(char t : tasks){
            task[t]++;
            maxCount = max(maxCount, task[t]);
        }

        //we need at least (count - 1) * (n + 1) cycle to complete n-1 occurance of T
        int leastTime = (maxCount - 1) * (n + 1);
        //add 1 cycle for last occurence of T
        //also, if there exist task with teh same occurence of T, 
        //need another 1 cycle to finish their last occurance.
        for(auto t: task){
            if(t.second == maxCount){ leastTime++; }
        }

        //here you might be wondering how about the case when more than n tasks
        //have maximum occurence? In that case, just insert those task
        //between each occurence of T, in this way we won't violate the n idle time limit
        
        //Another case, there're lots of trivial task only occurence once.
        //insert them after the first T and before the second T
        //or after them at the end
        //both won't violate the constraint.

        //in both case, total time taken equal to tasks.size()
        //hence the answer is actually size of tasks, lower-bounded by leastTime

        int answer = max((int)tasks.size(), leastTime);
        return answer;
    }
};