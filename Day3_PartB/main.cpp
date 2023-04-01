#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char findSharedItemType(string firstElf, string secondElf, string thirdElf){
    char sharedItemType = 0;
    int compartmentSize = firstElf.length();

    for (int i = 0; i < compartmentSize; i++){
        char item = firstElf[i];
        if(secondElf.find(item) != string::npos and thirdElf.find(item) != string::npos){
            sharedItemType = item;
            break;
        }
    }
    
    return sharedItemType;
}

//This function will calculate the distance between two chars
//then use that to calculate the priority
int priorityCalculate(char sharedItemType){
    if (sharedItemType >= 'a' && sharedItemType <= 'z') {
        return sharedItemType - 'a' + 1;
    }
    if (sharedItemType >= 'A' && sharedItemType <= 'Z') {
        return sharedItemType - 'A' + 27;
    }
    return 0;
}

int main(){
    ifstream data("input.txt");
    string line;
    string firstElf, secondElf, thirdElf;
    int sumOfPriority = 0;
    
    while(getline(data, firstElf) and getline(data, secondElf) and getline(data, thirdElf)){
            sumOfPriority += priorityCalculate(findSharedItemType(firstElf, secondElf, thirdElf));
    }
    
    cout << sumOfPriority << endl;
    
    return 0;
}