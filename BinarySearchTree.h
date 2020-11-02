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

// Tree Traversal printing functions below
void BinarySearchTree::inOrderTreeWalk(Project * x)
{
  if (x != NULL)
  {
    inOrderTreeWalk(x->getLeft());
    x->print();
    inOrderTreeWalk(x->getRight());
  }
}

void BinarySearchTree::preOrderTreeWalk(Project * x)
{
  if (x != NULL)
  {
    x->print();
    preOrderTreeWalk(x->getLeft());
    preOrderTreeWalk(x->getRight());
  }
}

void BinarySearchTree::postOrderTreeWalk(Project * x)
{
  if (x != NULL)
  {
    postOrderTreeWalk(x->getLeft());
    postOrderTreeWalk(x->getRight());
    x->print();
  }
}

// Tree functions

// insert a node into our binary search tree
bool BinarySearchTree::treeInsert(string name, string region, int cost)
{
  Project* z = new Project(name, region, cost);
  Project* y = NULL;
  Project* x = root;

  while (x != NULL)
  {
    y = x;
    if (name.compare(y->getProjectName()) < 0)
    {
      x = x->getLeft();
    }
    else
    {
      x = x->getRight();
    }
  }
  z->setParent(y);

  if (y == NULL)
  {
      root = z;
  }
  else
  {
    if (name.compare(y->getProjectName()) < 0)
    {
      y->setLeft(z);
    }
    else
    {
      y->setRight(z);
    }
  }
  return true;
}

// rotate the tree to the left
bool BinarySearchTree::leftRotate(string node)
{
  Project* x = treeSearch(node);
  if (x == NULL)
  {
    std::cout << "test";
    return false;
  }
  Project* y = x->getRight();
  
  x->setRight(y->getLeft());
  if (y->getLeft() != NULL)
  {
    y->getLeft()->setParent(x);
  }
  y->setParent(x->getParent());

  if (x->getParent() == NULL)
  {
    root = y;
  }
  else
  {
    if (x == x->getParent()->getLeft())
    {
      x->getParent()->setLeft(y);
    }
    else
    {
      x->getParent()->setRight(y);
    }
    y->setRight(x);
    x->setParent(y);
  }
  return true;
}

bool BinarySearchTree::rightRotate(string node)
{
  Project* x = treeSearch(node);
  if (x == NULL)
  {
    return false;
  }
  Project* y = x->getLeft();
  
  x->setLeft(y->getRight());
  if (y->getRight() != NULL)
  {
    y->getRight()->setParent(x);
  }
  y->setParent(x->getParent());

  if (x->getParent() == NULL)
  {
    root = y;
  }
  else
  {
    if (x == x->getParent()->getRight())
    {
      x->getParent()->setRight(y);
    }
    else
    {
      x->getParent()->setLeft(y);
    }
    y->setLeft(x);
    x->setParent(y);
  }
  return true;
}

// search for a node in our binary search tree
Project* BinarySearchTree::treeSearch(string nodeName)
{
  Project* x = root;
  if (root == NULL)
  {
    return NULL;
  }
  while (x != NULL && x->getProjectName().compare(nodeName) != 0)
  {
    if (nodeName.compare(x->getProjectName()) > 0)
    {
      if (x->getLeft() == NULL)
      {
        return NULL;
      }
      x = x->getLeft();
    }
    else
    {
      if (x->getRight() == NULL)
      {
        return NULL;
      }
      x = x->getRight();
    }
  }
  return x;
}

Project* BinarySearchTree::treeSearchNode(Project* node, string nodeName)
{
  Project* x = node;
  if (node == NULL)
  {
    return NULL;
  }
  while (x != NULL || x->getProjectName().compare(nodeName) != 0)
  {
    if (nodeName.compare(x->getProjectName()) > 0)
    {
      if (x->getLeft() == NULL)
      {
        return NULL;
      }
      x = x->getLeft();
    }
    else
    {
      if (x->getRight() == NULL)
      {
        return NULL;
      }
      x = x->getRight();
    }
  }
  return x;
}

// find the tree minimum
Project* BinarySearchTree::treeMinimum()
{
  if (isEmpty())
  {
    return NULL;
  }

  Project* x = root;
  while(x->getLeft() != NULL)
  {
    x = x->getLeft();
  }
  return x;
}

// find the minimum of a specific node
Project* BinarySearchTree::treeMinimumNode(Project* node)
{
  if (isEmpty())
  {
    cout << "tree is empty" << endl;
    return NULL;
  }

  while(node->getLeft() != NULL)
  {
    node = node->getLeft();
  }
  return node;
}

// find the tree maximum
Project* BinarySearchTree::treeMaximum()
{
  if (isEmpty())
  {
    return NULL;
  }

  Project* x = root;
  while(x->getRight() != NULL)
  {
    x = x->getRight();
  }
  return x;
}
// find the maximum if a specific node
Project* BinarySearchTree::treeMaximumNode(Project* node)
{
  if (isEmpty())
  {
    cout << "tree is empty" << endl;
    return NULL;
  }

  while(node->getRight() != NULL)
  {
    node = node->getRight();
  }
  return node;
}

// finds the nodes successor
Project* BinarySearchTree::treeSuccessor(string node)
{
  Project* x = treeSearchNode(root, node);
  if (x == NULL)
  {
    return NULL;
  }
  Project* y;

  if (x->getRight() != NULL)
  {
    return treeMinimumNode(x->getRight());
  }
  y = x->getParent();
  while (y != NULL && x == y->getRight())
  {
    x = y;
    y = y->getParent();
  }
  return y;
}

// find the nodes predecessor
Project* BinarySearchTree::treePredecessor(string node)
{
  Project* x = treeSearchNode(root, node);
  if (x == NULL)
  {
    return NULL;
  }
  Project* y;

  if (x->getLeft() != NULL)
  {
    return treeMinimumNode(x->getLeft());
  }
  y = x->getParent();
  while (y != NULL && x == y->getLeft())
  {
    x = y;
    y = y->getParent();
  }
  return y;
}