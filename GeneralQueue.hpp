#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;
	public:
		//Default constructor
		Queue(){
			_size = 0;
		}

		//Copy constructor
		Queue(Queue &q){
			_data = q._data;
			_size = q._size;
		}

		//Getters
		size_t size() const{
			return _size;
		}

		Q front() const{
			return _data.front();
		}

		Q back() const{
			return _data.back();
		}

		//Push to queue
		void enqueue(Q value){
			_data.push_back(value);
			_size += 1;
		}

		//Pop from queue
		void dequeue(){
			_data.pop_front();
			_size += 1;
		}

		void print(){
			std::cout << *this << std::endl;
		}

		bool search(Q value){
			return _data.search(value);
		}

		bool empty(){
			return _data.empty();
		}

		Queue<Q> operator=(const Queue<Q> q) {
			_data = q._data;
			_size = _data.size();
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(Queue<U> &left_queue, Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(Queue<U> &left_queue, Queue<U> &right_queue);
};

template <class U>
std::ostream &operator<<(std::ostream &out, const Queue<U> &q){
	out << q._data;
	return out;
}
	
template <class U>
bool operator==(Queue<U> &left_queue, Queue<U> &right_queue){
	if (left_queue.size() == right_queue.size()){
		if (left_queue._data == right_queue._data){
			return true;
		}
	}
	else{
		return false;
	}
}

template <class U>
bool operator!=(Queue<U> &left_queue, Queue<U> &right_queue){
	if (left_queue.size() != right_queue.size()){
		return true;
	}
	else if (left_queue._data == right_queue._data){
		return false;
	}
	else{
		return true;
	}
}
