#include<vector>

class MinStack {
private:
	std::vector<std::pair<int, int >> m_stack;
public:
	MinStack() {

	}

	void push(int val) {
		if (m_stack.empty() || val < m_stack.back().second)
			m_stack.push_back({ val,val });
		else
			m_stack.push_back({ val,m_stack.back().second });
	}

	void pop() {
		m_stack.pop_back();
	}

	int top() {
		return m_stack.back().first;
	}

	int getMin() {
		return m_stack.back().second;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */