class MyHashMap {
public:
    vector<vector<int>> m;
    MyHashMap() {
        m = {};
    }
    
    void put(int key, int value) {
        vector<int> temp = {key, value};
        for(int i=0; i<m.size(); i++)
        {
            if(m[i][0]==key){
                m[i][1]=value;
                return;
            }
        }
        m.push_back(temp);
    }
    
    int get(int key) {
        for(int i=0; i<m.size(); i++)
        {
            if(m[i][0]==key){
                return m[i][1];
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0; i<m.size(); i++)
        {
            if(m[i][0]==key){
                m.erase(m.begin()+i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
