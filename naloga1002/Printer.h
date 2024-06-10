//
// Created by doominik on 23.5.2024.
//

#ifndef NALOGA1002_PRINTER_H
#define NALOGA1002_PRINTER_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <cctype>

class Printer {
private:
    std::vector<std::string> queue;

public:
    // Metoda toString
    std::string toString() const {
        std::string result;
        for (const auto &item: queue) {
            result += item + "\n";
        }
        return result;
    }

    void print() {
        std::cout << toString();
        queue.clear();
    }

    void add(const char *value) {
        queue.push_back(std::string(value));
    }

    template<typename T>
    void add(T value) {
        queue.push_back(std::to_string(value));
    }

    void add(const std::string &value) {
        queue.push_back(value);
    }

    template<typename T>
    void add(const std::vector<T> &values) {
        for (const auto &value: values) {
            queue.push_back(std::to_string(value));
        }
    }

    void add(const std::vector<std::string> &values) {
        for (const auto &value: values) {
            queue.push_back(value);
        }
    }

    void remove(const std::function<bool(const std::string &)> &func) {
        for (int i = 0; i < queue.size();) {
            if (func(queue[i])) {
                queue.erase(queue.begin() + i);
            } else {
                i++;
            }
        }
    }

    void sort(const std::function<bool(const std::string &, const std::string &)> &func) {
        for(int i=1;i!=0;i=0){
            for(int j=0;j<queue.size()-1;j++){
                if(func(queue[j],queue[j+1])){
                    std::string  temp=queue[j];
                    queue[j]=queue[j+1];
                    queue[j+1]=temp;
                    i++;
                }
            }
        }
    }

    void checkAndCorrect(const std::function<bool(const std::string &)> &checkFunc,
                         const std::function<void(std::string &)> &correctFunc) {
        for (auto &item: queue) {
            if (checkFunc(item)) {
                correctFunc(item);
            }
        }
    }

    void findAndReplace(const std::string &find, const std::string &replace) {
        for (auto &item: queue) {
            size_t pos = 0;
            while ((pos = item.find(find, pos)) != std::string::npos) {
                item.replace(pos, find.length(), replace);
                pos += replace.length();
            }
        }
    }

    // Dodatna metoda unique, ki odstrani podvojene elemente v queue
    void unique() {
        for(int i=0;i<queue.size();i++){
            bool nov=true;
            for(int j=0;j<queue.size();j++) {
                if (queue[j] == queue[i]) {
                    nov== false;
                    if(!nov){
                        queue.erase(queue.begin()+j);
                        j--;
                    }
                }
            }
        }
    }

    template<class T>
    bool contains(T sus){
        for(int i =0;i<queue.size();i++){
            if(sus==queue[i]){
                return true;
            }
        }
        return false;

    }
    template<typename T, typename ... Args>
    bool contains(T sus, Args... bomb){

        return (contains(sus)&&contains(bomb...));

    }
};


#endif //NALOGA1002_PRINTER_H
