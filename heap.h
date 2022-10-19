#ifndef HEAP_H
#define HEAP_H
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
  Heap(int m=2, PComparator c = PComparator()) : comparator(c){

    //data.resize(m);
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
     length++;
      if (length <= data.size())
      data[length-1] = item;
      else 
      data.push_back(item);
      fix_up(length - 1);

      
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
    return length ;
  }

private:
  /// Add whatever helper functions and data members you need below
  vector<T> data;
  int length;
  PComparator comparator;
  static int left(int i) { return 2*i + 1;}
	static int right(int i) { return 2*i + 2;}
	static int parent(int i) { return (i-1)/2;}

  void fix_up(int i)
	{
	  for (int j = parent(i); (j>=0) && comparator(data[j], data[i]); i=j,j=parent(i))
		swap(data[i], data[j]);
	}

  void fix_down(int i)
	{
	  T tmp = data[i];
	  int j = left(i);

	  while (j < length) {
		if(j+1 < length && comparator(data[j], data[j+1])) j++;
		
		if (comparator(tmp, data[j])) {
		  data[i] = data[j];
		  i = j;
		  j = left(i);
		} else {
		  break;
		}
	  }
	  data[i] = tmp;
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

  return data[0];

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


  }

  swap(data[0], data[--length]);
	fix_down(0);
	

}



#endif

