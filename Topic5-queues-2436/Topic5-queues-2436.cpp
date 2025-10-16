// Topic5-queues-2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"MyQueue.h"

int main()
{
    //MySpace::QueueADT q; 
    
    try
    {
        MySpace::NaiveQueue naiveQueue; 

        //naiveQueue.dequeue(); //that's what I like about Texas!
        naiveQueue.enqueue("Alice"); //in std::queue, this is called push 
        naiveQueue.enqueue("Bob");
        naiveQueue.enqueue("Carol"); 

        naiveQueue.dequeue(); 

       


    }

    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }



    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
