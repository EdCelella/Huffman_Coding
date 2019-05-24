#include "huffman.h"

#ifndef UNIT_TEST

int main(){
	return 0;
}

#endif

Node::Node(unsigned int _freq, char _c){
	c = _c;
	freq = _freq;
}

Huff::Huff(std::string _input){
	input = _input;
}

Huff::Huff(char _input){
	input = _input; 
}

Huff::Huff(char _input[]){
	input = _input; 
}

Huff::Huff(int _input){
	input = std::to_string(_input);
}

bool Huff::createTree(){
	genereateProbabilities(this->input, this->treeNodes);
	sortNodes(this->treeNodes);
	return true;
}

void Huff::genereateProbabilities(std::string inputS, std::list<Node*> &nodeList){
	
	for(int i = 0; i < inputS.size(); i++){
		
		bool createNode = true;

		for(auto const& j : nodeList){
			if(j->c == inputS[i]){
				j->freq++;
				createNode = false;
			}
		}

		if(createNode){
			Node* newNode = new Node(1,inputS[i]);
			nodeList.push_back(newNode);
		}
		
	}

}

void Huff::sortNodes(std::list<Node*>& nodeList){
	nodeList.sort([](Node* lhs, Node* rhs) {return lhs->freq < rhs->freq;});
}