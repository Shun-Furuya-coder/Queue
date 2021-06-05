// Lab: Queues 4
// Name: Shun Furuya
// IDE: Xcode

#include <iostream>
#include <string>

#include "QueueADT.h"


using namespace std;

int main() {

    // Create the first queue (strings)
    Queue<string> queName;
    
    // Write a loop to enter an unknown number of names (assume one word strings).
    // The loop stops when you enter #.
    // As you are entering names, they are to be inserted into the first queue.
    string name;
    cin >> name;
    while(name != "#"){
        queName.push(name);
        cin >> name;
    }
    
    if(queName.isEmpty()){
        cout << "Empty Queue!" << endl;
        exit(1);
    }

    // Test the getLength function: - display the number of elements in the first queue
    cout << queName.getLength() << " ";
    
    // Create the second queue (doubles)
    Queue<double> queNum;
    
    // Test the getLength function: - display the number of elements in the second queue
                                 // (it should be 0!)
    cout << queNum.getLength() << endl;
    
    // Write another loop to enter the number of units (double) into a parallel queue.
    double item;
    for(int i = 0; i < queName.getLength(); i++){
        cin >> item;
        queNum.push(item);
    }
    
    // Display the two queues in parallel.
    string firstName = queName.peek();
    double lastNum = queNum.peekRear();
    
    while(!queName.isEmpty()){
        cout << queName.pop() << " " << queNum.pop() << endl;
    }
    
    // Display the front element in the first queue
    cout << firstName << endl;
    
    // Display the rear element in the second queue
    cout << lastNum << endl;
    
    return 0;
}


/*output

Ann Tim Jamie Bob #
4 0
9 4.5 15 13.5
Ann 9
Tim 4.5
Jamie 15
Bob 13.5
Ann
13.5
Program ended with exit code: 0
 
 
*/
