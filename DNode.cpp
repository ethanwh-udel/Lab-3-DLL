/*
 * DNode.cpp
 *
 *  Created on: Oct 13, 2021
 *      Author: harrisonlittlepage
 */

#include "DNode.hpp"
#include "song.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DNode::DNode(){
	song = NULL;
	next = NULL;
	prev = NULL;
}

DNode::DNode(string s, string a, int lenmin, int lensec){
	song = new song(string s, string a, int lenmin, int lensec);
	next = NULL;
	prev = NULL;
}


