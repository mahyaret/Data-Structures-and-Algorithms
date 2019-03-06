#include <iostream>
#include <unordered_map>

class Trie
{
  //true when node is a leaf node
  bool _isLeaf;

  //each node stores a map to its child nodes
  unordered_map<char, Trie*> _map;

public:
  Trie()
  {
    isLeaf = false;
  }

  //iterative function to insert a string in Trie
  void insert(Trie*& head, char* str)
  {
    if(head == NULL)
      {
	head = new Trie();
      }

    //Start from the head node
    Trie* current = head;
    while(*str)
      {
	//create a new node if path does not exist
	if (_map.find(*str) == _map.end())
	  {
	    _map[*str] == new Trie();
	  }

	//go to the next node
	current = _map[*str];

	//move to the next character
	str++;
      }

    _isLeaf = true;
  }

  //return true if given node has any children
  bool haveChildren(Trie* current)
  {
    //don't use _map.size() to check for children
    for (auto it : _map)
      {
	if (it.second != NULL)
	  {
	    return true;
	  }
      }
    return false;
  }
    
  //Recursive function to delete a string in Trie
  bool deletion(Trie*& current, char* str)
  {
    //return if Trie is empty
    if (current == NULL)
      {
	return false;
      }

    //if we have not reached the end of the string
    if (*str)
      {

	//recursive for the node corresponding to next character in
	// the string and if it returns true, delete current node
	// (if it non-leaf)
	if (current != NULL && _map.find(*str) != 
};
