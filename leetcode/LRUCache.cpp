#include "LRUCache.h"
#include <iostream>
using namespace std;
void lru(){
	LRUCache cache(2);
	/*
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache.get(2) << endl;       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache.get(1) << endl;       // 返回 -1 (未找到)
	cout << cache.get(3) << endl;       // 返回  3
	cout << cache.get(4) << endl;       // 返回  4
	*/
	cache.put(2, 1);
	cache.put(2, 2);
	cout << cache.get(2) << endl;      
	cache.put(1, 1);          
	cache.put(4, 1);    
	cout << cache.get(2) << endl;
}