#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace std::chrono;

const int NUM_CODES = 20000;

int main() {

    cout << "All times are measured in milliseconds\n\n";
    cout << setw(15) << " "<< setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set" << endl;

    /// *** Reading Tests *** ///

    out << setw(15) << "Reading:";

    // testing reading for vector;
    auto start = high_resolution_clock::now();
    vector<string> testVector
    ifstream inFile("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFile, tempCode);
        testVector.push_back(tempCode);
    }
    inFile.close();
    auto end = high_resolution_clock::now()
    auto duration = duration_cast<milliseconds>(end - start);
    cout << setw(15) << duration.count();

    // testing reading for list
    auto start = high_resolution_clock::now();
    list<string> testList
    ifstream inFile("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFile, tempCode);
        testList.push_front(tempCode);
    }
    inFile.close();
    auto end = high_resolution_clock::now()
    auto duration = duration_cast<milliseconds>(end - start);
    cout << setw(15) << duration.count();

    // testing reading for set
    auto start = high_resolution_clock::now();
    set<string> testSet
    ifstream inFile("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFile, tempCode);
        testSet.insert(tempCode);
    }
    inFile.close();
    auto end = high_resolution_clock::now()
    auto duration = duration_cast<milliseconds>(end - start);
    cout << setw(15) << duration.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/