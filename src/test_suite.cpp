#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE huffman_test
#include <boost/test/unit_test.hpp>

#define private public
#include "huffman.h"

BOOST_AUTO_TEST_SUITE( huff_contructor_input )

	BOOST_AUTO_TEST_CASE( contructor_string ){
		std::string t = "test string";
		Huff t1(t);
		BOOST_CHECK(t1.input == "test string");
	}

	BOOST_AUTO_TEST_CASE( contructor_char ){
		char t = 'a';
		Huff t1(t);
		BOOST_CHECK(t1.input == "a");
	}

	BOOST_AUTO_TEST_CASE( contructor_char_array ){
		char t[] = "test char array";
		Huff t1(t);
		BOOST_CHECK(t1.input == "test char array");
	}

	BOOST_AUTO_TEST_CASE( contructor_int ){
		int t = 100;
		Huff t1(t);
		BOOST_CHECK(t1.input == "100");
	}

	BOOST_AUTO_TEST_CASE( contructor_double ){
		double t = 10.01;
		Huff t1(t);
		BOOST_CHECK(t1.input == "10.01");
	}

	BOOST_AUTO_TEST_CASE( contructor_float ){
		float t = 10.00001;
		Huff t1(t);
		BOOST_CHECK(t1.input == "10.00001");
	}

	BOOST_AUTO_TEST_CASE( contructor_bool ){
		bool t = true;
		Huff t1(t);
		BOOST_CHECK(t1.input == "1");
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( node_contructor )

	BOOST_AUTO_TEST_CASE( contructor_assign_char ){
		char t = 'a';
		int u = 1;
		Node t1(u, t);
		BOOST_CHECK(t1.c == t);
	}

	BOOST_AUTO_TEST_CASE( contructor_assign_freq ){
		char t = 'a';
		int u = 1;
		Node t1(u, t);
		BOOST_CHECK(t1.freq == u);
	}

	BOOST_AUTO_TEST_CASE( contructor_no_char ){
		int u = 1;
		Node t1(u);
		BOOST_CHECK(t1.c == '\0');
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( creating_nodes )

	BOOST_AUTO_TEST_CASE( count_string ){

		std::string test = "aaabbbcccd";
		int freq[4] = {3,3,3,1};
		std::list<Node*> testNodes;
		Huff t1(test);

		t1.genereateProbabilities(test, testNodes);

		BOOST_CHECK(testNodes.size() == 4);

		int j = 0;
		for(auto const& i : testNodes){
			BOOST_CHECK(i->freq == freq[j]);
			j++;
		}

	}

	BOOST_AUTO_TEST_CASE( empty_string ){
		std::string test = "";
		std::list<Node*> testNodes;
		Huff t1(test);
		t1.genereateProbabilities(test, testNodes);
		BOOST_CHECK(t1.treeNodes.size() == 0);
	}

	BOOST_AUTO_TEST_CASE( one_letter ){
		std::string test = "a";
		std::list<Node*> testNodes;
		Huff t1(test);
		t1.genereateProbabilities(test, testNodes);
		BOOST_CHECK(t1.treeNodes.size() == 0);
	}

	BOOST_AUTO_TEST_CASE( mix_letter ){
		std::string test = "abbcacbcda";
		int freq[4] = {3,3,3,1};
		std::list<Node*> testNodes;
		Huff t1(test);

		t1.genereateProbabilities(test, testNodes);

		BOOST_CHECK(testNodes.size() == 4);

		int j = 0;
		for(auto const& i : testNodes){
			BOOST_CHECK(i->freq == freq[j]);
			j++;
		}
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( node_sorter )

	BOOST_AUTO_TEST_CASE( reverse_order ){
		std::string test = "";
		std::list<Node*> testNodes;

		for(int i = 5; i > 0; i--){
			testNodes.push_back(new Node(i));
		}
		Huff t1(test);
		t1.sortNodes(testNodes);

		int j = 1;
		for(auto const& i : testNodes){
			BOOST_CHECK(i->freq == j);
			j++;
		}
	}

	BOOST_AUTO_TEST_CASE( empty ){
		std::string test = "";
		std::list<Node*> testNodes;
		Huff t1(test);
		t1.sortNodes(testNodes);
		int j = 1;
		for(auto const& i : testNodes){
			BOOST_CHECK(i->freq == j);
			j++;
		}
	}

	BOOST_AUTO_TEST_CASE( random_order ){
		std::string test = "";
		std::list<Node*> testNodes;
		testNodes.push_back(new Node(5));
		testNodes.push_back(new Node(2));
		testNodes.push_back(new Node(1));
		testNodes.push_back(new Node(3));
		testNodes.push_back(new Node(4));
		Huff t1(test);
		t1.sortNodes(testNodes);
		int j = 1;
		for(auto const& i : testNodes){
			BOOST_CHECK(i->freq == j);
			j++;
		}
	}

	BOOST_AUTO_TEST_CASE( negative_numbers ){
		std::string test = "";
		std::list<Node*> testNodes;
		for(int i = -5; i < 0; i++){
			testNodes.push_back(new Node(i));
		}
		Huff t1(test);
		t1.sortNodes(testNodes);
		int j = -5;
		for(auto const& i : testNodes){
			BOOST_CHECK(i->freq == j);
			j++;
		}
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( construct_tree )

	BOOST_AUTO_TEST_CASE( contruct_normal ){
		std::string test = "abbcacbcda";
		Huff t1(test);
		bool b = t1.createTree();

		BOOST_CHECK(t1.root->freq == 10);
		BOOST_CHECK(b == true);
	}

	BOOST_AUTO_TEST_CASE( contructor_empty ){
		std::string test = "";
		Huff t1(test);
		bool b = t1.createTree();

		BOOST_CHECK(b == false);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( code )

	BOOST_AUTO_TEST_CASE( input_normal ){

		std::string test = "abbcacbcda";
		Huff t1(test);
		t1.createTree();
		t1.getCode();

		std::string codeCheck[] = {"00", "01", "10", "11"};

		int j = 0;
		for(auto const& i : t1.codes){
			BOOST_CHECK(i.second == codeCheck[j]);
			j++;
		}

	}

	BOOST_AUTO_TEST_CASE( input_same ){
		
		std::string test = "aaa";
		Huff t1(test);
		t1.createTree();
		t1.getCode();

		std::string codeCheck = "";

		BOOST_CHECK(t1.codes.front().second == codeCheck);

	}


BOOST_AUTO_TEST_SUITE_END()





