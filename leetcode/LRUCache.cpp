#include "LRUCache.h"
#include <iostream>
using namespace std;
void lru(){
	LRUCache cache(2);
	/*
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // ����  1
	cache.put(3, 3);    // �ò�����ʹ����Կ 2 ����
	cout << cache.get(2) << endl;       // ���� -1 (δ�ҵ�)
	cache.put(4, 4);    // �ò�����ʹ����Կ 1 ����
	cout << cache.get(1) << endl;       // ���� -1 (δ�ҵ�)
	cout << cache.get(3) << endl;       // ����  3
	cout << cache.get(4) << endl;       // ����  4
	*/
	cache.put(2, 1);
	cache.put(2, 2);
	cout << cache.get(2) << endl;      
	cache.put(1, 1);          
	cache.put(4, 1);    
	cout << cache.get(2) << endl;
}