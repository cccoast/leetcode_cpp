#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;
void lru();
class LRUCache {
	struct cache_struct {
		int value;
		int use_count;
		list<int>::iterator pstack;
	};
	map<int, cache_struct> cache;
	list< int > stack;
	int size;
	int internal_count;
public:
	LRUCache(int capacity) {
		this->size = capacity;
		this->internal_count = 0;
	}
	void update_stack(list< int >::iterator& stack_iter,int key) {
		stack.push_front(key);
		auto tobedelted = stack_iter;
		stack_iter = stack.begin();
		stack.erase(tobedelted);
	}

	int get(int key) {
		auto cache_iter = cache.find(key);
		if (cache_iter == cache.end()) {
			return -1;
		}
		else {
			cache_iter->second.use_count = internal_count++;
			update_stack(cache_iter->second.pstack, key);
			return cache_iter->second.value;
		}
	}

	void put(int key, int value) {
		auto cache_iter = cache.find(key);
		if (cache_iter == cache.end()) {
			if (cache.size() >= this->size) {
				auto stack_iter = stack.rbegin();
				cache.erase(*stack_iter);
				stack.pop_back();
			}
			auto new_cache = cache.insert(make_pair(key, cache_struct{ value, internal_count++, {} }));
			stack.push_front(key);
			list< int >::iterator new_stack = stack.begin();
			new_cache.first->second.pstack = new_stack;
		}
		else {
			auto& tmp = cache[key];
			tmp.use_count = internal_count++;
			tmp.value = value;
			update_stack(tmp.pstack, key);
		}
	}
};
