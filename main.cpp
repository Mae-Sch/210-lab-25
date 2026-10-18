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

    cout << setw(15) << "Reading:";

    // testing reading for vector;
    auto VectReadStart = high_resolution_clock::now();
    vector<string> testVector;
    ifstream inFileVect("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFileVect, tempCode);
        testVector.push_back(tempCode);
    }
    inFileVect.close();
    auto VectReadEnd = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(VectReadEnd - VectReadStart);
    cout << setw(15) << duration.count();

    // testing reading for list
    auto ListReadStart = high_resolution_clock::now();
    list<string> testList;
    ifstream inFileList("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFileList, tempCode);
        testList.push_front(tempCode);
    }
    inFileList.close();
    auto ListReadEnd = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(ListReadEnd - ListReadStart);
    cout << setw(15) << duration.count();

    // testing reading for set
    auto SetReadStart = high_resolution_clock::now();
    set<string> testSet;
    ifstream inFileSet("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFileSet, tempCode);
        testSet.insert(tempCode);
    }
    inFileSet.close();
    auto SetReadEnd = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(SetReadEnd - SetReadStart);
    cout << setw(15) << duration.count() << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/