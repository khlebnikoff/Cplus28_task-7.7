#include "IntArray.h"

void ShowonExit()
{
    cout << "Программа Завершена!!!" << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    int qx = 20;
    /*
    if (qx < 0)
    {
               exit (1);
           
    }
    */
    try
    {
      if (qx< 0)
       {
         throw SH(11);
       }
    }
    catch (SH& a)
    {
       // a.what();// does not work properly
        a.ShowThrow();
    }
  
    IntArray array(qx);
       for (int i= 0; i < array.getLength(); ++i)
       {      
           array[i] = i + 2147483640;
       }
       array.printResult();
       array.resize(21);// Resize the array to 8 elements
       array.printResult();
       array.insertBefore(20, 5);// Insert the number 20 before element with index 5
       array.printResult();
       array.remove(3);// Remove the element with index 3
       array.printResult();
       array.insertAtEnd(30);// Add 30 and 40 to the end and beginning
       array.printResult();
       array.insertAtBeginning(40);
       array.printResult();
   
       
          /* IntArray b{array};
           b = array;
           b = b;
           array = array;
           b.printResult();
           */

      
       cout << '\n';
       
       array.findElementbyValue(2147483642);
       try
       {
           IntArray b(array.getLength());
           b = array;
           b.printResult();
       }
       catch (...)
       {
           cout << "Shit Happens :)" << endl;
       }
    atexit(ShowonExit);// calling the function atexit
    exit(0);
    return 0;
}