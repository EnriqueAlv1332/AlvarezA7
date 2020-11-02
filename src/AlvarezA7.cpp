//============================================================================
// Name        : AlvarezA7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct EmployeeData
{
	char ID[10] = {0} ;
	string fName = {""};
	string lName = {""};
};

struct tableEntry
{
	EmployeeData employee;
	vector <EmployeeData> fubarVect;
};
int main() {


	//Part 1
	ifstream textFile;
	textFile.open("c:/users/Enrique/downloads/a7data.txt");

	int hashTable[163] = {0};
	if(textFile.is_open()){
		cout<< "we open" << endl;
	}

	string inputString;
	int key;
	for(string line; getline(textFile, line, '\n');){
		key = stoi(line.substr(3,6));
		key = key % 163;
		hashTable[key]++;

	}



	int noHash = 0;
	int oneHash = 0;
	int manyHash = 0;
	int manySum = 0;

	for(int i =0; i<=163;i++){
		if(hashTable[i] == 0){
			noHash++;
		}
		if(hashTable[i] == 1){
			oneHash++;
		}
		if(hashTable[i] > 1){
			manyHash++;
			manySum = manySum + hashTable[i];

		}
	}

	cout << "number of elements with 0 hashes: " << noHash << endl;
	cout << "number of elements with 1 hash:   " << oneHash << endl;
	cout << "number of elements with >1 hash:  " << manyHash <<	 endl;
	cout << "average chain size for elements with >1 hash: " << manySum / manyHash << endl;

	tableEntry empTable[163];
	int key2;

	textFile.close();
	textFile.open("c:/users/Enrique/downloads/a7data.txt");

	textFile.clear();
	textFile.seekg(0,ios::beg);

	EmployeeData temp;
	for(string nLine; getline(textFile, nLine, '\n');){
		key2 = stoi(nLine.substr(3,6));
		key2 = key2 %163;

		temp.fName = nLine.substr(9,10);
		temp.lName = nLine.substr(19,nLine.find(' '));
			for (int i = 0; i < nLine.substr(0,9).size(); i++) {
				temp.ID[i] = nLine[i];
			}
		if(empTable[key2].employee.fName == ""){
			empTable[key2].employee = temp;
		    }
		else{
			empTable[key2].fubarVect.push_back(temp);
		}

	}

	for( int k = 0; k<163 ; k++){
		cout << "hash table entry " << k << " : ";
		if(empTable[k].employee.fName == ""){
			cout << " no data" << endl;
			cout << "\t there is no chain from this entry " << endl;
		}
		else{
			cout << "employee " << empTable[k].employee.ID << " name " <<  empTable[k].employee.fName<< " " <<  empTable[k].employee.lName<< endl;
			if(empTable[k].fubarVect.empty()){
				cout << "\t there is no chain from this entry " << endl;
			}
			else{
				for( int q= 0 ; q <empTable[k].fubarVect.size(); q++ ){
					cout << "\t chain - employee " << empTable[k].fubarVect[q].ID << " name " << empTable[k].fubarVect[q].fName << " " << empTable[k].fubarVect[q].lName << endl;
				}
			}
		}
	}






//	for(int i =0; i<=163;i++){
//		cout << hashTable[i] << endl;
//	}

//	getline(textFile,inputString, '\n');
//	int key;
//	string test = inputString.substr(3,6);
//	cout << test<< endl;
//	key = stoi(inputString.substr(3,6));




	//cout << key;
	textFile.close();
}
