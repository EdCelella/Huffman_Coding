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