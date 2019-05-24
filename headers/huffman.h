#include <iostream>
#include <string>
#include <list> 

struct Node{

	public:
		char c;
		int freq;
		Node(unsigned int, char = '\0');

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

	private:
		std::list<Node*> treeNodes;

};

template<typename T1>
Huff::Huff(T1 _input){
	input = std::to_string(_input);
	input.erase(input.find_last_not_of('0') + 1, std::string::npos);
}