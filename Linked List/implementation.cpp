template<typename T>
class LinkedList {
private:
	struct ListNode {
		T data;
		ListNode *next;

		ListNode() {
			this->data = data;
			this->next = NULL;
		}

		ListNode(T data,ListNode *next) {
			this->data = data;
			this->next = next;
		}
	};

public:
	ListNode *head,*tail;
	LinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	void insertAtTail(T data) {
		ListNode *newNode = new ListNode(data,NULL);
		if(this->head == NULL) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = tail->next;
		}
	}

	void insertAtStart(T data) {
		ListNode *newNode = new ListNode(data,head);
		head = newNode;
	}

	void eraseHead() {
		ListNode *newHead = this->head->next;
		delete head;
		head = newHead;		
	}

	void erase(T data) {
		ListNode *cur = this->head;
		ListNode *prev = NULL;

		while(cur != NULL) {
			if(cur->data == data) {
				if(cur == head) {
					eraseHead();
				} 
				else {
					if(cur == tail) {
						tail = prev;
					}
					prev->next = cur->next;
					delete cur;
					return;
				}
			}
			prev = cur;
			cur = cur->next;
		}			
	}

	ListNode* reverse(ListNode *head) {
		if(head == NULL || head->next == NULL) {
			swap(this->head,this->tail);
			return head;
		}
		ListNode *revRest = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return revRest;
	}

	int getLength(ListNode *cur) {
		if(cur == NULL) return 0;
		return 1 + getLength(cur->next);
	}
	
	void printList() {
		for(ListNode *p = head ; p != NULL ; p = p->next) {
			cout << p->data << ' ';
		}
		cout << endl;
	}
};
