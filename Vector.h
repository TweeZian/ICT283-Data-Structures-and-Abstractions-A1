/***
@author Thien Twee Zian
@since 25/06/2023
@version 1.01
Template classic Vector class
*/

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

const int INITIAL_SIZE = 6;

/**
This class is a template classic Vector class to be used with other projects
*/
template <class T>
class Vector
{
private:
    /**
    Pointer to the array/vector
    */
    T * m_array;

    /**
    Number of elements in the array
    */
    int m_numElements;

    /**
    Size of the array
    */
    int m_capacity;

public:
    /**
    Default constructor to initialize a vector
    */
    Vector();

    /**
    Default deconstructor to delete the array and change array pointer to nullptr
    */
    ~Vector();

    /**
    Constructor to initialize using another vector
    @param anotherArray - Vector to be used for initialization
    */
    Vector(Vector &anotherArray);

    /**
    Overloaded = operator used for deep copying
    @param anotherArray - Vector to be used for copying
    */
    Vector<T>& operator = (Vector &anotherArray);

    /**
    Method used to add an element into the end of the array
    @param element - Element to be added
    @return boolean - True if operation is successful, otherwise false
    */
    bool Add(T element);

    /**
    Method used to remove an element at the end of the array
    @return boolean - True if operation is successful, otherwise false
    */
    bool Remove();

    /**
    Method used to add an element at a position according to the index
    @param element - Element to be added
    @param index - Position in the array for element to be added
    @return boolean - True if operation is successful, otherwise false
    */
    bool InsertAt(T element, int index);

    /**
    Method used to remove an element at a position according to the index
    @param element - Element to be removed
    @param index - Position in the array for element to be removed
    @return boolean - True if operation is successful, otherwise false
    */
    bool DeleteFrom(int index);

    /**
    Method used to find the size of the array
    @return m_numElements - Number of elements in the array
    */
    int Size();

    /**
    Method used to retrieve element at a position according to the index
    @param index - Position in the array for element to be retrieved
    @return element - Element in the position
    */
    T& At(int index); // equivalent to []; eg. cout << vec[5]

    /**
    Method used to check if the array is empty
    @return boolean - True if empty, otherwise false
    */
    bool Empty();

    /**
    Method used to change element at a position according to the index
    @param element - Element to be changed
    @param index - Position in the array for element to be changed
    @return boolean - True if operation is successful, otherwise false
    */
    bool ModifyAt(T element, int index);  // eg. vec[5] = "abc";

    /**
    Get method for m_array
    @return m_array - Object's m_array
    */
    T* GetArray();

    /**
    Get method for m_capacity
    @return m_capacity - Object's m_capacity
    */
    int GetCapacity();
};

template<class T>
int Vector<T>::GetCapacity()
{
    return m_capacity;
}

template<class T>
T* Vector<T>::GetArray()
{
    return m_array;
}

template<class T>
Vector<T>::Vector()
{
    // initialize an array of size INITIAL_SIZE
    m_numElements = 0;
    m_capacity = 0;
    // try to create array
    m_array = new T[INITIAL_SIZE];
    if(m_array != nullptr)
    {
        m_capacity = INITIAL_SIZE;
    }
}

template<class T>
Vector<T>::~Vector()
{
    if(m_array != nullptr)
    {
        delete[] m_array;
        m_array = nullptr;
    }
}

template<class T>
bool Vector<T>::Add(T element)
{
    if(m_numElements >= m_capacity)
    {
        int newCapacity = m_capacity * 2;
        T *tempArray = new T[newCapacity];


        //if tempArray is successfully allocated
        if(tempArray != nullptr)
        {
            // copy all elements from old array to new array
            for(int i = 0; i < m_numElements; i++)
            {
                tempArray[i] = m_array[i];
            }
            delete[] m_array;
            m_array = tempArray;
            tempArray = nullptr;
            m_capacity = newCapacity;

            // add the new item into the array
            m_array[m_numElements] = element;
            m_numElements++;
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        // add the new item into the array
        m_array[m_numElements] = element;
        m_numElements++;
        return true;
    }
}

template<class T>
int Vector<T>::Size()
{
    return m_numElements;
}

template<class T>
T& Vector<T>::At(int index)
{
    return *(m_array + index);
}

template<class T>
Vector<T>::Vector(Vector &anotherArray)
{
    m_numElements = 0;
    m_capacity = 0;
    // try to create array
    m_array = new T[INITIAL_SIZE];
    if(m_array != nullptr)
    {
        m_capacity = INITIAL_SIZE;
        for(int i = 0; i < anotherArray.Size(); i++)
        {
            T tempElement = anotherArray.At(i);
            Add(tempElement);
        }
    }
}

template<class T>
Vector<T>& Vector<T>::operator =(Vector &anotherArray)
{
    if(m_array != nullptr)
    {
        for(int i = 0; i < anotherArray.Size(); i++)
        {
            T tempElement = anotherArray.At(i);
            Add(tempElement);
        }
    }


    return *this;
}

template<class T>
bool Vector<T>::Remove()
{
    if(m_numElements > 0)
    {
        m_numElements--;
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
bool Vector<T>::DeleteFrom(int index)
{
    if(index < m_numElements && index >= 0)
    {
        for(int i = index; i < m_numElements; i++)
        {
            *(m_array + i) = *(m_array + i + 1);
        }
        m_numElements--;
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
bool Vector<T>::InsertAt(T element, int index)
{
    if(index < m_numElements && index >= 0)
    {
        if(m_numElements >= m_capacity)
        {
            int newCapacity = m_capacity * 2;
            T *tempArray = new T[newCapacity];

            //if tempArray is successfully allocated
            if(tempArray != nullptr)
            {
                // copy all elements from old array to new array
                for(int i = 0; i < m_numElements; i++)
                {
                    tempArray[i] = m_array[i];
                }
                delete[] m_array;
                m_array = tempArray;
                tempArray = nullptr;
                m_capacity = newCapacity;

                for(int i = m_numElements; i > index; i--) // move elements backwards, starting from
                {
                    *(m_array + i) = *(m_array + i - 1);
                }
                *(m_array + index) = element;
                m_numElements++;
                return true;
            }
        }
        else
        {
            for(int i = m_numElements; i > index; i--)
            {
                *(m_array + i) = *(m_array + i - 1);
            }
            *(m_array + index) = element;
            m_numElements++;
            return true;
        }
    }
    else
    {
        return false;
    }
}

template<class T>
bool Vector<T>::Empty()
{
    if(m_array != nullptr)
    {
        if(m_numElements == 0)
        {
            return true;
        }
    }
    return false;
}

template<class T>
bool Vector<T>::ModifyAt(T element, int index)
{
    if(m_array != nullptr)
    {
        if(index < m_numElements && index >= 0)
        {
            *(m_array + index) = element;
            return true;
        }
    }
    return false;
}

#endif // VECTOR_H_INCLUDED
