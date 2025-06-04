//Coordinators : Doan (Lam) Nguyen, Sammatha Magill, and Angel Prak
//Description  : Exam 3
//Date         : June 4th, 2025

//Division of tasks
//Me : Queue, Vector, main (partly) 
//Sammatha : Map, main 
//Angel : Stack, List


#include"input.h"
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <random>
#include <sstream>


using namespace std;

//prototype
void drawing();
void maps();
void vectors();
void lists();
void stacks();
void queues();
char menuOption();
int mapMenu();
int vectorMenu();
int listMenu();
int stackMenu();
int queueMenu();

//Our works 
int main()
{
    //main menu
    do
    {
        system("cls");
        drawing();
        switch (menuOption())
        {
        case 'X':  return 0; break;
        case 'M': maps(); break;
        case 'V': vectors(); break;
        case 'L': lists(); break;
        case 'S': stacks(); break;
        case 'Q': queues(); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }

        cout << "\n";
        system("pause");
    } while (true);

    return 1;
}

//display those nice figures above the menu function
void drawing()
{
    cout << "\n\t" << char(218) << string(4, char(196)) << char(194) << string(10, char(196)) << char(191) << string(64, char(32));
    cout << char(186) << char(32) << "in/out" << char(32) << char(186) << string(12, char(32)) << char(186) << string(3, char(32)) << "in" << string(3, char(32)) << char(186);

    cout << "\n\t" << char(179) << char(32) << "Cr" << char(32) << char(179) << char(32) << "Creative" << char(32) << char(179) << string(64, char(32));
    cout << char(186) << char(32) << char(218) << string(4, char(196)) << char(191) << char(32) << char(186) << string(12, char(32)) << char(186) << char(32) << char(218) << string(4, char(196)) << char(191) << char(32) << char(186);

    cout << "\n\t" << char(195) << string(4, char(196)) << char(197) << string(10, char(196)) << char(180) << string(60, char(32));
    cout << "top" << char(62) << char(186) << char(32) << char(179) << char(32) << "Ti" << char(32) << char(179) << char(32) << char(186) << string(7, char(32)) << "rear" << char(62) << char(186) << char(32) << char(179) << char(32) << "Pt" << char(32) << char(179) << char(32) << char(186);

    cout << "\n\t" << char(179) << char(32) << "Op" << char(32) << char(179) << char(32) << "Optimism" << char(32) << char(179) << string(64, char(32));
    cout << char(186) << char(32) << char(195) << string(4, char(196)) << char(180) << char(32) << char(186) << string(12, char(32)) << char(186) << char(32) << char(195) << string(4, char(196)) << char(180) << char(32) << char(186);

    cout << "\n\t" << char(195) << string(4, char(196)) << char(197) << string(10, char(196)) << char(180) << string(6, char(32)) << char(218) << string(4, char(196)) << char(194) << string(4, char(196)) << char(194) << string(4, char(196)) << char(191);
    cout << string(9, char(32)) << char(218) << string(4, char(196)) << char(191) << char(32) << char(218) << string(4, char(196)) << char(191) << char(32) << char(218) << string(4, char(196)) << char(191) << char(32);
    cout << string(12, char(32)) << char(186) << char(32) << char(179) << char(32) << "Nu" << char(32) << char(179) << char(32) << char(186) << string(12, char(32));
    cout << char(186) << char(32) << char(179) << char(32) << "Di" << char(32) << char(179) << char(32) << char(186);

    cout << "\n\t" << char(179) << char(32) << "Fr" << char(32) << char(179) << char(32) << "Fearless" << char(32) << char(179);
    cout << string(6, char(32)) << char(179) << char(32) << "Ju" << char(32) << char(179) << char(32) << "Ki" << char(32) << char(179) << char(32) << "Ma" << char(32) << char(179);
    cout << string(7, char(32)) << char(218) << char(62) << char(179) << char(32) << "Up" << char(32) << char(179) << char(62) << char(179) << char(32) << "Vi" << char(32) << char(179) << char(62) << char(179) << char(32) << "Pe" << char(32) << char(179);
    cout << string(13, char(32)) << char(186) << char(32) << char(195) << string(4, char(196)) << char(180) << char(32) << char(186) << string(12, char(32)) << char(186) << char(32) << char(195) << string(4, char(196)) << char(180) << char(32) << char(186);

    cout << "\n\t" << char(192) << string(4, char(196)) << char(193) << string(10, char(196)) << char(217) << string(6, char(32));
    cout << char(192) << string(4, char(196)) << char(193) << string(4, char(196)) << char(193) << string(4, char(196)) << char(217);
    cout << string(7, char(32)) << char(179) << char(32) << char(192) << string(4, char(196)) << char(217) << char(32) << char(192) << string(4, char(196)) << char(217) << char(32) << char(192) << string(4, char(196)) << char(217);
    cout << string(13, char(32)) << char(186) << char(32) << char(179) << char(32) << "Cu" << char(32) << char(179) << char(32) << char(186) << string(6, char(32));
    cout << "front" << char(62) << char(186) << char(32) << char(179) << char(32) << "Ag" << char(32) << char(179) << char(32) << char(186);

    cout << "\n\t key " << "  value" << string(11, char(32)) << 0 << string(4, char(32)) << 1 << string(4, char(32)) << 2 << string(13, char(32)) << "head" << string(30, char(32));
    cout << char(186) << char(32) << char(192) << string(4, char(196)) << char(217) << char(32) << char(186) << string(12, char(32));
    cout << char(186) << char(32) << char(192) << string(4, char(196)) << char(217) << char(32) << char(186);

    cout << "\n\t" << string(23, char(32)) << "(index)" << string(16, char(32)) << "(pointer)" << string(26, char(32));
    cout << char(200) << string(8, char(205)) << char(188) << string(12, char(32)) << char(186) << "  out   " << char(186);

    cout << "\n\n\t" << string(4, char(32)) << "Map" << string(20, char(32)) << "Vector" << string(17, char(32)) << "Linked List";
    cout << string(22, char(32)) << "Stack" << string(17, char(32)) << "Queue" << string(3, char(32));

}

//display choice menu 
char menuOption()
{
    //main menu
    cout << "\n\n\tStandard Template Library (STL) provides the built-in implementation of commonly used data structures known";
    cout << "\n\tas containers. A container is a holder object that stores a collection of other objects(its elements). They are";
    cout << "\n\timplemented as class templates, which allows great flexibility in the types supported as elements. A container";
    cout << "\n\tmanages the storage space for its elements and provides member functions to access them, either directly or through";
    cout << "\n\titerators(reference objects with similar properties to pointers).";


    //need to display array size, index and first element here
    cout << "\n\n\tCMPR121 - Exam#3: STL (Standard Template Library) Containers and Container Adaptors by Samantha Magill, Doan (Lam) Nguyen, and Angel Prak";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t M. Map Associative Container";
    cout << "\n\t V. Vector (contiguous memory) Sequence Container";
    cout << "\n\t L. List (non-contiguous memory) Sequence Container";
    cout << "\n\t S. Stack (LIFO) Container Adaptor";
    cout << "\n\t Q. Queue (FIFO) Container Adaptor";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t X. Exit Program";
    cout << "\n\t" << string(80, char(205));
    cout << "\n";

    return toupper(inputChar("\n\tSpecify an option: ", "MVLSQX"));
}




/* Map part */ //By Sammatha
int mapMenu()
{
    cout << "\n\n\tMap Menu Options";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t1. Read text data file and insert into map container";
    cout << "\n\t2. Display (using recursion) all Elements from the map container";
    cout << "\n\t3. Insert a new Element into the map container";
    cout << "\n\t4. Delete/Erase an existing Element from the map conatiner";
    cout << "\n\t5. Quiz Game";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Return";
    cout << "\n\t" << string(80, char(205));

    return inputInteger("\n\tSpecify an option: ", 0, 5);
}

void mapsRead(map<string, string>& testMap)
{
    {

        ifstream fileToRead;
        string filename = inputString("\n\tSpecify a valid binary data file name to retrieve data from (elements.txt) : ", false);

        string line;

        fileToRead.open(filename);

        if (!fileToRead) {
            cout << "\n\tERROR: File, " << filename << ", cannot be found to read.";
            return;
        }

        while (getline(fileToRead, line))
        {
            stringstream ss(line);
            string key, value;
            size_t hyphen = line.find('-');

            if (hyphen != string::npos)
            {
                key = line.substr(0, hyphen);
                value = line.substr(hyphen + 1);
                testMap[key] = value;
            }
        }

        cout << "\n\tCONFIRMATION: " << testMap.size() << " element(s) have been stored/inserted into the map container.";
        fileToRead.close();
    }
}

void mapsDisplay(map<string, string>& testMap, map<string, string>::iterator it)
{
    if (it == testMap.end())
    {
        cout << "\n\tCONFIRMATION: " << testMap.size() << " of element(s) are in the map container.";
        return;
    }

    cout << "\t" << it->first << "  " << it->second << "\n";
    mapsDisplay(testMap, next(it));
}

void mapsInsert(map<string, string>& testMap)
{
    string toAdd = inputString("\n\tSpecify an Element Symbol : ", false);

    if (toAdd.length() > 2)
    {
        cout << "\n\tERROR: Invalid Element Symbol. Must be 1-2 characters long";
        return;
    }

    //testMap.find(toAdd);
    if (testMap.count(toAdd) > 0)
    {
        cout << "\n\tERROR: Element, " << toAdd << " has already existed in the map container and therefore it cannot be re-inserted.";
    }
    else
    {
        string toAddVal = inputString("\n\tSpecify the Element Name : ", false);
        testMap.emplace(toAdd, toAddVal);
        cout << "\n\tCONFIRMATION: New element, " << toAdd << " - " << toAddVal << ", has been inserted into the map container.";
    }
}

void mapsDelete(map<string, string>& testMap)
{
    string toDel = inputString("\n\tSpecify an element symbol : ", false);

    if (toDel.length() > 2)
    {
        cout << "\n\tERROR: Invalid Element Symbol. Must be 1-2 characters long";
        return;
    }

    if (testMap.count(toDel) > 0)
    {
        testMap.erase(toDel);
        cout << "\n\tCONFIRMATION: Element, " << toDel << " has been deleted/erased from the map container.";
    }
    else
    {
        cout << "\n\tERROR: Element Symbol, " << toDel << ", does not exist in the map of Elements and therefore it cannot be deleted from the map container.";
    }
}

void mapsGame(map<string, string>& testMap, int& q, int& r, int& w)
{
    if (testMap.size() == 0) return;

    //pair keys to vector
    vector<string>keys;
    for (const auto& pair : testMap)
        (keys.push_back(pair.first));

    //randomize index
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, keys.size() - 1);

    int ranIndex = distrib(gen);
    string ranKey = keys[ranIndex];
    string ranValue = testMap[ranKey];

    string answer;
    tolower(answer[0]);
    tolower(ranValue[0]);


    cout << "\n\tWhat is the element name of " << ranKey << "? ";
    getline(cin, answer);
    q++;

    if (answer == ranValue)
    {
        cout << "\n\tCONFIRMATION: Correct answer! ";
        r++;
    }
    else
    {
        cout << "\n\tERROR: Incorrect! The answer is " << ranValue;
        w++;
    }

    cout << "\n\t" << q << " Question(s)";
    cout << "\n\t" << r << " correct answer(s)";
    cout << "\n\t" << w << " wrong answer(s)";

}

void maps()
{
    map<string, string>testMap;
    map<string, string>::iterator it;

    int right = 0;
    int wrong = 0;
    int questions = 0;
    do
    {
        system("cls");
        cout << "\n\tIn C++, maps are associative containers that store data in the form of key value pairs sorted on the basis of keys.No two mapped values can have the same keys.By default, it stores data in ascending order of the keys. ";
        int size = testMap.size();
        cout << "\n\n";
        switch (mapMenu())
        {
        case 0:  return; break;
        case 1: mapsRead(testMap); break;
        case 2: mapsDisplay(testMap, testMap.begin()); break;
        case 3: mapsInsert(testMap); break;
        case 4: mapsDelete(testMap); break;
        case 5: mapsGame(testMap, right, wrong, questions); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n\n";
        system("pause");
    } while (true);
}




/* Vector part */ //By me 
int vectorMenu()
{
    cout << "\n\n\tVector Menu Options";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t1. Add (push_back) an element";
    cout << "\n\t2. Insert an element at index";
    cout << "\n\t3. Retrieve an element from index";
    cout << "\n\t4. Erase element(s)";
    cout << "\n\t5. Sort the vector elements in ascending order";
    cout << "\n\t6. Clear all elemetns";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Return";
    cout << "\n\t" << string(80, char(205));

    return inputInteger("\n\tSpecify an option: ", 0, 6);
}

void VectorAdd(vector<string>& vectors) 
{
    string NewElement = inputString("\n\tSpecify an Element Symbol: ", false);

    if (false) //mapName.find(NewElement) 
    {
        cout << "\n\tERROR: Element Symbol, " << NewElement << ", does not exist in the map Elements and therefore it cannot be added to the vector.";
    }
    else {
        vectors.push_back(NewElement); 
        cout << "\n\tCONFIRMATION: Element Symbol, " << NewElement << "' has been added to the back of the vector.";
    }
}

void VectorInsert(vector<string>& vectors)
{
    string NewElement = inputString("\n\tSpecify an Element Symbol: ", false);
    if (false) //mapName.find(NewElement) 
    {
        cout << "\n\tERROR: Element Symbol, " << NewElement << ", does not exist in the map Elements and therefore it cannot be added to the vector.";
    }
    else {

        if (vectors.empty()) {
            vectors.push_back(NewElement);
            cout << "\n\tCONFIRMATION: Element Symbol, " << NewElement << ", has been inserted into the back of the vector.";
        }
        else {
            int i = inputInteger("\n\tSpecify an index from the vector to be inserted : ", 0, vectors.size() - 1);
            auto it = vectors.begin() + i;
            vectors.insert(it, NewElement);
            cout << "\n\tCONFIRMATION: Element, " << NewElement << ", has been inserted at index " << i << " of the vector container.";
        }
    }
}

void VectorRetrieve(const vector<string>& vectors)
{
    if (vectors.size() == 0)
    {
        cout << "\n\tERROR: Clear operation cannot be performed on an empty vector.";
    }
    else {
        int indexRetrieve = inputInteger("\n\tEnter an index of the vector container: ");
       
        try
        {
            cout << "\n\t[" << vectors.at(indexRetrieve) << "] is located at index (" << indexRetrieve << ") from the vector container.";
        }
        catch (out_of_range& exception)
        {
            cout << "\n\tEXCEPTIONAL ERROR: Invalid subscript.";
        }
    }
}

//tell if a symbol exists in the vector
int findVector(const vector<string>& vectors, string element, int size)
{
    if (size <= 0) return -1;
        
    if (vectors[size - 1] == element) return size - 1;
    else {
        return findVector(vectors, element, size - 1);
    }
}

//delete all found copies of an element in a vector
void deleteAll(vector<string>& vectors, string element, vector<string>::iterator it)
{
    if (it == vectors.end()) return; 
    if (*it == element) {
        it = vectors.erase(it);
        deleteAll(vectors, element, it);
    }
    else {
        deleteAll(vectors, element, it + 1);
    }
}


void VectorErase(vector<string>& vectors)
{
    if (vectors.size() == 0)
    {
        cout << "\n\tERROR: Erase operation cannot be performed on an empty vector.";
    }
    else {
        string StringErase = inputString("\n\tSpecify an Element Symbol: ",false);


        if (findVector(vectors, StringErase, vectors.size()) == -1)
        {
            cout << "\n\t" << StringErase << " cannot be found from the vector container."; 
        }
        else {
            char choice = toupper(inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", "OA"));
            switch (choice)
            {
            case 'A':                                                                                  //FIX 
                deleteAll(vectors, StringErase, vectors.begin());
                cout << "\n\tAll " << StringErase << " has been removed from the vector.";
                break;
            case 'O': 
                auto it = vectors.begin() + findVector(vectors, StringErase, vectors.size());
                vectors.erase(it);
                cout << "\n\tFirst found " << choice << " has been removed from the vector.";
                break;
            }
        }
    }
}

void VectorSort(vector<string>& vectors)
{
    if (vectors.size() == 0)
    {
        cout << "\n\tERROR: Sort operation cannot be performed on an empty vector.";
    }
    else {
        sort(vectors.begin(), vectors.end());
        cout << "\n\tThe vector has been sorted in ascending order.";
    }
}

void VectorClear(vector<string>& vectors)
{
    if (vectors.size() == 0)
    {
        cout << "\n\tERROR: Clear operation cannot be performed on an empty vector.";
    }
    else {
        vectors.clear();
        cout << "\n\tCONFIRMATION: The vector has been cleared of all elements.";
    }
}

//display all elements in the vector
void displayVector(const vector<string>& vectors, int i)
{
    if (i >= vectors.size()) return; 

    cout << "[" << setw(2) << right << vectors[i] << "]";
    displayVector(vectors, i + 1);
}

//display the indices of all elements in the vector
void displayIndex(const vector<string>& vectors, int j)
{
    if(j >= vectors.size()) return;

    cout << j << "   ";
    displayIndex(vectors, j+1);
}

void vectors()
{
    vector<string> elementVector; 
    do
    {
        system("cls");
        cout << "\n\tIn C++, vector is a dynamic array that stores collection of elements same type in contiguous memory. It has the ability to resize itself automatically when an element is inserted or deleted. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators or indexes. ";
        if (elementVector.empty()) {
            cout << "\n\n\tThe current vector is empty.";
        }
        else {
            cout << "\n\n\tThe current vector contains " << elementVector.size() << " elements.\n"; 

            cout << "\n\t\t"; 
            displayVector(elementVector, 0);
            cout << "\n\tIndex:  ";
            displayIndex(elementVector, 0);
            cout << "\n\tAddress: " << elementVector.data(); 
        }
        cout << "\n\n";
        switch (vectorMenu())
        {
        case 0:  return; break;
        case 1:  VectorAdd(elementVector);  break;
        case 2:  VectorInsert(elementVector); break;
        case 3:  VectorRetrieve(elementVector);  break;
        case 4:  VectorErase(elementVector);  break;
        case 5:  VectorSort(elementVector);  break;
        case 6:  VectorClear(elementVector);  break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n\n";
        system("pause");
    } while (true);
}




/* Linked list part */ //By Angel 
int listMenu()
{
    cout << "\n\n\tLinked List Menu Options";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t1. Add (push) an element";
    cout << "\n\t2. Insert an element after";
    cout << "\n\t3. Remove element(s)";
    cout << "\n\t4. Sort the elements in ascending order";
    cout << "\n\t5. Clear all elemetns";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Return";
    cout << "\n\t" << string(80, char(205));

    return inputInteger("\n\tSpecify an option: ", 0, 5);
}

//recursion function to print a list
void printList(list <string>& l, list <string> ::iterator it)
{
    //base case ends the recursive functionif the iterator is the end of linked list
    if (it == l.end())
    {
        cout << "[Null]";
        return;
    }
    //else it prints the current node and calls back the function with an incremented iterator
    else
    {
        cout << "[" << *it << "]->";
        printList(l, ++it);
    }
}

//creates an iterator to transverse the list
list<string> ::iterator findNode(list<string>& l, string n)
{
    list<string> ::iterator i;
    for (i = l.begin(); i != l.end(); ++i)
    {
        if (*i == n)
            return i;
    }

    //if end is returned as iteraotr value then return an error message
    return l.end();
}

void lists()
{
    list<string> elementList;
    list<string> ::iterator node;

    string element = "null";
    string pivot = "null";
    do
    {
        system("cls");
        cout << "\n\tIn C++, list container implements a doubly linked list in which each element contains the address of next and previous element in the list.It stores data in non - contiguous memory, hence providing fast insertion and deletion once the position of the element is known.";
        if (elementList.empty())
            cout << "\n\n\t Current list is empty...";
        else
        {
            cout << "\n\n\tThe current linked list contains " << elementList.size() << " element:";
            list <string> ::iterator it = elementList.begin();
            cout << "\n\n\t[Head]->";
            printList(elementList, it);
        }
        cout << "\n\n";
        switch (listMenu())
        {
        case 0:  return; break;
        case 1:
            //Add (push) element
            //**need to check for map list

            element = inputString("\n\tSpecify an Element Symbol: ", false);

            if (false) //mapName.find(NewElement) 
            {
                cout << "\n\tERROR: Element Symbol, " << element << ", does not exist in the map Elements and therefore it cannot be added to the list.";
                return;
            }

            if (elementList.empty()) {
                elementList.push_front(element);
                cout << "\n\tCONFIRMATION: Element" << element << "has been added to the empty list.";
            }
            else
            {
                if (toupper(inputChar("\n\n\t\tAdd to the (F-front) or from the (B-back): ", 'F', 'B')) == 'F')
                {
                    elementList.push_front(element);
                    cout << "\n\tCONFIRMATION: Element [" << element << "] has been pushed to the front of the list container.";
                }
                else {
                    elementList.push_back(element);
                    cout << "\n\tCONFIRMATION: Element [" << element << "] has been pushed to the back of the list container.";
                }
            }
            break;
        case 2:
            //Insert element
            //**need to check for map list
            element = inputString("\n\tSpecify an Element Symbol: ", false);

            if (false) //mapName.find(NewElement) 
            {
                cout << "\n\tERROR: Element Symbol, " << element << ", does not exist in the map Elements and therefore it cannot be inserted into the list.";
                return;
            }

            //**need to check for linked list
            pivot = inputString("\n\tSpecify an Element Symbol: ", false);

            if (findNode(elementList, pivot) == elementList.end())
            {
                cout << "\n\tERROR: Element" << pivot << "cannot be found from the list container.";
            }
            else
            {
                node = findNode(elementList, pivot);
                if (toupper(inputChar("\n\n\t\tInsert (B-before) or (A-after) the existing element : ", 'B', 'A')) == 'B')
                {
                    elementList.emplace(node, element);
                    cout << "\n\tCONFIRMATION: Element [" << element << "] has been inserted before the existing element [" << pivot << "] from the list container.";
                }
                else {
                    elementList.emplace(++node, element);
                    cout << "\n\tCONFIRMATION: Element [" << element << "] has been inserted after the existing element [" << pivot << "] from the list container.";
                }
            }
            break;
        case 3:
            //remove elements

            if (elementList.empty()) {
                cout << "\n\tERROR: Delete operation cannot be performed on an empty list container.";
                return;
            }

            element = inputString("\n\tSpecify an Element Symbol: ", false);

            if (findNode(elementList, element) == elementList.end())
            {
                cout << "\n\tERROR: Element [" << element <<"] is not found in the list";
            }
            else
            {
                node = findNode(elementList, element);

                if (toupper(inputChar("\n\n\t\tRemove (O-one) or (A-all) element(s): ", 'O', 'A')) == 'O') {
                    elementList.erase(node);
                    cout << "\n\tCONFIRMATION: Element [" << element << "] has been removed once from the list container.";
                }
                else {
                    while (findNode(elementList, element) != elementList.end())
                    {
                        elementList.erase(node);
                        node = findNode(elementList, element);
                    }
                    cout << "\n\tCONFIRMATION: All element [" << element << "] have been removed from the list container.";
                }
            }
            break;
        case 4:
            //sort elements

            if (!elementList.empty()) {
                elementList.sort();
                cout << "\n\tCONFIRMATION: The list container have been sorted.";
            }
            else {
                cout << "\n\tERROR: Sort operation cannot be performed on an empty list container.";
            }


            break;
        case 5:
            //clear elements

            if (elementList.empty()) {
                cout << "\n\tERROR: Clear operation cannot be performed on an empty list container.";
                return;
            }

            elementList.clear();
            cout << "\n\tCONFIRMATION: All Elements have been cleared from list";
            break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n\n";
        system("pause");
    } while (true);
}




/* Stack part*/ //By Angel 
int stackMenu()
{
    cout << "\n\n\tStack Menu Options";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t1. Push";
    cout << "\n\t2. Top";
    cout << "\n\t3. Pop";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Return";
    cout << "\n\t" << string(80, char(205));

    return inputInteger("\n\tSpecify an option: ", 0, 3);
}

//recursion function for printing the stack
void printStack(stack <string>& s)
{
    //Base case: once it reaches the bottom of the stack
    if (s.empty())
        return;

    //saves the top in a string to push back after it is popped off
    string top = s.top();

    cout << "[" << top << "]";

    s.pop();

    printStack(s);

    s.push(top);
}

void stacks()
{
    stack <string> elementStack;

    string element = "null";
    do
    {
        system("cls");
        cout << "\n\tStacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added(pushed) at one end(top) and an element is removed(popped) from that end only.Stack uses an encapsualted object of either vector or deque(by default) or list(sequential container class) as its underlying container, providing a specific set of member functions to access its elements.";
        if (elementStack.empty())
            cout << "\n\n\t Current list is empty...";
        else
        {
            cout << "\n\n\tThe current stack contains " << elementStack.size();
            cout << "\n\n\tTop->";
            printStack(elementStack);
        }
        cout << "\n\n";
        switch (stackMenu())
        {
        case 0:  return; break;
        case 1:
            //push
            element = inputString("\n\tSpecify an Element Symbol: ", false);

            if (false) //mapName.find(NewElement) 
            {
                cout << "\n\tERROR: Element Symbol, " << element << ", does not exist in the map Elements and therefore it cannot be added to the stack.";
                return;
            }

            elementStack.push(element);
            cout << "\n\tCONFIRMATION: [" << element << "] has been pushed onto the stack container.";
            break;
        case 2:
            //show top
            if (elementStack.empty())
                cout << "\n\tERROR: No top element can be retrieved from an empty stack container.";
            else
                cout << "\n\n\t[" << elementStack.top() << "] is at the top of the stack container.";
            break;
        case 3:
            //pop
            if (elementStack.empty())
                cout << "\n\tERROR: No pop operation can be performed from an empty stack container.";
            else
            {
                cout << "\n\tCONFIRMATION: [" << elementStack.top() << "] will be popped off from the stack container.";
                elementStack.pop();
            }
            break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n\n";
        system("pause");
    } while (true);
}




/* Queue part*/ //By me
int queueMenu()
{
    cout << "\n\n\tQueue Menu Options";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t1. Enqueue (push into the rear)";
    cout << "\n\t2. Rear";
    cout << "\n\t3. Front";
    cout << "\n\t4. Dequeue (pop from the front)";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t0. Return";
    cout << "\n\t" << string(80, char(205));

    return inputInteger("\n\tSpecify an option: ", 0, 4);
}

void Enqueue(queue<string>& queues)
{
    string NewElement = inputString("\n\tSpecify an Element Symbol: ", false);

    if (false) //mapName.find(NewElement) 
    {
        cout << "\n\tERROR: Element Symbol, " << NewElement << ", does not exist in the map Elements and therefore it cannot be added to the queue.";
    }
    else {
        queues.push(NewElement);
        cout << "\n\tCONFIRMATION: Element Symbol, " << NewElement << "' has been added to the rear of the queue.";
    }
}

void RearQueue(queue<string>& queues)
{
    if (queues.empty())
    {
        cout << "\n\tERROR: No back element can be retrieved from an empty queue container.";
    }
    else {
        cout << "\n\t[" << queues.back() << "] is at the back of the queue container.";
    }
}

void FrontQueue(queue<string>& queues)
{
    if (queues.empty())
    {
        cout << "\n\tERROR: No front element can be retrieved from an empty queue container.";
    }
    else {
        cout << "\n\t[" << queues.front() << "] is at the front of the queue container.";
    }
}

void Dequeue(queue<string>& queues)
{
    if (queues.empty())
    {
        cout << "\n\tERROR: No dequeue (pop) operation can be performed on an empty queue container.";
    }
    else {

        cout << "\n\t[" << queues.front() << "] has been dequeued (popped) from the queue container.";
        queues.pop();

    }
}

//display the queue from the rear to the front
void displayQueue(queue<string> queues)
{
    if (queues.empty()) return; 

    string front = queues.front(); //update the front until the rear is removed
    queues.pop();
    displayQueue(queues);
    cout << "[" << setw(2) << right << front << "] -> "; //display the front from the latest updates 
}


void queues()
{
    queue<string> elementQueue; 
    do
    {
        system("cls");
        cout << "\n\tQueues are type of container adaptors that operate in a first in first out (FIFO) type of arrangement.Elements are inserted / pushed(enqueued) at the rear and are removed / popped(dequeued) from the front.Queues use an encapsulated object of deque or list(sequential container class) as its underlying container, providing a specific set of member functions to access elements..";
        cout << "\n\n";
        if (elementQueue.empty()) {
            cout << "\n\n\tThe current queue is empty.";
        }
        else {
            cout << "\n\n\tThe current queue contains " << elementQueue.size() << " elements.\n";

            cout << "\n\tin(rear) -> ";
            displayQueue(elementQueue);
            cout << "out(front)\n";
            
            cout << "\n\tAddress: " << &elementQueue;
        }
        switch (queueMenu())
        {
        case 0:  return; break;
        case 1: Enqueue(elementQueue); break;
        case 2: RearQueue(elementQueue); break;
        case 3: FrontQueue(elementQueue); break;
        case 4: Dequeue(elementQueue); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n\n";
        system("pause");
    } while (true);
}


