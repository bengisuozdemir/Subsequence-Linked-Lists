#include "bengisuozdemir_Ozdemir_Bengisu_hw3_header.h"

SubSeqsList::SubSeqsList()
{
	hHead = NULL;
}
SubSeqsList::~SubSeqsList()
{//destructer
	SubSeqHeadNode * copy= hHead;
	SubSeqNode * ptr;
	SubSeqNode * ptr2;
	while(copy != NULL)
	{
		ptr = hHead->sHead;
		ptr2=ptr;
		while(ptr != NULL)
		{
			ptr = ptr->next;
			delete ptr2;
			ptr2 = ptr;
		}
		copy = copy->next;
		delete hHead;
		hHead = copy;
	}
}
void SubSeqsList::Display()
{//Pre:No additional parameter, only using hHead pointer
	SubSeqHeadNode* printCopyHeadNode = hHead;
	SubSeqNode* printCopyNode = NULL;
	while(printCopyHeadNode != NULL)
	{
		cout << printCopyHeadNode->size << " | ";
		printCopyNode = printCopyHeadNode->sHead;
		cout << printCopyNode->value;
		printCopyNode = printCopyNode->next;
		while(printCopyNode != NULL)
		{
			cout << " --> " << printCopyNode->value;
			printCopyNode = printCopyNode->next;
		}
		cout << endl;
		printCopyHeadNode = printCopyHeadNode->next;
	}
}//Post:Printing the linked list as intended format

bool SubSeqsList::AddList(int num)
{//pre:using the inputted integer and hHead pointer
	SubSeqHeadNode* ptr = hHead; //Equating hHead to a temporary pointer while wr are changing it
	if(IsEmpty())
	{   //if linked list is empty initially, repalce the first num to first location, and return true. 
		hHead = new SubSeqHeadNode(1, new SubSeqNode(num, NULL), NULL);
		return true;
	}
	else
	{   //else implement functions by copying the existing values to a temporary subseqheadnode and subseqnode
		//check if the new value existed before in the list
		if(IsExists(num))
		{
			return false;
		}
		else
		{
			insertValues(num);
			return true;
		}
	}
}//post:if hHead pointer points nothing (nullptr) creating the first new node, else regarding what is the number inserting number(s) to new nodes.
bool SubSeqsList::IsExists(int num)
{//aim: checking whether the new num existed in the list
	SubSeqHeadNode * node = hHead;
	while(node != NULL)
	{
		SubSeqNode * ptr = node->sHead; 
		while(ptr!=NULL)
		{
			if(ptr->value == num)
			{   //if the num exists return true
				return true;
			}
			ptr = ptr->next;
		}
		node = node->next;
	}
	return false;
}
bool SubSeqsList::findToBeDeleted(int numToBeDelete)
{//aim: finding nodes to be deleted and sending its location to the DeleteSingleNode function to be delete. 
	SubSeqHeadNode* ptr = hHead;
	bool check = false;
	while(ptr!=NULL)
	{
		if(isIncluded(ptr,numToBeDelete))
		{
			DeleteSingleNode(ptr);
			check = true;
			ptr = hHead;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	return check;
}
void SubSeqsList::DeleteSingleNode(SubSeqHeadNode * toBeDeleted)
{//modified by Bengisu Özdemir, deleting desired nodes:
	//Begin: code is taken from 2.2-pointers-linkedlists.ppt
	SubSeqHeadNode * ptr;
	if(toBeDeleted == hHead)
	{
		hHead = hHead->next;
		deleteSmallNode(toBeDeleted->sHead);
		delete toBeDeleted;
		
	}
	else
	{
		ptr = hHead;
		while(ptr->next != toBeDeleted)
		{ ptr = ptr->next; }
		ptr->next = toBeDeleted->next;
		deleteSmallNode(toBeDeleted->sHead);
		delete toBeDeleted;	
	}
	//End: code is taken from 2.2-pointers-linkedlists.ppt
}
void SubSeqsList::deleteSmallNode(SubSeqNode * node)
{//aim: deleting a single node and linking the others
	SubSeqNode *itr=node;
	while(itr != nullptr)
	{
		itr=itr->next;
		delete node;
		node = itr;
	}
}
bool SubSeqsList::IsEmpty()
{//aim: to check whether a list is empty
	if(hHead == nullptr)
	{
		return true;
	}
	return false;
}
SubSeqNode * SubSeqsList::LastNodeFinder(SubSeqHeadNode * initialNode)
{//aim: to find the last npode of the given linked list
	SubSeqNode * ptr = initialNode->sHead;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	return ptr;
}
void SubSeqsList::insertValues(int num)
{//aim: by using the information from the AddList function, inserting values to suitable locations of nodes
	SubSeqHeadNode * ptr;
	SubSeqHeadNode * n;
	SubSeqHeadNode * copy;
	SubSeqNode * last;
	SubSeqHeadNode * itrHead = hHead;
	ptr = new SubSeqHeadNode(1, new SubSeqNode(num, NULL), NULL);
	if(itrHead->sHead->value >num)
	{
		ptr->next = itrHead;
		hHead = ptr;
	}
	else
	{
		while(itrHead->next != NULL&& itrHead->next->size == 1 &&itrHead->next->sHead->value < num)
		{
			itrHead=itrHead->next;
		}
		SubSeqHeadNode * temp = itrHead->next;
		itrHead->next = ptr;
		ptr->next = temp;
	}
	itrHead = hHead;
	while(itrHead != NULL)
	{
		if(!isIncluded(itrHead,num)&&LastNodeFinder(itrHead)->value<num)
		{
			copy = copyAndStore(itrHead);
			last = LastNodeFinder(copy);
			last->next = new SubSeqNode(num, NULL);
			copy->size++;
			n = hHead;
			while(n->next != NULL && n->next->size < copy->size)
			{
				n = n->next;
			}
			while(n->next != NULL &&compare(n->next, copy)&& n->next->size <= copy->size)
			{
				n=n->next;
			}
			SubSeqHeadNode * temp = n->next;
			n->next = copy;
			copy->next = temp;
		}
		itrHead = itrHead->next;
	}
}//post: linked list has formed
bool SubSeqsList::isIncluded(SubSeqHeadNode* currentptr, int num)
{//aim: checking wheter a single value is included within given list
	SubSeqNode * ptr = currentptr->sHead;
	while(ptr!=NULL)
	{
		if(ptr->value==num)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}
bool SubSeqsList::compare(SubSeqHeadNode*toBeSearched, SubSeqHeadNode * newNode)
{//aim: to compare two lists to be sorted
	SubSeqNode * ptr = newNode->sHead;
	SubSeqNode * itr = toBeSearched->sHead;
	while(ptr!=	NULL)
	{
		if(ptr->value > itr->value)
		{
			return true;
		}
		else if(ptr->value < itr->value)
		{
			return false;
		}
		else
		{
			ptr= ptr->next;
			itr = itr->next;
		}
	}
}
SubSeqHeadNode * SubSeqsList::copyAndStore(SubSeqHeadNode * nodeToCopy)
{//aim: to copy given node(s), returns copied version of given node
	SubSeqHeadNode * copiedNode = new SubSeqHeadNode(nodeToCopy->size, new SubSeqNode(nodeToCopy->sHead->value, NULL), NULL);
	SubSeqNode * tempNode = nodeToCopy->sHead->next;
	SubSeqNode * itrnode = copiedNode->sHead;
	while(tempNode!=NULL)
	{
		itrnode->next = new SubSeqNode(tempNode->value, NULL);
		tempNode = tempNode->next;
		itrnode = itrnode->next;
	}
	return copiedNode;
}
