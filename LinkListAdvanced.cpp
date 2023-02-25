#include<iostream>
#include<string>
#include<string>
#include<stack>
using namespace std;

template <class T>
struct Node {
	T data;
	Node* pnext;
	Node(T data) {
		this->data = data;
		this->pnext = nullptr;
	}
};
template <class T>
class SLL {
private: 
	Node<T>* head;
public:
	SLL()
	{
		head = nullptr;
	}
	void install(int* arr, int size) {
		for (int i = 0; i < size; i++) {
			Node<T>* node = new Node<T>(arr[i]);
			if (head == nullptr)
			{
				head = node;
			}
			else {
				Node<T>* tmp = head;
				while (tmp->pnext != nullptr){
					tmp = tmp->pnext;
				}
				tmp->pnext = node;
			}
		}
	}
	void intSertH(int value) {
		Node<T>* new_head = new Node<T>(value);
		new_head->pnext = head;
		this->head = new_head;
	}
	void intSertMid(T value, int position) {
		Node<T>* pNew = new Node<T>(value);
		Node<T>* pTemp = head;
		Node<T>* pBeforce = new Node<T>(pTemp->data);
		int index = 0;
		while (position != index) {
			index++;
			pBeforce = pTemp;
			pTemp = pTemp->pnext;
		}
		pNew->pnext = pTemp;
		pBeforce->pnext = pNew;
	}
	void insertT(int value) {
		Node<T>* pTemp = head;
		Node<T>* pNew = new Node<T>(value);
		while(pTemp->pnext != nullptr){
			pTemp = pTemp->pnext;
			//if (pTemp->pnext == nullptr) {
			//	pTemp->pnext = pNew;
			//	return;
			//}
			//else {
			//	pTemp = pTemp->pnext;
			//}
		}
		pTemp->pnext = pNew;
	}
	void delH() {
		Node<T>* delNode = head;
		head = head->pnext;
		delete delNode;
	}
	void delM(int target) {
		Node<T>* pTemp = head;
		Node<T>* pPrev = nullptr;
		while (pTemp != nullptr) {
			if (pTemp->data == target) {
				pPrev->pnext = pTemp->pnext;
				delete pTemp;
				pTemp = pPrev->pnext;
			}
			else {
				pPrev = pTemp;
				pTemp = pTemp->pnext;
			}
		}
		return;
	}
	void delposition(int postion) {
		Node<T>* pTemp = head;
		Node<T>* pPrev = nullptr;
		int count = 0;
		while (pTemp != nullptr)
		{
			count++;
			if (count == postion) {
				pPrev->pnext = pTemp->pnext;;
				delete pTemp;
				pTemp = pPrev->pnext;
			}
			else {
				pPrev = pTemp;
				pTemp = pTemp->pnext;
			}
		}
	}
	void delT() {
		Node<T>* pTemp = head;
		Node<T>* pPrev = nullptr;
		while (pTemp != nullptr)
		{
			if (pTemp->pnext != nullptr) {
				pPrev = pTemp;
				pTemp = pTemp->pnext;

			}
			else {
				pPrev->pnext = pTemp->pnext;
				delete pTemp;
				pTemp = pPrev->pnext;
			}
		}
	}
	Node<T>* search(int target) {
		Node<T>* pTemp = head;
		int count = 0;
		while (pTemp != NULL && count == target) {
			count++;
			pTemp = pTemp->pnext;
		}
		return pTemp;
	}
	Node<T>* reverseList() {
		Node<T>* pTemp = head;
		Node<T>* pPrev = nullptr;
		Node<T>* nextNode = nullptr;
		while (pTemp != nullptr) {
			nextNode = pTemp->pnext;
			pTemp->pnext = pPrev;
			pPrev = pTemp;
			pTemp = nextNode;
		}
	    return pPrev;

	}
	void print(){
		Node<T>* tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data << endl;
			tmp = tmp->pnext;
		}
	}
};

int main() {
	int arr[10] = { 1,2,3,4,5 };
	SLL<int> sll;
	sll.install(arr, 5);
	// sll.intSertH(20);
	// sll.intSertMid(99, 2);
	// sll.delM(3);
	// sll.delposition(2);
	// sll.insertT(12);
	sll.insertT(3);
	sll.print();
	return 0;
}