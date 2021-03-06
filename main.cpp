#include <iostream>
#include <vector>
#include <regex>



template<typename T>
class Token {
public:
	T m_data;
	Token(T t) : m_data(t) {};
};

class Tree {
	template<typename T>
	class Node {
	public:
		Node* left{};
		Node* right{};
		Token<T> m_token{};
	};

public:
	Node<int>* root{};

	std::string getVarName(std::string::iterator it, std::string& expression) {
		std::string validSet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
		std::string::iterator itEnd = std::find_if(it, expression.end(), [validSet, expression](char& c) {
			return validSet.find(c) == expression.npos;
			}
		);
		std::string name{ it, itEnd };
		if (name[0] < 65 || name[0] > 122) {
			throw std::exception("[ERROR] Calculator::getDigit NOT a digit");
		}
		return name;
	}
	bool isChar(char ch) {
		return ch >= 65 && ch <= 122;
	}
	bool isDigit(char ch) {
		return (ch > 47 && ch < 58) || ch == '.';
	}
	double getDigit(std::string::iterator it, std::string& expression) {
		std::string validSet{ "0123456789." };
		std::string::iterator itEnd = std::find_if(it, expression.end(), [validSet, expression](char& c) {
			return validSet.find(c) == expression.npos;
			}
		);
		std::string name{ it, itEnd };
		std::regex twoDots("\.*\\.[0-9]*\\.");
		std::smatch m;
		if (name == "." || std::regex_search(name, m, twoDots)) {
			throw std::exception("[ERROR] [invalid input] invalid point in number");
		}
		return std::stod(name);
	}
	template<typename T>
	void tokenize(std::string& expression) {
		auto it{ expression.begin() };
		
		while (it != expression.end()) {
			std::vector<Token<T>> tokens;
			int operCounter{ 0 };
			int bracketCounter{ 0 };
			if (*it== ' ' || *it == '	') {
				++it;
				continue;
			}
			if (isChar(*it)) {
				tokens.push_back(Token(getVarName(it, expression)));
				++operCounter;
			}
			else if (isDigit(*it)) {
				(Token(getDigit(it, expression)));
				++operCounter;
			}
			//else if (isOper(*it)) {
			//	tokens.push_back(getOper(expression, strIndex));
			//	--operCounter;
			//}
			
		}

		////////////////////////////////////////////////
		//size_t strEnd{ expression.length() };
		//size_t strIndex{ 0 };
		//
		//while (strIndex < strEnd) {
		//	//pos = expression[strIndex];
		//	else if (isBracket(pos)) {
		//		pos == '(' ? ++bracketCounter : --bracketCounter;
		//		tokens.push_back(getOper(expression, strIndex));
		//	}
		//	else {
		//		throw std::exception("[ERROR] [invalid input] [invalid character] Calculator::GetTokens() ");
		//	}
		//	strIndex += tokens.back().m_str.length();
		//}
		//if (operCounter != 1 || bracketCounter != 0) {
		//	throw std::exception("[ERROR] [invalid input] [invalid character order] Calculator::GetTokens() ");
		//}
		////printTokens();
		//return tokens;
		////////////////////////////////////////////////
	}
	template<typename T>
	void Create(std::vector<Token<T>> tokens) {

	}
	template<typename T>
	void Insert(Token<T> token) {

	}
	template<typename T>
	void Delete(Token<T>& token) {

	}
	void Print() {

	}
};

int main() {
	Tree tree;
	std::string input{ "2 + 1" };
	
	tree.tokenize<Token<std::string>>(input);

	return 0;
}