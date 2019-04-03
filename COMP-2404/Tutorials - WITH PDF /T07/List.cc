#include<iostream>
using namespace std;

#include "List.h"

List::List(){
    head = NULL;
}

List::~List(){
    Node* currNode; 
    Node* nextNode;

    currNode = head;

    while(currNode != NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
} 

void List::add(Book* kitaab)
{
    Node* currNode;
    Node* tmpNode;
    Node* prevNode;

    tmpNode = new Node();
    tmpNode->data = kitaab;
    tmpNode->prev = NULL;
    tmpNode->next = NULL;

    currNode = head;
    prevNode = NULL;

    while(currNode != NULL){
        if(kitaab->lessThan(currNode->data))
            break;
        prevNode = currNode;
        currNode = currNode->next;
    }
    if(prevNode == NULL){
        head = tmpNode;
    }
    else{
        prevNode->next = tmpNode;
    }
    if(currNode != NULL){
        currNode->prev = tmpNode;
    }

    tmpNode->next = currNode;
   // currNode->prev = tmpNode;
    tmpNode->prev = prevNode;
}

void List::print(){
    Node* currNode = head;
    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}
