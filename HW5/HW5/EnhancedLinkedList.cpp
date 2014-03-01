// Author: Ilya Trofimov
// Group: 272(2)
// Date: 25 Feb 2013

#include "EnhancedLinkedList.h"

template <class T>
T& EnhancedLinkedList<T>::find_first(const T& key) {
	if (this->empty() | head == NULL)
		throw ListItemNotFoundException("List is empty");

	Node<T> *current = head;

	for (int i = 0; i < count; i ++) {
		if (current->getData() == key) {
			return current->getData();
		}
		current = current->getNext();
	}
	
	throw ListItemNotFoundException("Not found");
}
template<class T>
EnhancedLinkedList<T> EnhancedLinkedList<T>::find_all(const T& key) {
	EnhancedLinkedList<T> findList;
	Node<T> *current = this->head;

	while (current != NULL) {
		if (current->getData() == key) {
			findList.push_back(key);
		}
		current = current->getNext();
	}
	return findList;
}

template<class T>
void EnhancedLinkedList<T>::remove_first(const T& key) {
	if (head != NULL) {
		if (head->getData() == key) {
			pop_front();
			return;
		}

		Node<T> *current = head;
		Node<T> *previous = head;

		while (current != NULL && current != tail) {
			if (current->getData() == key) {
				if (current->getData() == key) {
					pop_front();
					return;
				}
				else {

				}
				previous->getNext() = current->getNext();
				delete current;
				count--;
				current = previous->getNext();
				return;
			}
			else {
				previous = current;
				current = current->getNext();
			}
		}

		if (tail->getData() == key) {
			pop_back();
		}
	}
}

template <class T>
void EnhancedLinkedList<T>::remove_all(const T& key)
{
	if (head != NULL) {
		Node<T>* current = head;
		Node<T>* previous = head;

		while (current != tail && current != NULL) {
			if (current->getData() == key) {
				if (current == head) {
					pop_front();
					current = head;
					previous = head;
				}
				else {
					previous->getNext() = current->getNext();
					delete current;
					count--;
					current = previous->getNext();
				}
			}
			else {
				previous = current;
				current = current->getNext();
			}
		}
		if (tail->getData() == key) {
			pop_back();
		}
	}
}
