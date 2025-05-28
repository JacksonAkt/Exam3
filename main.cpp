//Coordinators : Doan (Lam) Nguyen, Sammatha Magill, and Angel Prak
//Description  : Exam 3
//Date         : May 31, 2025

#include"input.h"
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <cctype>
#include <iomanip>


using namespace std;

//prototype
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


int main()
{
    //main menu
    do
    {
        system("cls");
        cout << "\n\n";
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

char menuOption()
{
    //main menu
    cout << "\n\tStandard Template Library (STL) provides the built-in implementation of commonly used data structures known as containers.A container is a holder object that stores a collection of other objects(its elements).They are implemented as class templates, which allows great flexibility in the types supported as elements.A container manages the storage space for its elements and provides member functions to access them, either directly or through iterators(reference objects with similar properties to pointers).";


    //need to display array size, index and first element here
    cout << "\n\n\tCMPR121 - Exam#3: STL (Standard Template Library) Containers and Container Adaptors by Samantha Magill, Doan (Lam) Nguyen, and Angel";
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




/* Map part */
int mapMenu()
{
    system("cls");
    cout << " In C++, maps are associative containers that store data in the form of key value pairs sorted on the basis of keys.No two mapped values can have the same keys.By default, it stores data in ascending order of the keys. ";
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

void maps()
{
    do
    {
        cout << "\n\n";
        switch (mapMenu())
        {
        case 0:  return; break;
        case 1:  break;
        case 2:  break;
        case 3:  break;
        case 4:  break;
        case 5:  break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}




/* Vector part */ 
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
        int i = inputInteger("\n\tSpecify an index from the vector to be inserted : ", 0, vectors.size() - 1);
        auto it = vectors.begin() + i;
        vectors.insert(it, NewElement);
        cout << "\n\tCONFIRMATION: Element, " << NewElement << ", has been inserted at index " << i << " of the vector container.";
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
            cout << "\n\tEXEPTIONAL ERROR: Invalid subscript.";
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
                cout << "\n\tAll " << choice << " has been removed from the vector.";
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




/* Linked list part */
int listMenu()
{
    system("cls");
    cout << " In C++, list container implements a doubly linked list in which each element contains the address of next and previous element in the list.It stores data in non - contiguous memory, hence providing fast insertion and deletion once the position of the element is known.";
    cout << "\n\n\tList Menu Options";
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

void lists()
{
    do
    {
        cout << "\n\n";
        switch (listMenu())
        {
        case 0:  return; break;
        case 1:  break;
        case 2:  break;
        case 3:  break;
        case 4:  break;
        case 5:  break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}




/* Stack part*/
int stackMenu()
{
    system("cls");
    cout << "  Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added(pushed) at one end(top) and an element is removed(popped) from that end only.Stack uses an encapsualted object of either vector or deque(by default) or list(sequential container class) as its underlying container, providing a specific set of member functions to access its elements.";
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

void stacks()
{
    do
    {
        cout << "\n\n";
        switch (stackMenu())
        {
        case 0:  return; break;
        case 1:  break;
        case 2:  break;
        case 3:  break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}




/* Queue part*/ 
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
            cout << "out(front)";
            
            cout << "\n\tAddress: ";
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
        cout << "\n";
        system("pause");
    } while (true);
}
