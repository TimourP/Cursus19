#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include "containers/map.hpp"
#include "containers/stack.hpp"
#include "containers/vector.hpp"
void test_vector();
void test_map();
void test_stack();

/*
** 531-m31c's tester for ft_containers
** Feel free to comment lines in main to test containers one by one
*/
int main()
{
test_vector();
test_map();
test_stack();
}

void test_stack()
{
	std::cout << "******STARTING TO TEST ft::STACK******" << std::endl;
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
  std::vector<int> myvector (2,200);        // vector with 2 elements

  std::stack<int> first;                    // empty stack

  std::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
	  ft::vector<int> myvector (2,200);        // vector with 2 elements
  ft::stack<int> first;                    // empty stack
  ft::stack<int,ft::vector<int> > third;  // empty stack using vector
  ft::stack<int,ft::vector<int> > fourth (myvector);
  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------MINE_SIZE-----------" << std::endl;
{
	  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------STL_EMPTY-----------" << std::endl;
{
	 std::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}

std::cout << "----------STL_TOP-----------" << std::endl;
{
	 ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

}
std::cout << "----------MINE_TOP-----------" << std::endl;
{ ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}
std::cout << "----------STL_PUSH_POP-----------" << std::endl;
{
	  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}
std::cout << "----------MINE_PUSH_POP-----------" << std::endl;
{
	  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}
std::cout << "------------STL_REL_OPERATOR--------" << std::endl;
//TEST relational operators: tests from cplusplus.com

std::cout << "------------MINE_REL_OPERATOR--------" << std::endl;


}
void test_map()
{
	std::cout << "******STARTING TO TEST ft::MAP******" << std::endl;
std::cout << "----------STL_INSERT-----------" << std::endl;
{
	std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
    std::map<char,int>::iterator it = mymap.begin();
	 mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
 std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
std::cout << "----------MINE_INSERT-----------" << std::endl;
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
  ft::map<char, int>::iterator it = mymap.begin();
 mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(), mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
 std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

std::cout << "----------STL_OPERATOR[]-----------" << std::endl;
{
	std::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}
std::cout << "----------MINE_OPERATOR[]-----------" << std::endl;
{
  ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}

std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
}
std::cout << "----------MINE_SIZE-----------" << std::endl;
{  
	ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
  }
std::cout << "----------STL_EMPTY-----------" << std::endl;
  {
	   std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  }
std::cout << "----------MINE_EMPTY-----------" << std::endl;
  {
	   std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  }
std::cout << "----------STL_SWAP-----------" << std::endl;
 {
	   std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }
std::cout << "----------MINE_SWAP-----------" << std::endl;
 {
	   ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }

std::cout << "----------STL_ERASE-----------" << std::endl;
 {
	   std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }
std::cout << "----------MINE_ERASE-----------" << std::endl;
{  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
std::cout << "----------STL_KEY__COMP-----------" << std::endl;
{std::map<char,int> mymap;

  std::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
  }
std::cout << "----------STL_KEY__COMP-----------" << std::endl;
{
	ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
  }
 
std::cout << "----------STL_VALUE__COMP-----------" << std::endl;
 {
	  std::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

 }
std::cout << "----------MINE_VALUE__COMP-----------" << std::endl;
 {
	  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

 }
std::cout << "----------STL_COUNT-----------" << std::endl;
 {
	   std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
 }
std::cout << "----------MINE_COUNT-----------" << std::endl;
 {
	   ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
 }
std::cout << "----------STL_LOWER__BOUND-----------" << std::endl;
{
	  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}
std::cout << "----------MINE_LOWER__BOUND-----------" << std::endl;
{
	  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;


  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
  ft::map<char,int>::iterator s = itlow;
  ft::map<char,int>::iterator e = itup;
//  for (; s != itup; s++)
//	std::cout << s->first << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

std::cout << "----------STL_EQUAL__RANGE-----------" << std::endl;
{
	 std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}
std::cout << "----------MINE_EQUAL__RANGE-----------" << std::endl;
{
	 ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}
}

void test_vector()
{
	std::cout << "******STARTING TO TEST ft::VECTOR******" << std::endl;
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
	  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
 std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};

  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
    std::cout << "The contents of second are:";
  for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of third are:";
  for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
		  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};

  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of second are:";
  for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of third are:";
    for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------STL_OPERATOR==-----------" << std::endl;
{
	  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}
std::cout << "----------MINE_OPERATOR==-----------" << std::endl;
{
	  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

std::cout << "----------STL_REND_RBEGIN-----------" << std::endl;
{
	  std::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  std::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_REND_RBEGIN-----------" << std::endl;
{
	  ft::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';

}
std::cout << "----------MINE_SIZE-----------" << std::endl;
{  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}


std::cout << "----------STL_PUSH__BACK-----------" << std::endl;
{
  std::vector<int> myvector;


  for (int i = 19; i <= 42; i++)
    myvector.push_back(i);
 
  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "vector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}
std::cout << "----------MINE_PUSH__BACK-----------" << std::endl;
{
  ft::vector<int> myvector;
 


  for (int i = 19; i <= 42; i++)
    myvector.push_back (i);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "vector contains:";
	for (ft::vector<int>::iterator it=myvector.begin(); it != myvector.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::cout << "----------STL_INSERT-----------" << std::endl;
{
	  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  std::vector<int> vec;
  vec.push_back(19);
  vec.push_back(21);
  vec.push_back(42);
  myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_INSERT-----------" << std::endl;
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());

ft::vector<int> vec;
vec.push_back(19);
vec.push_back(21);
vec.push_back(42);
  myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

std::cout << "----------STL_IT_OP[]_OP+-----------" << std::endl;
{
	    std::vector<int>v1; 
		v1.push_back(1); 
		v1.push_back(2); 
		v1.push_back(3); 
		v1.push_back(4); 
		v1.push_back(5); 
    int i; 
  std::vector<int>::iterator itx = v1.begin();
    for(i=0;i<5;++i) 
        std::cout << itx[i] << " "; 
	std::cout << std::endl;
	std::vector<int>::iterator it = v1.begin() + 1;
	std::cout << it[-1] << std::endl;
	it = v1.end() - 1;
	std::cout << it[-1] << std::endl;
	it -= 4;
	std::cout << it[0] << std::endl;
	it += 2;
	std::cout << it[0] << std::endl;

}
std::cout << "----------MINE_IT_OP[]_OP+_OP-_OP+=_OP-=()-----------" << std::endl;
{
	    ft::vector<int>v1;
		v1.push_back(1); 
		v1.push_back(2); 
		v1.push_back(3); 
		v1.push_back(4); 
		v1.push_back(5); 
    int i; 
  
	ft::vector<int>::iterator itx = v1.begin();
    for(i=0;i<5;++i) 
        std::cout << itx[i] << " "; 
	std::cout << std::endl;
	ft::vector<int>::iterator it = v1.begin() + 1;
	std::cout << it[-1] << std::endl;
	it = v1.end() - 1;
	std::cout << it[-1] << std::endl;
	it -= 4;
	std::cout << it[0] << std::endl;
	it += 2;
	std::cout << it[0] << std::endl;

}
std::cout << "----------STL_SPECIAL---------" << std::endl;
// THIS IS AN ADDITIONAL TEST TO CHECK ITERATOR DESIGN VALIDITY
{
std::vector<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.push_back(3);
std::vector<int>::iterator it = lst.end();
lst.erase(--lst.end());
lst.insert(lst.end(), lst.begin(), (++lst.begin()));
lst.insert(--(--lst.end()), 19);
while (it != lst.begin())
	std::cout << *--it << std::endl;
}
std::cout << "----------MINE_SPECIAL---------" << std::endl;
{
ft::vector<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.push_back(3);
ft::vector<int>::iterator it = lst.end();
lst.erase(--lst.end());
lst.insert(lst.end(), lst.begin(), (++lst.begin()));
lst.insert(--(--lst.end()), 19);
while (it != lst.begin())
	std::cout << *--it << std::endl;
}

std::cout << "----------STL_RESIZE-----------" << std::endl;
{
	 std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

}
std::cout << "----------MINE_RESIZE-----------" << std::endl;
{ 
	ft::vector<int> myvector;
  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}		
std::cout << "----------STL_OP[]-----------" << std::endl;
{
	  std::vector<int> myvector (10);   // 10 zero-initialized elements

  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

}
std::cout << "----------MINE_OP[]-----------" << std::endl;
{
	  ft::vector<int> myvector (10);   // 10 zero-initialized elements

  
  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
std::cout << "----------STL_EMPTY-----------" << std::endl;
{
	  std::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	  ft::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------STL_FRONT-----------" << std::endl;
{
	  std::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}
std::cout << "----------MINE_FRONT-----------" << std::endl;
{
	  ft::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}
std::cout << "----------STL_RESERVE-----------" << std::endl;
{
  std::vector<int> foo;
  foo.reserve(19);
  std::cout << foo.capacity() << std::endl;
  foo.reserve(42);
  std::cout << foo.capacity() << std::endl;
}
std::cout << "----------MINE_RESERVE-----------" << std::endl;
{
  ft::vector<int> foo;
  foo.reserve(19);
  std::cout << foo.capacity() << std::endl;
  foo.reserve(42);
  std::cout << foo.capacity() << std::endl;
}
std::cout << "----------STL_AT-----------" << std::endl;
{
std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

}
std::cout << "----------MINE_AT-----------" << std::endl;
{
ft::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
  
}
std::cout << "----------STL_ASSIGN-----------" << std::endl;
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';	
}
std::cout << "----------MINE_ASSIGN-----------" << std::endl;
{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
std::cout << "----------STL_SWAP-----------" << std::endl;
{
	 std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
std::cout << "----------MINE_SWAP-----------" << std::endl;
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
std::cout << "----------STL_NMO_REL_OP-----------" << std::endl;
{
std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
std::cout << "----------MINE_NMO_REL_OP-----------" << std::endl;
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
std::cout << "----------MINE_NMO_SWAP-----------" << std::endl;
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_NMO_SWAP-----------" << std::endl;
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
}