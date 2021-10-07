void swap(int&,int&);

class Min_Heap {

private :
  
	int* arr;
	int capacity;
	int curSize;	

public :
	
  // Constructor
	Min_Heap(int capacity) {
		this->capacity = capacity;
		this->arr = new int[capacity];
		this->curSize = 0;
	}

	int get_size() {
		return curSize;
	}

  // function to get smallest value -> O(1)
	int get_min() {
		return arr[0];
	}

  // function to insert new element in heap -> O(LogN)
	void insert(int val) {
		arr[curSize] = val;

		int i = curSize;
		while(i > 0 and arr[(i-1)/2] > arr[i]) {
			swap(arr[i],arr[(i-1)/2]);
			i = (i - 1)/2;
		}
		curSize++;
	}

  // function to remove smallest element from heap -> O(LogN) 
	void remove_Min() {
		int curMin = arr[0];
		arr[0] = arr[curSize - 1];
		curSize--;
		heapify(0);
	}

  // function to retain heap property after deletion O(LogN) 
	void heapify(int idx) {
		int left_child = 2 * idx + 1;
		int right_child = 2 * idx + 2;
		int smallest = idx;
		
		if(left_child < curSize and arr[left_child] < arr[smallest]) smallest = left_child;
		if(right_child < curSize and arr[right_child] < arr[smallest]) smallest = right_child;
	
		if(smallest != idx) {
			swap(arr[smallest],arr[idx]);
			heapify(smallest);
		}
	}
};

void swap(int& a,int& b) {
	int temp = a;
	a = b;
	b = temp;
}
