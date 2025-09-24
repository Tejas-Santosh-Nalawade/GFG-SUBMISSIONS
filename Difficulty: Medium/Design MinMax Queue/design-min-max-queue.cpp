class SpecialQueue {

  public:

deque<int> dq;
    map<int,int> mp;
    void enqueue(int x) {
        // Insert element into the queue
        dq.push_back(x);
        mp[x]++;
    }

    void dequeue() {
        // Remove element from the queue
        int x = dq.front();
        dq.pop_front();
        mp[x]--;
        if(mp[x] == 0)
            mp.erase(x);
    }

    int getFront() {
        // Get front element
        return dq.front();
    }

    int getMin() {
        // Get minimum element
        auto it = mp.begin();
        return (*it).first;
    }

    int getMax() {
        // Get maximum element
        auto it = mp.rbegin();
        return (*it).first;
    }
};