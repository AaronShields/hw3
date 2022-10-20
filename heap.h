#ifndef HEAP_H
#define HEAP_H
#pragma warning(suppress: 4101)
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : data(0), m_ary(m), comparator(c) {

    
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){
    data.clear();
  }

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item){
    data.push_back(item);
		shiftUp(size() - 1);
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
      if(data.size() == 0){
        return true;
      }
      return false;
  }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{
    return data.size() ;
  }

private:
  /// Add whatever helper functions and data members you need below
  int m_ary;
  vector<T> data;

  PComparator comparator;
  
  T deleteAt(int ind) {
		if (empty())
			throw std::domain_error("You can't remove any element due to the heap is empty.");
		else if (ind >= size()) {
			throw std::domain_error("Position out of range");
		}
		else {
			T elem = data[ind];
			data[ind] = data[data.size() - 1];
			data.pop_back();
			if (!empty() && ind < size()) shiftDown(ind);
			return elem;
		}
	}

int daryChild(int child, int d) {
		return m_ary * child + d;
	}
  int parent(int child) {
		return (child - 1) / m_ary;
	}

  void shiftUp(int i) {
		T elem = data[i];
		int place = i;
		while (place > 0 && comparator(elem, data[parent(place)])) {
			data[place] = data[parent(place)];
			place = parent(place);
		}
		data[place] = elem;
	}

void shiftDown(int i) {
		T elem = data[i];
		int place = i;
		int child; 
		bool end = false;
		while (daryChild(place, 1) <= size() && !end) {
			child = mostPriorityPosition(place);
			
			if (comparator(data[child], elem)) {
				data[place] = data[child];
				place = child;
			}
			else end = true;
		}
		data[place] = elem;
	}

  int mostPriorityPosition(int i) {
		int result = daryChild(i, 1);
		int d = 2;
		int pos = daryChild(i, d);
		while (d <= m_ary && pos < size()) {
			if (comparator(data[pos], data[result])) {
				result = pos;
			}
			pos = daryChild(i, d++);
		}
		return result;
	}

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
      return data[0];
  }
  

  

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");


  }else{
    deleteAt(0);
  }

  
	

}



#endif

