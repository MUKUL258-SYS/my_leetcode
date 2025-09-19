class TaskManager {
public:
unordered_map<int,int>mp2;
map<pair<int,int>,int>mp1;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks){
            int priority=i[2];
            int userId=i[0];
            int taskId=i[1];
            mp1[{priority,taskId}]=userId;
            mp2[taskId]=priority;
        }
    }
    
    void add(int userId, int taskId, int priority) {
          mp1[{priority,taskId}]=userId;
          mp2[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        int oldpriority=mp2[taskId];
        int userId=mp1[{oldpriority,taskId}];
        mp1.erase({oldpriority,taskId});
        mp1[{newPriority,taskId}]=userId;
        mp2[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        int priority=mp2[taskId];
        mp1.erase({priority,taskId});
        mp2.erase(taskId);
    }
    
    int execTop() {
        if(!mp1.size())return -1;
        auto it=prev(mp1.end());
        int ans=it->second;
        int taskId=it->first.second;
        mp1.erase(it);
        mp2.erase(taskId);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */