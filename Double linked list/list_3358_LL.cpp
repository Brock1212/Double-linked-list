// File Name: list_3358_LL.cpp
//
// Author: Brock Yarbrough
// Date: 02/23/2015
// Assignment Number: 2
// CS 3358 Spring 2015
// Instructor: Jill Seaman
//
// holds the prototypes and definitions for the List_3358 class
// list can insert and remove nodes. Also move cursor.

#include "list_3358_LL.h"
#include<iostream>
#include<cassert>

using namespace std;


//***********************************************************
// List_3358::List_3358(): constructor that creates an empty list
//
// returns: nothing void
//***********************************************************
List_3358::List_3358()
{
  head = NULL;
  tail = NULL;
  cursor = NULL;
}


//***********************************************************
// List_3358::List_3358 ( const List_3358 & src ): copy constructor
//  that does a deep copy from the source list
// param-1 List_3358 & src: the source list to be copied.
//
// returns: nothing void
//***********************************************************
List_3358::List_3358 ( const List_3358 & src )
{
	 head = NULL;
	 tail = NULL;
	 cursor = NULL;
	 Node *p = src.head;
	 Node *n;
	 Node *holdcursor;
	    while (p)
	    {
	       insert(p->value);
	       if (src.cursor == p)
	       {
	    	   n = head;
	    	   while (n->next)
	    		   n = n->next;
	    	   holdcursor = n;
	       }
	       p = p->next;
	    }
    cursor = holdcursor;
}


//***********************************************************
// List_3358::~List_3358(): destructor that deletes all
// dynamically located memory
//
// returns: nothing void
//***********************************************************
List_3358::~List_3358()
{
	Node *p = head;
	Node *n;
	  while (p)
	  {
	      n = p->next;
	      delete p;
	      p = n;
	  }
}


//***********************************************************
// void List_3358::insert ( const int & item ): adds a new node
// to the list right before the cursor.
// param-1 const int & item: the item to be added to the list
//
// returns: nothing void
//***********************************************************
void List_3358::insert ( const int & item )
{
	assert (!isFull());

   Node *newnode = new Node;
   newnode->value = item;
   newnode->next = NULL;
   newnode->previous = NULL;

   if(head == NULL && tail == NULL)
   {
      head = newnode;
      tail = newnode;
   }
   else if ( cursor == head )
   {
      Node *P = head;
      P->previous = newnode;
      newnode->next = P;
      head = newnode;

   }
   else
   {
	   Node *p = head;
	   while (p->next != cursor)
	        p = p->next;
	   p->next = newnode;
	   newnode->next = cursor;
	   if (!atEOL())
	        cursor->previous = newnode;
	   else
		   tail = newnode;
	   newnode->previous = p;
   }



}


//***********************************************************
// void List_3358::remove(): removes the node being pointed to
//  by the cursor from the list
//
// returns: nothing void
//***********************************************************
void List_3358::remove()
{
	assert (!atEOL());
    assert (!isEmpty());

    Node *p = head->next;
    Node *n = head;

    if ( n == cursor)
    {
    	cursor = cursor->next;
        head = p;
        if (head != NULL)
        	p->previous = NULL;
        else
        	tail = NULL;
        delete n;
    }
    else
    {
       while (p != cursor)
       {
          n = p;
          p = p->next;
       }
       cursor = cursor->next;
       if (!atEOL())
          cursor->previous = n;
       else
    	   tail = n;
       n->next = cursor;
       delete p;
    }


}


//***********************************************************
// void List_3358::resetFront(): sets the cursor to the first node
// in the list
//
// returns: nothing void
//***********************************************************
void List_3358::resetFront()
{
  cursor = head;
}


//***********************************************************
// void List_3358::resetBack(): sets the cursor to the last node
// in the list
//
// returns: nothing void
//***********************************************************
void List_3358::resetBack()
{
cursor = tail;
}


//***********************************************************
// void List_3358::advance(): moves the cursor to the next node
// in the list
//
// returns: nothing void
//***********************************************************
void List_3358::advance()
{
  if (!atEOL())
	  cursor = cursor->next;
}


//***********************************************************
// void List_3358::backup(): moves the cursor to the previous node
// in the list
//
// returns: nothing void
//***********************************************************
void List_3358::backup()
{
  if (!atEOL())
     cursor = cursor->previous;
}


//***********************************************************
// bool List_3358::isEmpty() const: checks if there are any nodes
// in the list
//
// returns: True if there are no nodes in the list.
//***********************************************************
bool List_3358::isEmpty() const
{
	return head == NULL && tail == NULL;
}


//***********************************************************
// bool List_3358::atEOL() const: checks if the cursor is at
// the end of the list
//
// returns: true if the cursor is at EOL
//***********************************************************
bool List_3358::atEOL() const
{
	return cursor == NULL;
}


//***********************************************************
// bool List_3358::isFull() const: checks if the max amount of nodes
// has been reached
//
// returns: True if the list max has been reached
//***********************************************************
bool List_3358::isFull() const
{
	return false;
}


//***********************************************************
// int List_3358::getCurrent() const: gets the value currently
// being pointed to by the cursor
//
// returns: the value of the node being pointed to by the cursor
//***********************************************************
int List_3358::getCurrent() const
{
	assert (!atEOL());

  return cursor->value;
}




