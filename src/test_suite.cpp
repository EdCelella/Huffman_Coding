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

		Huff t1(test);
		t1.createTree();

		BOOST_CHECK(t1.treeNodes.size() == 4);

		int j = 0;
		for(auto const& i : t1.treeNodes){
			BOOST_CHECK(i->freq == freq[j]);
			j++;
		}

	}

	BOOST_AUTO_TEST_CASE( empty_string ){
		std::string test = "";
		Huff t1(test);
		t1.createTree();
		BOOST_CHECK(t1.treeNodes.size() == 0);
	}

	BOOST_AUTO_TEST_CASE( one_letter ){
		std::string test = "a";
		Huff t1(test);
		t1.createTree();
		BOOST_CHECK(t1.treeNodes.size() == 1);
	}

	BOOST_AUTO_TEST_CASE( mix_letter ){
		std::string test = "abbcacbcda";
		int freq[4] = {3,3,3,1};

		Huff t1(test);
		t1.createTree();

		BOOST_CHECK(t1.treeNodes.size() == 4);

		int j = 0;
		for(auto const& i : t1.treeNodes){
			BOOST_CHECK(i->freq == freq[j]);
			j++;
		}
	}

BOOST_AUTO_TEST_SUITE_END()