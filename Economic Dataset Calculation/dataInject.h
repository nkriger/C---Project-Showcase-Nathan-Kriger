/*
Created by Nathan Kriger
Last Updated : December 14th 2024
*/


#ifndef DATAINJECT_H
#define DATAINJECT_H

#include <string>
#include <iostream>

//Struct to hold data on years n stuff
struct YearData {
    int year;
    double inflationRate;
    double unemploymentRate;

    YearData(int y, double inflation, double unemployment)
        : year(y), inflationRate(inflation), unemploymentRate(unemployment) {}
};

// class data with pub function
class DataInject {
public:
    // Constructor and destructor
    DataInject();
    ~DataInject();

    // Methods to load data and print results
    void loadData(const std::string& filename);
    void printData() const;
    bool analyzeData();
    void graphData() const;

private:
    // Node struct for a linked list 
    struct Node {
        YearData data;
        Node* next;

        Node(const YearData& data) : data(data), next(nullptr) {}
    };

    Node* head;  // no head?
};

#endif // DATAINJECT_H