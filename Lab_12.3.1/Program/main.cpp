#include <iostream>
using namespace std;

struct S {
	S* next = nullptr;
	S* parent = nullptr;
	int num;
};

void list_factory(const int& count, S* start, S* &end) {
	S* next = start;
	for (size_t i = 0; i < count; )
	{
		cout << "Input " << i << " num: "; cin >> next->num;
		i++;
		
		if (i < count) {
			next->next = new S();
			next->next->parent = next;
			end = next = next->next;
		}
	}
}

void list_draw(S* start) {
	while (start) {
		cout << start->num << endl;
		start = start->next;
	}
}

void list_plus(S* start, const int &count) {
	while (start) {
		start->num+= count;
		start = start->next;
	}
}

void delete_list(S* &start, S* &end) {
	start = nullptr;
	S* tmp;
	while (end) {
		tmp = end;
		end = end->parent;
		delete tmp;
	}
	end = nullptr;
}

void main() {
	int size;
	cout << "Input list size: "; cin >> size;
	S* start = new S(), *end = start;
	int count;
	list_factory(size, start, end);
	list_draw(start);
	cout << endl;
	cout << "Input list count plus: "; cin >> count;
	list_plus(start, count);
	list_draw(start);
	cout << endl << (int)start << endl << (int)end << endl;
	delete_list(start, end);
	cout << (int)start << endl << (int)end << endl;
}