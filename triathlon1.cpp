#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("race-data.txt");
    ofstream outputFile("Athlete-results.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    outputFile << "Athlete Results\n";
    outputFile << "-------------------------\n";

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        char athlete;
        int running, swimming, biking, total;

        ss >> athlete >> running >> swimming >> biking;
        total = running + swimming + biking;

        outputFile << "Athlete " << athlete << ": Run " << running 
                   << " min, Swim " << swimming << " min, Bike " 
                   << biking << " min, Total " << total << " min\n";
    }

    cout << "Results saved to Athlete-results.txt" << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
