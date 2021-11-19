#include <iostream>
#include <vector>

class Token {

};

class Tree {
	template<typename T>
	class Node {
	public:
		Node* left{};
		Node* right{};
		T m_value{};

	};

	Node<char>* root{};
public:

	void Create(std::vector<Token> tokens) {

	}
	void Insert() {

	}
	void Destroy() {

	}
	void Print() {

	}
};

int main() {
	
	
	


	return 0;
}