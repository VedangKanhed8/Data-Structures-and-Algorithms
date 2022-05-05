vector<int> preorder(Node *root) {
	stack<Node*> stk;

	Node *cur = root;

	vector<int> res;
	while(stk.empty() == false || cur != nullptr) {
		while(cur != nullptr) {
			res.push_back(cur->data);
			if(cur->right != nullptr) {
        stk.push(cur->right);
      }
      cur = cur->left;		
		}

		if(stk.empty() == true) {
			cur = stk.top();
			stk.pop();
		}
	}

	return res;
}
