#include "dataInject.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Constructor and destructor
DataInject::DataInject() : head(nullptr) {}

DataInject::~DataInject() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Load data from a da file
void DataInject::loadData(const std::string& filename) {
    //make sure file opens
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    int year;
    double inflation;
    double unemployment;

    while (file >> year >> inflation >> unemployment) {
        //linked list to grab data and put it into teh struct
        YearData data(year, inflation, unemployment);
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    file.close();
}

// Print the loaded data to test if linked list works
void DataInject::printData() const {
    Node* current = head;
    while (current) {
        std::cout << "Year: " << current->data.year
                  << ", Inflation Rate: " << current->data.inflationRate
                  << "%, Unemployment Rate: " << current->data.unemploymentRate
                  << "%" << std::endl;
        current = current->next;
    }
}

// Analyze data to check the correlation between inflation and unemployment
bool DataInject::analyzeData(){
    Node* current = head;
    
    int corrYes = 0;
    int corrNo = 0;
    bool correlation = false;

    while(current && current->next){
        //check to see if the values are both increasing 
        if((current->data.inflationRate < current->next->data.inflationRate) && (current->data.unemploymentRate < current->next->data.unemploymentRate)){
            corrYes++;
        }
        //checks for if the values are both decreasing
        else if((current->data.inflationRate > current->next->data.inflationRate) && (current->data.unemploymentRate > current->next->data.unemploymentRate)){
            corrYes++;
        }
        //if they are not changing together put no
        else{
            corrNo++;
        }
        current = current->next;
    }
    cout << "Years with correlation: " << corrYes << "\n" <<
    "Years without correlation: " << corrNo << endl;
    
    if (corrNo/corrYes < .25) {//check to see if 80% of the time or more will they increase or decrease together
        std::cout << "Higher inflation correlates with higher unemployment" << std::endl;
        correlation = true;
    } else {// if the correlation is less than 80% its unlikely there is a real correlation between the 2 
        std::cout << "Higher inflation does not correlates with higher unemployment" << std::endl;
        correlation = false;
    }

    return correlation;
}


// data graph function to be contued
void DataInject::graphData() const {
    std::cout << "Graphing Data (Placeholder)" << std::endl;
    // to be written stuffs
}