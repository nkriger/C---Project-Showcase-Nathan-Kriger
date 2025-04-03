#include "dataInject.h"
#include <iostream>
#include <fstream>

using namespace std;

bool fileExists(const string &filename)
{
    ifstream file(filename);
    return file.good();
}

int main()
{
    DataInject data;

    cout << "Input Data FileName" << endl;
    string filename;
    cin >> filename;

    while (!fileExists(filename))
    {
        cout << "File not found. Please enter a valid file name:" << endl;
        cin >> filename;
    }

    data.loadData(filename); // input is now player input

    int choice;
    do
    {
        cout << "Choose an option:" << endl;
        cout << "1. Print Data" << endl;
        cout << "2. Analyze Data" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            data.printData(); // Print the data
            break;
        case 2:
            data.analyzeData(); // Analyze and print results
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
