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

Huff::~Huff(){

	if (root != nullptr) destructor_rec(root);
	else{
		std::list<Node*>::iterator it;
		for (it = this->treeNodes.begin(); it != this->treeNodes.end(); ++it){
			delete *it;
		}
	}
	this->treeNodes.clear();
	
}

void Huff::destructor_rec(Node*& currentNode){
	if(currentNode != nullptr){
		destructor_rec(currentNode->leftChild);
		destructor_rec(currentNode->rightChild);
		delete currentNode;
	}
}

bool Huff::createTree(){
	if (this->input == "") return false;
	genereateProbabilities(this->input, this->treeNodes);
	sortNodes(this->treeNodes);
	constructTree(this->root, this->treeNodes);
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

void Huff::constructTree(Node*& root, std::list<Node*> treeNodes){

	while(treeNodes.size() > 1){

		Node* minNode1 = treeNodes.front();
		treeNodes.pop_front();

		Node* minNode2 = treeNodes.front();
		treeNodes.pop_front();

		Node* parentNode = new Node(minNode1->freq + minNode2->freq);

		parentNode->leftChild = minNode1;
		parentNode->rightChild = minNode2;

		treeNodes.push_front(parentNode);

		sortNodes(treeNodes);

	}

	if(treeNodes.size() == 1){
		root = *treeNodes.begin();
	}
	

}

void Huff::getCode(){
	generateCode(this->root, "", this->codes);
}

void Huff::generateCode(Node* currentNode, std::string code, std::list<std::pair <char,std::string>>& codes){
	
	if(currentNode->c != '\0'){
		codes.push_back(std::pair<char,std::string>(currentNode->c, code));
	}

	if(currentNode->leftChild != nullptr){
		generateCode(currentNode->leftChild, code + "0", codes);
	}

	if(currentNode->rightChild != nullptr){
		generateCode(currentNode->rightChild, code + "1", codes);
	}

}


