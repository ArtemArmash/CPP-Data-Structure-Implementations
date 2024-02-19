#include <iostream>
using namespace std;

template<class T>
class List {
private:
	template<class T>
	class Node {
	public:
		Node* p_Next;
		T datas;

		Node(T datas = T(), Node* p_Next = nullptr) : datas{ datas }, p_Next{ p_Next } {}

	};
	int size;
	Node<T>* head;

public:

	List() : size{ 0 }, head{ nullptr } {}
	~List() {
		cout << "Destructor called\n";
		clear();
	}

	Node<T>* cloneList() const {
		if (head == nullptr) {
			return nullptr;
		}

		Node<T>* new_head = new Node<T>(head->datas);
		Node<T>* current_new = new_head;
		Node<T>* current_old = head->p_Next;

		while (current_old != nullptr) {
			current_new->p_Next = new Node<T>(current_old->datas);
			current_new = current_new->p_Next;
			current_old = current_old->p_Next;
		}

		return new_head;
	}

	T& operator[] (const int index) {
		int count = 0;
		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (count == index) {
				return current->datas;
			}
			current = current->p_Next;
			count++;
		}
	}

	List<T> operator+ (const List<T>& other) {
		List<T> result;
		Node<T>* this_clone = cloneList();
		Node<T>* other_clone = other.cloneList();

		if (this_clone == nullptr) {
			result.head = other_clone;
			return result;
		}

		Node<T>* current = this_clone;
		while (current->p_Next != nullptr) {
			current = current->p_Next;
		}

		current->p_Next = other_clone;
		result.head = this_clone;
		return result;
	}

	List<T> operator* (const List<T>& other) {
		List<T> result;
		Node<T>* this_clone = cloneList();
		Node<T>* other_clone = other.cloneList();

		Node<T>* current_this = this_clone;
		while (current_this != nullptr) {
			Node<T>* current_other = other_clone;
			while (current_other != nullptr) {
				if (current_this->datas == current_other->datas) {
					result.push_back(current_this->datas);
					break;
				}
				current_other = current_other->p_Next;
			}
			current_this = current_this->p_Next;
		}

		return result;
	}

	int getsize() { return size; }

	void push_back(T datas) {
		if (head == nullptr) {
			head = new Node<T>(datas);
		}
		else {
			Node<T>* current = this->head;
			while (current->p_Next != nullptr) {
				current = current->p_Next;
			}
			current->p_Next = new Node<T>(datas);
		}
		size++;
	}

	void push_front(T datas) {
		head = new Node<T>(datas, head);
		size++;
	}

	void pop_front() {
		Node<T>* tmp = head;
		head = head->p_Next;
		delete tmp;
		size--;
	}

	void pop_back() {
		removeAT(size - 1);
	}

	void Insert(T datas, int index) {
		if (index == 0) {
			push_front(datas);
		}
		Node<T>* prev = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			prev = prev->p_Next;
		}
		Node<T>* newNode = new Node<T>(datas, prev->p_Next);
		prev->p_Next = newNode;
		size++;
	}

	void removeAT(int index) {
		if (index == 0) {
			pop_front();
		}
		Node<T>* prev = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			prev = prev->p_Next;
		}
		Node<T>* tmp_delete = prev->p_Next;
		prev->p_Next = tmp_delete->p_Next;
		delete tmp_delete;
		size--;
	}

	void clear() {
		while (size) {
			pop_front();
		}
	}

};


int main() {
	List<int>lst;

	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(101);

	for (size_t i = 0; i < lst.getsize(); i++)
	{
		cout << lst[i] << ' ';
	}
	cout << endl << "Insert: " << endl;

	lst.removeAT(1);

	for (size_t i = 0; i < lst.getsize(); i++)
	{
		cout << lst[i] << ' ';
	}
}