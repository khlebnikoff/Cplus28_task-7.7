#include "IntArray.h"
IntArray::IntArray(int length) : m_length{ length }
{
    try
    {
        if (length > 0)
        {
            m_data = new int[length] {};
        }
        else
        {
            throw SH(11);
        }

    }
    catch (SH& a)
    {
        a.what();
        a.ShowThrow();
    }
}
IntArray::IntArray(const IntArray& a)
{
    reallocate(a.getLength());

    try
    {
       
        for (int index{ 0 }; index < m_length; ++index) 
            if (index <= 0)
            {
                throw SH(20);
            }
            else
            {
                m_data[index] = a.m_data[index];
            }
    }
    catch (SH& a)
    {
        a.what();
        a.ShowThrow();
    }
}
IntArray::~IntArray()
{
    delete[] m_data;
    
}
void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}
void IntArray::reallocate(int newLength)
{
       erase();

       if (newLength <= 0)
        return;

       m_data = new int[newLength];
    m_length = newLength;
}
void IntArray::resize(int newLength)
{
       if (newLength == m_length)
        return;

       if (newLength <= 0)
    {
        erase();
        return;
    }

    
    int* data{ new int[newLength] };

    
    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

      
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    
    delete[] m_data;

    
    m_data = data;
    m_length = newLength;
}
void IntArray::insertBefore(int value, int index)
{
    try
    {
    if (!(index >= 0 && index <= m_length))
        {
        throw SH(20);
        }
    }
    catch (SH& a)
    {
        a.what();
        a.ShowThrow();
    }
    int* data{ new int[m_length + 1] };

   
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before]; 
        data[index] = value;

    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    
    delete[] m_data;
    m_data = data;
    ++m_length;
}
void IntArray::remove(int index)
{
   
    if (!(index >= 0 && index <= m_length))
    {
        try
        {
            throw SH(30);
        }
        catch (SH& a)
        {
            a.what();
            a.ShowThrow();
        }
      
    }
    
    if (m_length == 1)
    {
        erase();
        return;
    }

    
    int* data{ new int[m_length - 1] };

  
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

   
    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    try
    {
    delete[] m_data;
   
    }
    catch (const char* exception)
    {
        cout << exception << endl;
    }
    catch (const exception& ex)
    {
        cout << ex.what() << endl;
    }
     catch (const string& ex) 
     {
        cout << ex << endl;
     }
     catch (...)
     {
         cout << "ALL Exceptions are catched" << endl;
     }
     try
     {
         m_data = data;
     }
     catch (const char* exception)
     {
         cout << exception << endl;
     }
     catch (const exception& ex)
     {
         cout << ex.what() << endl;
     }
     catch (const string& ex)
     {
         cout << ex << endl;
     }
     catch (...) 
     {
         cout << "ALL Exceptions are catched" << endl;
     }
    --m_length;
}
void IntArray::insertAtBeginning(int value) { insertBefore(value, 0); }
void IntArray::insertAtEnd(int value) { insertBefore(value, m_length); }
int IntArray::getLength() const { return m_length; }
  int& IntArray::operator[](int index)
  {
      if (!(index >= 0 && index <= m_length))
      {
          try
          {
              throw SH(40);
          }
          catch (SH& a)
          {
              a.what();
              a.ShowThrow();
          }
      }
     
        //assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    IntArray& IntArray::operator=(const IntArray& a)
    {
            if (&a == this)
            return *this;

          reallocate(a.getLength());

           for (int index{ 0 }; index < m_length; ++index)
            m_data[index] = a.m_data[index];

        return *this;
    }
    //
    void IntArray::printResult()
    {
              
        cout << "stage: "<<++pr<<" "<<"Размер Массива : " << ' ' << m_length << endl;
        try
        {
            if (m_length <= 0)
            {
                throw SH(50);
            }
            for (int i = 0; i < m_length; i++)
            {
                if (i > m_length)
                {
                    throw SH(51);
                }
                cout << m_data[i] << ' ';
            }
            cout << endl;
        }
        catch (SH& a)
        {
            a.what();
            a.ShowThrow();
        }
               
    }
    void IntArray::findElementbyValue(int value)
    {
        int e = 0;
        for (int i = 0; i < m_length; i++)
        {
            if (m_data[i] == value)
            {
                e = i;
                cout << "The index of element with the value " << value << " is " << i << endl;
             }
        }
        if (e == 0)
        {
            cout << " the array has no elements with this value" << endl;
        }
    }
  

    void SH::ShowThrow()
       {
        cout << "Error number:" << _e;
        switch ( _e)
        {
        case 10:
            cout << " the length of the array is wrong" << endl;
            exit( _e);
            break;
        case 11:
            cout << " the length of the array is NEGATIVE" << endl;
            exit( _e);
            break;
        case 20:
            cout << " the index is out of the range" << endl;
            exit(_e);
            break;
        case 21:
            cout << " the index of the element is wrong" << endl;
            exit(_e); 
            break;
            exit(_e);
        case 22:
            cout << " the value of the element is wrong" << endl;
            exit(_e); 
            break;
        case 30:
            cout << " the index is out of the range" << endl;
            exit(_e); 
            break;
        case 40:
            cout << " get Length trouble" << endl;
            exit(_e); 
            break;
        case 50:
            cout << " cant print the array" << endl;
            exit(_e); 
            break;
        case 60:
            cout << " local variable value is too big" << endl;
            exit(_e); 
            break;
        case 61:
            cout << " array variable is too big" << endl;
            exit(_e); 
            break;
        default:
            cout << " unexpected exception" << endl;
            exit(_e); 
            break;
        }

    }