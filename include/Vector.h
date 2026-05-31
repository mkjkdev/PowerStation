#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>


    /**
    * @class Vector
    * @brief Manages a dynamic array
    *   Vector provides a safe way to manipulate a dynamic array
    *   of type T data
    *
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/4/21
    */

template<class T>
class Vector{
    public:
            /**
            * @brief Constructor, sets size to 0, array to nullptr
            *   No memory allocated until insert
            **/
        Vector();

            /**
            * @brief Constructor taking a size to allocate memory
            * @param size to allocate memory
            * @pre size contains a value greater than 0
            * @post Vector constructod with size memory allocated
            */
        Vector(int size);

            /**
            * @brief Coy constructor
                copies passed vector to calling vector
            * @param Vector to initialize to
            * @pre initializer contains data
            * @post vector Constructed with values copied from initializer
            **/
        Vector(const Vector<T> & initializer);

            /**
            * @brief Returns if Vector is empty or not
            * @return bool if length is 0
            * @post boolean representing if length is 0 or not
            *
            **/
        bool isEmpty() const;

            /**
            * @brief Returns Vector used elements
            * @return int representing vector length
            * @pre Vector has been allocated memory
            * @post amount used elements returned
            **/
        int vectorSize() const;

            /**
            * @brief overloaded assignment operator
            *   Defines behaviour for the default assignment operator
            *   Calls copy method to deep copy elements across
            * @param otherVector to deep copy from
            * @pre otherVector contains data
            * @post values assigned to caller
            **/
        Vector<T>& operator=(const Vector<T> & otherVector);

            /**
            * @brief overloaded array index operator
            *   Defines behaviour for the default array index operator
            *   Provides convenience, as opposed to a get method
            * @param index to return
            * @return T at index
            * @pre index is greater than 0
            * @pre Vector contains data
            * @post T at index returned
            **/
        T & operator [] (int index);

            /**
            * @brief const overloaded array index operator
            *   Defines behaviour for the default array index operator
            *   Provdies convenience, as opposed to a get method
            *   Const overloaded array index operator required when implementing
            * @param index to return
            * @return const T at index
            * @pre index is greater than 0
            * @pre Vector contains data
            * @post const T at index returned
            **/
        const T & operator [] (int index) const;

            /**
            * @brief insert into vector
            *   insert into vector at length, length is incremented on insert
            * @param val to insert
            * @pre val contains valid T instance
            * @post T instance val inserted
            **/
        void insert(const T & val);

            /**
            * @brief clear vector
            *   Clears the vector, deletes and sets to nullptr
            * @return true if vector is nullptr
            * @pre Vector isnt nullptr
            * @post Vector is deleted and set to nullptr
            **/
        bool clear();

            /**
            * @brief Deconstructor
            *   Deletes arrayVector on heap
            *   Sets to nullptr
            * @post vector deleted and set to nullptr
            **/
        virtual ~Vector();
    private:
        T * arrayVector; ///< Dynamic array on heap
        int length; ///< Tracks used elements
        int maxSize; ///< Tracks allocated memory

            /**
            * @brief extends the capacity of the Vecter array
            *   Doubles the capacity of the vector based on isFull()
            * @pre vector maxSize is 0
            * @post vector memory capacity is doubled
            **/
        void expandCapacity();

            /**
            * @brief Copy method copies from passed Vector reference
            *   used by copy constructor and overloaded assignment operator
            * @return returns true if success, false if passed val is empty
            * @pre Vector<T> val contains data
            * @post val data deep copied to calling Vector
            **/
        bool copy(const Vector<T> & val);

            /**
            * @brief Returns if Vector is full or not
            *   private helper method used by insert
            * @return bool if length is equal to max
            * @post boolean true or false based on length and maxSize
            **/
        bool isFull() const;
};

/**********************************Methods*****************************************/

//Deconstructor
template<class T>
Vector<T>::~Vector(){
    delete[] arrayVector;
    arrayVector = nullptr;

    //confirm
    if(arrayVector != nullptr){
        delete [] arrayVector;
        arrayVector = nullptr;
    }
}

//Expand capacity by 2 *
template<class T>
void Vector<T>::expandCapacity(){
    //Double the size, if size is 0, make at least 1 with max
    maxSize = std::max(1, maxSize * 2);

    //Protect incase expanding a null vector
    if(arrayVector == nullptr){
        arrayVector = new T[maxSize];
    }
    else{
        //Temporary array at new size
        T * tempArray= new T[maxSize];
        //Only now index through to add to tempArray
        //loop through and get what was in array
        for(int i =0;i<length;i++){
            tempArray[i] = arrayVector[i];
        }
        //delete old array now we have values
        delete [] arrayVector;
        arrayVector = nullptr;
        //Re-create
        arrayVector = tempArray;
    }
}

//Insert before index
template<class T>
void Vector<T>::insert(const T & val){
    //Check if needs expanding
    if(isFull()){
        expandCapacity();
    }
    //assign to index after shift
    arrayVector[length] = val;
    //Increment length
    length++;
}

//Clear Vector
template<class T>
bool Vector<T>::clear(){
    if(arrayVector != nullptr){
        delete [] arrayVector;
        arrayVector = nullptr;
    }
    //Make sure it worked
    if(arrayVector == nullptr){
        //Reset length
        length =0;
        maxSize =0;
        return true;
    }
    else{
        return false;
    }
}

//Gets Vector size
template<class T>
int Vector<T>::vectorSize() const{
    return length;
}

//Checks if Vector is full
template<class T>
bool Vector<T>::isFull() const{
    if(length == maxSize){
        return true;
    }
    else
        return false;
}

//Checks if Vector is empty
template<class T>
bool Vector<T>::isEmpty() const{
    if(length == 0){
        return true;
    }
    else
        return false;
}

//overloaded assignment operator
template<class T>
Vector<T> & Vector<T>::operator = (const Vector & otherVector){
    //avoid overwriting
    if (this != &otherVector){
        //Make sure arrayVector null
        if(arrayVector != NULL){
            delete [] arrayVector;
            arrayVector = nullptr;
        }
        //Copy to arrayVector
        copy(otherVector);
    }
    return *this;
}

//overloaded array index operator
template<class T>
T & Vector<T>::operator [] (int index){
    //Check if out of range
    assert(index >= 0 && index <= length);

    return arrayVector[index];
}

//Overloaded const array index operator
template<class T>
const T & Vector<T>::operator [] (int index) const{
    //Check if out of range
    assert(index >= 0 && index <= length );
    return arrayVector[index];
}

//Default constructor
template<class T>
Vector<T>::Vector(): arrayVector(nullptr), length(0), maxSize(0){}

//Constructor overloaded
 template<class T>
 Vector<T>::Vector(int size){
    if(size <= 0){
        std::cout << "The array size must be positive. Creating an array with size 10.\n";
        maxSize = 10;
        length =0;
        arrayVector = new T[maxSize];
    }
    else{
        maxSize = size;
        length =0;
        arrayVector = new T[maxSize];
    }
    //Make sure memory allocated
    if(arrayVector == nullptr){
        std::cout << "\nCannot create Vector\n";
    }
 }

 //remove list
//Copy constructor
template<class T>
Vector<T>::Vector(const Vector<T> & initializer): arrayVector(nullptr),length(initializer.vectorSize()),maxSize(initializer.maxSize){
    copy(initializer);
}

//Copy method
template<class T>
bool Vector<T>::copy(const Vector<T> & otherVector){
    if(otherVector.arrayVector!= nullptr || !otherVector.isEmpty()){
        //Get arrayVector ready for new elements
        delete [] arrayVector;
        arrayVector = nullptr;
        //Set lengths
        maxSize = otherVector.maxSize;
        length = otherVector.length;

        //Allocate memory
        arrayVector = new T[maxSize];
        //Check it was success
        if(arrayVector == nullptr){
            return false;
        }

        //copy elements
        for(int i=0;i<length;i++){
            arrayVector[i] = otherVector[i];
        }
        return true;
    }
    else{
        return false;
    }
}

#endif
