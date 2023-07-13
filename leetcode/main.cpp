
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A :public enable_shared_from_this<A> {
public:
	vector<shared_ptr<A>> v;

	A() :v(26, NULL) {

	}

	shared_ptr<A> get_ptr() {
		return shared_from_this();
	}

	void show_val() {
		auto p = shared_from_this();
		cout << p.use_count() << endl;
	}

	void add_val(int p) {
		this->v[p] = make_shared<A>();
	}
};

//int main() {
//
//	shared_ptr<A> a = make_shared<A>();
//	a->add_val(0);
//
//	vector<shared_ptr<A>>* b = &a->v;
//	cout << a.use_count() << endl;
//	(*b)[1] = make_shared<A>();
//
//	b = &(*b)[1]->v;
//	(*b)[1] = make_shared<A>();
//	cout << a.use_count() << endl;
//	cout << "fuck you stupid" << endl;
//	return 0;
//}