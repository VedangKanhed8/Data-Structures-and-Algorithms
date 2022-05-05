vector<int> postorder(Node *root) {
	stack<Node*> stk1,stk2;
	stk1.push(root);

	while(stk1.empty() == false) {
		Node *cur = stk1.top();
		stk1.pop();
		stk2.push(cur);
		if(cur->left != nullptr) {
			stk1.push(cur->left);
		}
		if(cur->right != nullptr) {
			stk2.push(cur->right);
		}
	}

	vector<int> res;
	while(stk2.empty() == false) {
		res.push_back(stk2.top());
		stk2.pop();
	}
	
	return res;
}
