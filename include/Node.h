/**
 * Project Bst
 * @brief intBst integer Binary Search Tree
 * @author mkjkdev
 * @date 17/05/2026
 */

#ifndef _NODE_H
#define _NODE_H

/**
* @brief Node struct containing data, left and right Node
* @todo make Bst a friend, change struct members to private
*/
template<class T>
struct Node {
    T info;
    Node<T> * right;
    Node<T> * left;

    //make Bst a friend of this struct here
    //friend template<class T>

    //Struct constructor
    Node(): info(T()), right(nullptr), left(nullptr){}
    Node(const T & data):info(data), right(nullptr),left(nullptr) {}
};
#endif //_NODE_H
