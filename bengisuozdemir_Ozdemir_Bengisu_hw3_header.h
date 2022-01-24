#ifndef bengisuozdemir_Ozdemir_Bengisu_hw3_header_h
#define bengisuozdemir_Ozdemir_Bengisu_hw3_header_h
/*
In this header, we have to perform all operations via the member 
functions of this class including the operations regarding the subsequence lists.

*/
#include <iostream>
#include <string>
using namespace std;

struct SubSeqNode
{
	int value;
	SubSeqNode * next;

	//default constructor
	SubSeqNode()
		:value(0), next(nullptr)
	{}
	//constructor
	SubSeqNode (int i,SubSeqNode *n)
		:value(i), next(n)
	{}
};

struct SubSeqHeadNode
{
	int size; // number of elements in the subsequence
	SubSeqNode * sHead; // head of the subsequence list
	SubSeqHeadNode * next;

	//default constructor
	SubSeqHeadNode()
		:size(0), sHead(nullptr), next(nullptr)
	{}
	//contructor
	SubSeqHeadNode (int i,SubSeqNode * s, SubSeqHeadNode *n)
		:size(i), sHead(s), next(n)
	{}
};

class SubSeqsList
{
public:
	SubSeqsList(); //default constructor that creates an empty list
	~SubSeqsList(); //destructer
	void Display(); //displays entire list
	bool AddList(int num); //adds number to the que to be inserted or not
	bool findToBeDeleted(int num); //finding the node location(s) of given number
	bool IsEmpty(); //to check whether a number already exists in the list

private:
	SubSeqHeadNode * hHead;
	SubSeqHeadNode * copyAndStore(SubSeqHeadNode*); //to copy a single pointer or a linked list, returns copied node(s)
	bool IsExists(int num); //to find whether a particular value exists in the data structure
	void DeleteSingleNode(SubSeqHeadNode * toBeDeleted); // to delete a single node via deleteSmallNode funciton
	void insertValues(int); //to insert values to the list
	SubSeqNode * LastNodeFinder(SubSeqHeadNode*); //returns the last node of given list
	void deleteSmallNode(SubSeqNode*); //to delete a single node and linking others
	bool isIncluded(SubSeqHeadNode* ptr, int num); //checking wheter a value is included in the list
	bool compare(SubSeqHeadNode*node1, SubSeqHeadNode *node2); //comparing two given lists for sorting purposes
	// any helper functions you see necessary
};

#endif bengisuozdemir_Ozdemir_Bengisu_hw3_header_h