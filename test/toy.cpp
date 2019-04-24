
// A program with virtual destructor
#include <iostream>
#include <memory>

using namespace std;

class base {
public:
  base()
  { cout<<"Constructing base \n"; }
  virtual ~base()
  { cout<<"Destructing base \n"; }
};

class derived: public base {
public:
  derived()
  { cout<<"Constructing derived \n"; }
  ~derived()
  { cout<<"Destructing derived \n"; }
};

int main(void)
{
  std::shared_ptr<derived> d = make_shared<derived>();
  std::shared_ptr<derived> d2(d);
  // base *b = d;
  // delete b;
  //  delete b;
  //  getchar();
  return 0;
}
