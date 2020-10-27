// Assignment #6
// Name: Noah Carlow
// ASU Email Address: ncarlow2@asu.edu
// Description: To be completed

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi

using namespace std;

//Project represents some project information
class Project
 {
  private: 
    string projectName;
    string region;
    int cost;
    Project * left, * right, * parent;


  public:
    //The following two functions are constructors
    Project()
     { 
      projectName = "?";
      region = "?";
      cost = 0;
      parent = NULL;
      left = NULL;
      right = NULL;
     }

    Project(string projectName1, string region1, int cost1)
     {
      projectName = projectName1;
      region = region1;
      cost = cost1;
      parent = NULL;
      left = NULL;
      right = NULL;
     }

    //The following functions are accessor functions
    Project * getLeft()
     {
      return left;
     }

    Project * getRight()
     {
      return right;
     }

    Project * getParent()
     {
      return parent;
     }
     
    string getProjectName()
     {
         return projectName;
     }
     string getRegion()
     {
         return region;
     }
     int getCost()
     {
         return cost;
     }
     

    //The following functions are mutator functions
    void setLeft(Project * other)
     {
       left = other;
     }

    void setRight(Project * other)
     {
       right = other;
     }

    void setParent(Project * other)
     {
       parent = other;
     }

    //The print method prints the project information
    void print()
     {
         cout << "Project Name: " << projectName << endl;
         cout << "Region: " << region << endl;
         cout << "Cost: " << cost << endl << endl;
     }

   //you can add more functions

 };

//class BinarySearchTree will contains projects
class BinarySearchTree
 {
  private:
     Project * root;
     int size;

  public:
     BinarySearchTree();
     ~BinarySearchTree();
     int postOrderTreeDelete(Project *);
     bool isEmpty();
     void inOrderTreePrint();
     void preOrderTreePrint();
     void postOrderTreePrint();
     void inOrderTreeWalk(Project *);
     void preOrderTreeWalk(Project *);
     void postOrderTreeWalk(Project *);
     Project * treeSearchNode(Project *, string);
     Project * treeSearch(string);
     Project * treeMinimum();
     Project * treeMaximum();
     Project * treeMinimumNode(Project *);
     Project * treeMaximumNode(Project *);
     Project * treeSuccessor(string);
     Project * treePredecessor(string);
     bool treeInsert(string,string,int);
     bool rightRotate(string);
     bool leftRotate(string);
 };

//The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
 {
  root = NULL;
 }

//The descurtor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree()
 {
   //TO BE COMPLETED

 }

//Checks if the tree is empty
bool BinarySearchTree::isEmpty()
 {
   if (root == NULL)
    return true;
   else
    return false; 
 }

//prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    inOrderTreeWalk(root);
    cout << "\n";
   }
 }

//prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    preOrderTreeWalk(root);
    cout << "\n";
   }
 }

//prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    postOrderTreeWalk(root);
    cout << "\n";
   }
 }

///COMPLETE THE REQUIRED FUNCTIONS
 

