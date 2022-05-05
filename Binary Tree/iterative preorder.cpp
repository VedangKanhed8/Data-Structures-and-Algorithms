vector<int> preorder(Node *root) {
	stack<Node*> stk;
	stk.push(root);

	vector<int> res;
	while(stk.empty() == false) {
		Node *cur = stk.top();
		stk.pop();

		if(cur->right != nullptr) {
			stk.push(cur->right);
		}

		if(cur->left != nullptr) {
			stk.push(cur->left);
		}
	}

	return res;
}
