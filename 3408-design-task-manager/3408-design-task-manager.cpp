class TaskManager {
    struct Task { int priority; int taskId; };
    struct Compare {
        bool operator()(const Task &a, const Task &b) const {
            if (a.priority != b.priority) return a.priority < b.priority;
            return a.taskId < b.taskId;
        }
    };
    struct Info { int userId; int priority; };
    unordered_map<int, Info> taskMap;
    priority_queue<Task, vector<Task>, Compare> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) add(t[0], t[1], t[2]);
    }
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        it->second.priority = newPriority;
        pq.push({newPriority, taskId});
    }
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    int execTop() {
        while (!pq.empty()) {
            Task t = pq.top(); pq.pop();
            auto it = taskMap.find(t.taskId);
            if (it != taskMap.end() && it->second.priority == t.priority) {
                int user = it->second.userId;
                taskMap.erase(it);
                return user;
            }
        }
        return -1;
    }
};