#ifndef Bst_H
#define Bst_H

#include "Node.h"

    /**
    * @class Bst
    * @brief Represents a Binary Search Tree structure
    * minimal and complete implementation to have a functioning Bst
    *
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/5/21
    */

template<class T>
class Bst {
    typedef void(*functionReturn)(const T &); ///< return function type declaration

    public:
            /**
            * @brief default constructor
            * sets root to nullptr
            */
        Bst();

            /**
            * @brief copy constructor
            * calls copyTree
            * @param tree Bst to copy from
            */
        Bst(const Bst & tree);

            /**
            * @brief deconstructor
            * calls private deleteTree
            */
        virtual ~ Bst();

            /**
            * @brief insert method calls private insert
            * @param insertItem int to insert
            *
            */
        bool insert(const T & insertItem);

            /**
            * @brief public search, calls recursive search with caller root Node
            * @param item, item to insert
            *
            */
        bool search(const T & item, functionReturn func);

            /**
            * @brief inOrder traversal public method
            * calls inOrderTraversal
            */
        void inOrder(functionReturn func) const;

            /**
            * @brief postORder traversal public method
            * calls postOrderTraversal
            */
        void postOrder(functionReturn func) const;

            /**
            * @brief preOrder traversal public methos
            * calls preOrderTraversal
            */
        void preOrder(functionReturn func) const;

            /**
            * @brief overloaded assignment operator
            * @param tree reference to bst to assign
            */
        Bst & operator=(const Bst & tree);

    private:
        /**
        * @brief root Node pointer
        */
        Node<T> * root; ///< root pointer to Heap Node

            /**
             * @param tree, pointer to reference Node
             * @param parent, pointer to reference Node
             * @todo check recursive method
             * @todo check break case
             */
        bool insert(Node<T> * & tree, Node<T> * & parent);

            /**
             * @param root, pointer to reference Node
             * @param item to search for
             * @todo check recursive method
             * @todo check break case
             * @return bool
             */
        bool search(Node<T> * & root, const T & item, functionReturn func) const;

            /**
             * @brief private deleteTree to protect incorrect delete attempts
             * @param Node deleteNode
             */
        void deleteTree(Node<T> * & deleteNode);

            /**
             * @param Node resultTreeRoot
             * @param Node otherTreeRoot
             */
        void copyTree(Node<T> * & resultTreeRoot, const Node<T> * otherTreeRoot);

            /**
            * @brief in order traversal of tree, prints value
            * @param func pointer function
            * @param root Node to traverse
            */
        void inOrderTraversal(functionReturn func, Node<T> * root) const;

            /**
            * @brief post order traversal of tree, prints value post
            * @param func pointer function
            * @param root Node to traverse
            */
        void postOrderTraversal(functionReturn func, Node<T> * root) const;

            /**
            * @brief post order traversal of tree, prints value pre
            * @param func pointer function
            * @param root Node to traverse
            */
        void preOrderTraversal(functionReturn func, Node<T> * root) const;
};


//---------------------Methods-----------------------//
template<class T>
Bst<T>::Bst(): root(nullptr){}

//copy constructor
template<class T>
Bst<T>::Bst(const Bst & tree): root(nullptr){
    //Passed tree is empty
    if(tree.root == nullptr){
        root = nullptr;
    }
    else{//copy from non empty tree
        copyTree(root, tree.root);
    }
}

//Deconstructor
template<class T>
Bst<T>::~Bst(){
    //Delete all memory previously used
    deleteTree(root);
}

//deep copy
template<class T>
void Bst<T>::copyTree(Node<T> * & resultTreeRoot, const Node<T> * otherTreeRoot){
    //Check if null
    if(otherTreeRoot == nullptr){
        resultTreeRoot = nullptr;
    }
    else{
        Node<T> * newNode = new Node<T>;
        resultTreeRoot = newNode;
        resultTreeRoot->info = otherTreeRoot->info;

        //recursive call with left then right
        copyTree(resultTreeRoot->left, otherTreeRoot->left);
        copyTree(resultTreeRoot->right, otherTreeRoot->right);
    }
}

//delete memory allocated to tree
template<class T>
void Bst<T>::deleteTree(Node<T> *& deleteNode){
    //remove recursively
    if(deleteNode != nullptr){
        deleteTree(deleteNode->left);
        deleteTree(deleteNode->right);
        delete deleteNode;
        deleteNode = nullptr;
    }
}

//assignment operator overloaded
template<class T>
Bst<T> & Bst<T>::operator=(const Bst<T> & otherTree){
    //avoid self copy
    if(this == &otherTree){
        return *this;
    }
    //Check if not null, then delete
    if(root != nullptr){
        deleteTree(root);
    }
    //copy if other tree is not empty
    if(otherTree.root != nullptr){
        copyTree(root, otherTree.root);
    }

    else{
        root = nullptr;
    }

    return * this;
}

//public inOrder calls private method with caller root node
template<class T>
void Bst<T>::inOrder(functionReturn func) const{
    inOrderTraversal(func, root);
}

//in order traversal recursively
template<class T>
void Bst<T>::inOrderTraversal(functionReturn func, Node<T> * tree) const{
    if(tree != nullptr){
        inOrderTraversal(* func, tree->left);
        //action in order, call function pointer, pass node info as parameter
        //std::cout << tree->info << std::endl;

        //remove parenthesis and dereference, research double dereferencing
        func(tree->info);
        inOrderTraversal(* func, tree->right);
    }
}

//public preOrder calls private method with caller root node
template<class T>
void Bst<T>::preOrder(functionReturn func) const{
    preOrderTraversal(func, root);
}

//pre order traversal recursively
template<class T>
void Bst<T>::preOrderTraversal(functionReturn func, Node<T> * tree) const{
    if(tree != nullptr){
        //action pre order, call function pointer, pass node info as parameter
        //std::cout << tree->info << std::endl;
        func(tree->info);
        preOrderTraversal(* func, tree->left);
        preOrderTraversal(* func, tree->right);
    }
}

//public postOrder traversal calls private method with caller root node
template<class T>
void Bst<T>::postOrder(functionReturn func) const{
    postOrderTraversal(func, root);
}

//post order traversal recursively
template<class T>
void Bst<T>::postOrderTraversal(functionReturn func, Node<T> * tree) const{
    if(tree != nullptr){
        postOrderTraversal(* func, tree->left);
        postOrderTraversal(* func, tree->right);
        //action post order, call function pointer, pass node info as parameter
        //std::cout << tree->info << std::endl;
        func(tree->info);
    }
}

template<class T>
bool Bst<T>::insert(const T & insertItem){
    //create node to insert
    Node<T> * tempNode = new Node<T>(insertItem);

    if(root == nullptr){
        root = tempNode;
        return true;
    }
    return(insert(tempNode, root));
}

//insert integer to tree, create a new node with the required value, pass to isnert
template<class T>
bool Bst<T>::insert(Node<T> * & node, Node<T> * & parent){
    //If root is null then insert
        //check for duplicate
        //Check nested statements
        if(node->info == parent->info){
            return false;
        }
        if(node->info < parent->info){
            if(parent->left == nullptr){
                parent->left = node;
                return true;
            }
            else{
                insert(node, parent->left);
            }
        }
        else{
            if(parent->right == nullptr){
                parent->right = node;
                return true;
            }
            else{
                insert(node, parent->right);
            }
        }
        return false;
    }

//Public search calls recursive search with caller root node
template<class T>
bool Bst<T>::search(const T & item, functionReturn func){
    if(search(root, item, * func)){
        return true;
    }
    else{
        return false;
    }
}

//search for item, depth first search
template<class T>
bool Bst<T>::search(Node<T> * & tree, const T & item, functionReturn func) const{
    bool found = false;
    //return if null
    if(tree != nullptr){
        //end case
        if(tree->info == item){
            func(tree->info);
            found = true;
        }
        //while not found recursive search
        if(found == false){
            found = search(tree->left, item, * func);
            if(!found){
                found = search(tree->right, item, * func);
            }
        }
    }
    return found;
}
#endif //_Bst_H
