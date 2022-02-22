#include <bits/stdc++.h>
using namespace std;

/*
    Question Link : {https://leetcode.com/problems/lru-cache/}
*/

class LRUCache
{
private:
    int capacity;
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> position;

    void helper(int key)
    {
        if (position.find(key) != position.end())
        {
            recent.erase(position[key]);
        }
        else if (recent.size() >= capacity)
        {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            position.erase(old);
        }
        recent.push_front(key);
        position[key] = recent.begin();
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            helper(key);
            return cache[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        helper(key);
        cache[key] = value;
    }
};

int main(){
    LRUCache obj(3);
    obj.put(1, 1);
    obj.put(2, 2);
    obj.put(3, 3);
    cout << obj.get(2)<<endl;
    cout << obj.get(4)<<endl;
    obj.put(4, 4);
    obj.put(2, 5);
    cout << obj.get(3)<<endl;
}