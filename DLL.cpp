
#include "DNode.hpp"
#include "DLL.hpp"
#include "Song.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}

	void DLL::push(string t, string a, int m, int s){
		DNode *n = new DNode (t,a,m,s);

		if(first == NULL){
			first = n;
			last = n;

		}
		else{
			n->prev = last;
			last->next = n;
			last = n;
		}
		numSongs++;
	}

	void DLL::printList(void){
		DNode *live = first;

		while(live != NULL){
			live->printSong();
			live = live->next;
		}
	}

	int DLL::remove(string t) {

	}

	Song DLL::*pop() {

	}

	void DLL::moveUp(string t) {

	}

	void DLL::moveDown(string t) {

	}

	void DLL::makeRandom() {

	}

	void DLL::listDuration(int *tm, int *ts) {

	}

