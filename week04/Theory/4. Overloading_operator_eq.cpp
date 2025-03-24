#include <iostream>
#include <cstring>

class MyString
{
private:
  char *mStr;
  unsigned mCapacity;

public:
  MyString(const char *str = "\0");

  MyString(const MyString &src);
  MyString &operator=(const MyString &rhs);

  ~MyString();
};

MyString::MyString(const char *str) : mCapacity(strlen(str) + 1)
{
  mStr = new char[mCapacity];
  strcpy_s(mStr, mCapacity, str);
}

MyString::MyString(const MyString &src) : mCapacity(src.mCapacity), mStr(new char[mCapacity])
{
  strcpy_s(mStr, mCapacity, src.mStr);
}

MyString &MyString::operator=(const MyString &rhs)
{
  if (this != &rhs)
  {
    delete[] this->mStr;
    this->mCapacity = rhs.mCapacity;
    this->mStr = new char[this->mCapacity];
    strcpy_s(this->mStr, this->mCapacity, rhs.mStr);
  }
  return *this;
}

MyString::~MyString()
{
  delete[] mStr;
}

int main()
{
  /*
  - Copy assignment operator (=)
    - C++ provides a default assignment operator used ofr assigning one object to another
      Mystring s1 {"Frank"};
      Mystring s2 = s1;       //NOT assignment because its the same as Mystring s2{s1}; (initialization statement)
      ,but:
      s2 = s1     ASSIGNMENT

  - Default is memberwise assignment (shallow copy)
    - if we have a raw pointer data member we must deep copy
  */
  MyString str("Nikolay");
  MyString toAssing;
  toAssing = str;

  return 0;
}