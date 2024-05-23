//
// Created by doominik on 9.5.2024.
//

#ifndef NALOGA0802_NODE_H
#define NALOGA0802_NODE_H

template<typename T>
class Node {
T value;
Node<T> *next;
public:
    Node(T value, Node<T> *next) : value(value), next(next) {}

    T getValue() const {
        return value;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setValue(T value) {
        Node::value = value;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }
};


#endif //NALOGA0802_NODE_H
