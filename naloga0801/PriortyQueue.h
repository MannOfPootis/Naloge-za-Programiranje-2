//
// Created by doominik on 9.5.2024.
//

#ifndef NALOGA0801_PRIORTYQUEUE_H
#define NALOGA0801_PRIORTYQUEUE_H


#include <vector>
#include <exception>
#include <stdexcept>
#include <sstream>
#include "Time.h" // Vključite razred Time, če ga potrebujete.
#include "utility"
#include "memory"

using namespace std;
enum class Priority {
    Low,
    High
};

template<typename A, typename T>
class PairD {
    T val;
    A priority;
public:
    PairD(T val, A priority) : val(val), priority(priority) {}

    T getVal() const {
        return val;
    }

    A getPriority() const {
        return priority;
    }
};


template<typename T>
class PriorityQueue {
public:
    // Vstavi element v vrsto s prioriteto.
    void add(const T &element, Priority priority) {

        if (priority == Priority::High) {
            values.insert(values.begin() + indexNextHigh, pair(Priority::High, element));
            indexNextHigh++;
        } else {
            values.push_back( pair(Priority::Low, element));
        }
    }

    pair<Priority, T> pop() {
        if (empty()) {
            throw out_of_range("empty lol");
        }
        pair<Priority, T> e = values[0];
        values.erase(values.begin());
        indexNextHigh -= (int) (indexNextHigh > 0);
        return e;
    }

    T getMax() const {
        if (empty())
            throw std::out_of_range("Index out of range for vector access.");
        T e = values[0].second;
        for (pair<Priority, T> t: values) {
            if (t.second > e)
                e = t.second;
        }
        return e;
    }

    std::string toString() const {
        stringstream ss;
        ss << "[ ";


        for (int i = 0; i < values.size(); i++) {
            std::string pr = "H";
            if (i == indexNextHigh) {
                pr = "L";
            }
            ss << values[i].second << pr << " ";

        }
        ss << "]";
        return ss.str();

    }

    // Preveri, ali je vrsta prazna.
    bool empty() const {
        return values.empty();
    }

private:
    vector<std::pair<Priority, T>> values;
    int indexNextHigh = 0;


    // Funkcija za iskanje indeksa elementa z najvišjo prioriteto.
    int findMaxIndex() const;
};

template<>
class PriorityQueue<shared_ptr<Time>> {
public:
    // Vstavi element v vrsto s prioriteto.
    void add(const shared_ptr<Time> &element, Priority priority) {

        if (priority == Priority::High) {
            values.insert(values.begin() + indexNextHigh, pair(Priority::High, element));
            indexNextHigh++;
        } else {
            values.insert(values.begin() + values.size(), pair(Priority::Low, element));
        }
    }

    pair<Priority, shared_ptr<Time>> pop() {
        if (empty()) {
            throw out_of_range("empty lol");
        }
        pair<Priority, shared_ptr<Time>> e = values[0];
        values.erase(values.begin());
        indexNextHigh -= (int) (indexNextHigh > 0);
        return e;
    }

    shared_ptr<Time> getMax() const {
        if (empty())
            throw std::out_of_range("Index out of range for vector access.");
        shared_ptr<Time> e = values[0].second;
        for (pair<Priority, shared_ptr<Time>> t: values) {
            if (t.second->greater(*e))
                e = t.second;
        }
        return e;
    }

    std::string toString() const {
        stringstream ss;
        ss << "[ ";


        for (int i = 0; i < values.size(); i++) {
            std::string pr = "H";
            if (i == indexNextHigh) {
                pr = "L";
            }
            ss << values[i].second << pr << " ";

        }
        ss << "]";
        return ss.str();

    }

    // Preveri, ali je vrsta prazna.
    bool empty() const {
        return values.empty();
    }

private:
    vector<std::pair<Priority, shared_ptr<Time>>> values;
    int indexNextHigh = 0;


    // Funkcija za iskanje indeksa elementa z najvišjo prioriteto.
    int findMaxIndex() const;
};


#endif //NALOGA0801_PRIORTYQUEUE_H
