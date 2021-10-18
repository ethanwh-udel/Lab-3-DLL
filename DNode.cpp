/*
 * DNode.cpp
 *
 *  Created on: Oct 17, 2021
 *      Author: harrisonlittlepage
 */


#include "DNode.hpp"
#include "Song.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DNode::DNode(){
	song = NULL;
	next = NULL;
	prev = NULL;
}

DNode::DNode(string s, string a, int lenmin, int lensec){
	song = new Song(s,a,lenmin,lensec);
	next = NULL;
	prev = NULL;
}


