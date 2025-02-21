#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <random>

#include "AVLTree.h"

// uncomment and replace the following with your own headers
// #include "AVL.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Example Test Name - Change me!", "[flag]"){
	// instantiate any class members that you need to test here
	int one = 1;

	// anything that evaluates to false in a REQUIRE block will result in a failing test 
	REQUIRE(one == 0); // fix me!

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(false); // also fix me!
}

TEST_CASE("Test 2", "[flag]"){
	// you can also use "sections" to share setup code between tests, for example:
	int one = 1;

	SECTION("num is 2") {
		int num = one + 1;
		REQUIRE(num == 2);
	};

	SECTION("num is 3") {
		int num = one + 2;
		REQUIRE(num == 3);
	};

	// each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

TEST_CASE("Example BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
}

TEST_CASE("Incorrect inserts","[flag]")
{
	AVLTree t;

	bool inserted = t.insert(1, "_joe") && t.insert(2, "jo3")  && t.insert(3,"&sal") && t.insert("98273873837", "joe") && t.insert(1, "joe 💻");

	REQUIRE(!inserted);
}

TEST_CASE("Insert and rotation","[flag]")
{
	Student joe(1, "joe smith");
	Student jim(2, "jimmy john");
	Student john(3, "johnny jim");
	SECTION("Left rotation")
	{
		AVLTree t;
		bool inserted = t.insert(&joe) && t.insert(&jim) && t.insert(&john);
		REQUIRE(t.isBalanced()); //return true if balance factor is within [-1,1]
		REQUIRE(inserted);
	};

	SECTION("Right rotation")
	{
		AVLTree t;
		bool inserted = t.insert(&john) && t.insert(&jim) && t.insert(&joe);
		REQUIRE(t.isBalanced()); //return true if balance factor is within [-1,1]
		REQUIRE(inserted);
	};

	SECTION("Left right rotation")
	{
		AVLTree t;
		bool inserted = t.insert(&john) && t.insert(&joe) && t.insert(&jim);
		REQUIRE(t.isBalanced()); //return true if balance factor is within [-1,1]
		REQUIRE(inserted);
	};

	SECTION("Right left rotation")
	{
		AVLTree t;
		bool inserted = t.insert(&joe) && t.insert(&john) && t.insert(&jim);
		REQUIRE(t.isBalanced()); //return true if balance factor is within [-1,1]
		REQUIRE(inserted);
	};
}

TEST_CASE("100 nodes test", "[flag]")
{
	std::vector<Student> expectedOutput, actualOutput;
	AVLTree t;

	for(int i = 0; i < 100; i++)
	{
		int randomInput = rand();
		Student* input = new Student(randomInput, "joe");
		if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
		{
			expectedOutput.push_back(*input);
			t.insert(input);
		}
	}

	actualOutput = t.inorder();
	std::sort(expectedOutput.begin(), expectedOutput.end());
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(expectedOutput == actualOutput);

	//test removals
	t.removeID(expectedOutput[0].ID);
	t.removeID(expectedOutput[1].ID);
	t.removeID(expectedOutput[2].ID);
	t.removeID(expectedOutput[3].ID);
	t.removeID(expectedOutput[4].ID);
	t.removeID(expectedOutput[5].ID);
	t.removeID(expectedOutput[6].ID);
	t.removeID(expectedOutput[7].ID);
	t.removeID(expectedOutput[8].ID);
	t.removeID(expectedOutput[9].ID);

	expectedOutput.erase(expectedOutput.begin(), expectedOutput.begin() + 10);

	actualOutput = t.inorder();

	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(expectedOutput == actualOutput);
}

TEST_CASE("search test", "[flag]")
{
	AVLTree t;
	Student s(1, "john");
	t.insert(&s);
	REQUIRE(t.searchName("john"));
	REQUIRE(t.searchID(1));
}

TEST_CASE("test balance", "[flag]")
{
	AVLTree t;

	SECTION("empty tree")
	{
		REQUIRE(t.height() == 0);
	}
	SECTION("tree with 1 student")
	{
		Student n(1,"n");
		t.insert(&n);
		REQUIRE(t.height() == 1);
	}
	SECTION("tree with multiple students")
	{
		Student a(1, "a");
		Student b(2, "b");
		Student c(3, "c");
		Student d(4, "d");
		Student e(5, "e");

		t.insert(&a);
		t.insert(&b);
		t.insert(&c);
		t.insert(&d);
		t.insert(&e);

		REQUIRE(t.height() == 3);
	}
}