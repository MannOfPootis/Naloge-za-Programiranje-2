//
// Created by doominik on 9.5.2024.
//

#ifndef NALOGA0802_CIRCULARLINKEDLIST_H
#define NALOGA0802_CIRCULARLINKEDLIST_H
#include "Node.h"
#include <stdexcept>
template<typename T>
class CircularLinkedList {
 Node<T> head;
public:
    bool isEmpty(){
        return head.getNext()== nullptr;
    }
    int sizeSlow(){
        if(isEmpty())
            return 0;//ouch
        Node<T> *crawlr=&head;
        int i=0;
        for(;crawlr->getNext()!=&head;crawlr=crawlr->getNext()){
            i++;
        }
        return i;


    }
    CircularLinkedList(): head(Node((T)0,(Node<T>*) nullptr)){

    }
    Node<T>* Eat(Node<T>* meal,Node<T>* except){
        if(meal->getNext()==except){
            return meal;
        }
        delete Eat(meal->getNext(),except);

    }
    virtual ~CircularLinkedList() {

        delete Eat(&head,&head);//funny

    }
    void add(T t){
        if(head.getNext()== nullptr){
            head= Node(t,&head);
            return;
        }
        for(Node<T> *crawlr=head.getNext(); true;crawlr=crawlr->getNext()){
            if(crawlr->getNext()==&head) {
                crawlr->setNext(new Node(t, &head));
                return;
            }
        };
    }
    void insertBefore(T node,T newNode){
        int i =0;
        int size=sizeSlow()+1;
        /*if(newNode==head.getValue()){
            head.setNext(&head);
            head.setValue(newNode);
            return;
        }*/
        for(Node<T> *crawlr=&head; /*crawlr!=head.getNext()*/true;crawlr=crawlr->getNext()){
            if(crawlr->getNext()->getValue()==node) {
                Node<T> *box= crawlr->getNext();
                crawlr->setNext(new Node(newNode,crawlr->getNext()));
                return;
            }
            i++;
        };
        throw std::invalid_argument("not in array");
    }
    T at(int dex){
        //return head.getNext()->getValue();
        Node<T> *crawlr=&head;
        for(int i=0;/*crawlr->getNext()!=&head*/true;crawlr=crawlr->getNext()){
            if(i==dex)
                return crawlr->getValue();
            i++;
        }
        throw std::out_of_range("out of range of linked list");
    }

};


#endif //NALOGA0802_CIRCULARLINKEDLIST_H
