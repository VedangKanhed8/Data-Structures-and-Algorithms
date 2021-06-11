class circularQueue {
private : 
	int* arr;
	int maxCap; // stores max Capacity 
	int curCnt; // gives count of elements present in queue
	int front,rear; // used for pop and push respectively

public :
	// constructor to initialize array
	circularQueue(int maxCap) {
		this->arr = new int[maxCap];
		this->maxCap = maxCap;
		front = rear = curCnt = 0;
	}

	void push(int val); // this pushes val in queue

	bool isEmpty(); // returns true if queue is empty

	bool isFull(); // returns true if queue is full

	int pop(); // deletes front of queue and returns it
	
};

// Time : O(1)
bool circularQueue:: isEmpty() {
	// if curCnt is null , queue is empty
	return (curCnt == 0);
}

// Time : O(1)
bool circularQueue:: isFull() {
	// if curCnt is equal to max Capacity , queue is full
	return (curCnt == maxCap);	
}

// Time : O(1)
void circularQueue:: push(int data) {
	// if queue is full we can't push it
	if(this->isFull()) return;
	this->arr[rear % maxCap] = data;
	rear++;
	curCnt++;
}

// Time : O(1)
int circularQueue:: pop() {
	// if queue is empty , we can't pop
	if(this->isEmpty()) return -1;
	int frontVal = this->arr[front % maxCap];
	front++;
	curCnt--;
	return frontVal; 
}
