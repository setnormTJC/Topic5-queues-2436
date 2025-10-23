// Topic5-queues-2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<queue> 

#include"MyQueue.h"

int main()
{
    //MySpace::QueueADT q; 
    
    try
    {

        MySpace::CircularStaticQueue circularStaticQueue;

        //naiveQueue.dequeue(); //throws exception - cannot pop empty queue
        circularStaticQueue.enqueue("A"); //in std::queue, this is called push 
        circularStaticQueue.enqueue("B");
        circularStaticQueue.enqueue("C"); 
        circularStaticQueue.enqueue("D");
        circularStaticQueue.enqueue("E");

        circularStaticQueue.dequeue(); //remove Alice (because she was the first in line)  
        circularStaticQueue.enqueue("F");

        circularStaticQueue.dequeue(); //remove Bob (he was next)

        //while(naiveQueue.emp)

        //demo of "chaining" operations (cout uses this - ex: cout << a << b << "\n"): 
        circularStaticQueue.enqueueWithChaining("G").enqueueWithChaining("H").enqueue("I");

        //circularStaticQueue.enqueue("J").circularStaticQueue.enqueue("K); //won't work

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
