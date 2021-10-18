
#include "DNode.hpp"
#include "Song.hpp"
#include "DLL.hpp"
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
				live->song->printSong();
				live = live->next;
			}
		}

		int DLL::remove(string t){
			DNode *song = first;

			if(song->song->title == t){
				cout<<"Removing:";
				song->song->printSong();
				song->next->prev = song ->prev;
				first = song->next;
				delete song;
				return 0;
			}

			while(song->next != NULL){
				cout<<"Removing:";
				song->song->printSong();
				song->prev->next = song->next;
				song->next->prev = song ->prev;
				delete song;
				return 0;
			}



			if(last->song->title == t){
				cout<<"Removing:";
				pop()->printSong();
				return 0;
			}

			cout<<"Remove Failed, "<< t << "not in list.";
			return -1;

		}

		Song *DLL::pop(){
			if(numSongs == 1){
				first = NULL;
				DNode *temp = last;
				Song *song = temp->song;
				last = last->prev;
				delete temp;
				last = NULL;
				return song;
			}
			else{
				DNode *temp = last;
				Song *song = temp->song;
				last = last->prev;
				delete temp;
				numSongs--;
				return song;
			}
		}

		void DLL::moveUp(string t){
			if(numSongs == 0){
				cout<<"List is empty"<<endl;
			}
			else{
				DNode *n = first;
				while(n != NULL){
					if(n->song->title == t){
					 if(n->prev == NULL){
						 first = n->next;
						 first->prev = NULL;
						 last->next = n;
						 n->prev = last;
						 last = n;
						 last->next = NULL;
						 break;
					 }
					 else if(n->next == NULL){
						 n->prev->prev->next = n;
						 last = n->prev;
						 n->prev->next = NULL;
						 n->next = n->prev;
						 n->prev = n->next->prev;
						 n->next->prev = n;
						 break;
					 }
					 else if(n->prev->prev == NULL){
						 n->prev->next = n->next;
						 n->next->prev = n->prev;
						 n->prev->prev = n;
						 n->next = n->prev;
						 n->prev = NULL;
						 first = n;
						 break;
					 }
					 else{
						 n->prev->prev->next = n;
						 n->next->prev = n->prev;
						 n->prev->next = n->next;
						 n->next = n->prev;
						 n->prev = n->prev->prev;
						 n->next->prev = n;
						 break;
					 }
				}
				n = n->next;
				}
			}
		}

		void DLL::moveDown(string t){
			if(numSongs == 0){
				cout<<"List is empty"<<endl;
			}
			else{
				DNode *n = first;
				while(n != NULL){
					if(n->song->title == t){
						if(n->prev == NULL){
							n->next->next->prev = n;
							first = n->next;
							first->prev = NULL;
							n->next = first->next;
							first->next = n;
							n->prev = first;
						}
						else if(n->next->next == NULL){
							n->prev->next = n->next;
							n->next->prev = n->prev;
							n->next->next = n;
							n->prev = n->next;
							last = n;
							n->next = NULL;
						}
						else if(n->next == NULL){
							 first->prev = n;
							 n->next = first;
							 first = n;
							 last = n->prev;
							 last->next = NULL;
							 n->prev = NULL;
						}
						else{
							n->prev->next = n->next;
							n->next->prev = n->prev;
							n->next = n->next->next;
							n->prev = n->next->prev;
							n->next->prev->next = n;
							n->next->prev = n;
						}
					}
					n = n->next;
				}
			}
		}

		void DLL::makeRandom(){
	           int num1 = 0;
	           int x = 0;
	           Song *s;
	           for(int i = 0; i < 2*numSongs; i++){
	               num1 = rand() % (2*numSongs) + 1;
	               x = 0;
	               s = first->song;
	               while(x < num1){
	                   DLL::moveDown(s->title);
	                   x++;
	               }
	           }


		}

		void DLL::listDuration(int *tm, int *ts){

			if(numSongs == 0){
				*tm = 0;
				*ts = 0;
			}
			else{
				DNode *n = first;
				while(n != NULL){
					*tm += n->song->min;
					*ts += n->song->sec;
					n = n->next;
				}
			}

		}

		DLL::~DLL(){
			while(first){
				cout<<"Deleting: "<< pop()->title<<endl;
			}
			first = NULL;
			last = NULL;

		}


