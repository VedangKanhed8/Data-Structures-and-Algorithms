vector<int> inorder(Node *root) {
	stack<Node*> stk;

	Node *cur = root;

	vector<int> res;
	while(stk.empty() == false || cur != nullptr) {
		while(cur != nullptr) {
			stk.push(cur);
			cur = cur->left;
		}

		cur = stk.top();

		stk.pop();
		
		res.push_back(cur->data);

		cur = cur->right;		
	}

	return res;
}
