#include <iostream>
#include "GeneralList.hpp"

template <class T>
class Stack {
	private:
		List<T> _data;
		size_t _size;
		
	public:
		//Default constructor
		Stack(){
			_size = 0;
		}

		//Default copy constructor
		Stack(Stack &stack){
			_data = stack._data;
			_size = stack._size;
		}

		//Getters
		T top() const{
			return _data.back();
		}

		size_t size() const{
			return _size;
		}

		//Adding data to the data structure
		void push(T value){
			_data.push_back(value);
			_size += 1;	
		}

		//Removing data from the data structure
		void pop(){
			_data.pop_back();
			_size -= 1;
		}

		bool search(T value) {
			return _data.search(value);
		}


		bool empty() const{	
			return _data.empty();
		}

		void print(){
			//_data.print();
			std::cout << *this << std::endl;
		}

		//This overloaded operator is empty, please implement
		Stack<T> operator=(Stack<T> &stack) {
			_data = stack._data;
			return *this;
		}

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		/*	
		template <class S>
		friend bool operator==(Stack<S> &left_side, Stack<S> &right_side){
			if (left_side.size() == right_side.size()){
				if (left_side._data == right_side._data){
					return true;
				}
			}
			else{
				return false;
			}
		}*/
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};

//template <class T, class S>
template <class S>
std::ostream &operator<<(std::ostream &out, const Stack<S> &stack){
	for (auto j: stack._data){
		out << j << " ";
	}
	return out;
}
	
	
	/*List<T> _temp = stack._data;
	for (int i = 0; i < stack._size; i++){
		out << _temp.back() << " ";
		_temp.pop_back();
	}
	return out;*/

//}

