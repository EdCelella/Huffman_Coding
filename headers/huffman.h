#include <iostream>
#include <string>
#include <list>
#include <utility> 

struct Node{

	public:
		char c;
		int freq;
		Node(unsigned int, char = '\0');
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;

};

class Huff{

	public:
		std::string input;

		Huff(std::string);
		Huff(char);
		Huff(char[]);
		Huff(int);
		template<typename T1>
		Huff(T1);

		bool createTree();
		void getCode();

		std::list<std::pair <char,std::string>> codes;

	private:
		std::list<Node*> treeNodes;
		Node* root = nullptr;

		static void genereateProbabilities(std::string, std::list<Node*>&);
		static void sortNodes(std::list<Node*>&);
		static void constructTree(Node*&, std::list<Node*>);
		static void generateCode(Node*, std::string, std::list<std::pair <char,std::string>>&);

};

template<typename T1>
Huff::Huff(T1 _input){
	input = std::to_string(_input);
	input.erase(input.find_last_not_of('0') + 1, std::string::npos);
}