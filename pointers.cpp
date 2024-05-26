#include <iostream>

int add(int a, int b) {
  return a + b;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main () {
  int a = 10;
  int *ptr = &a;

  int &referenceToA = a;

  std::cout << "a: " << a << std::endl;
  std::cout << "a ref: " << referenceToA << std::endl;
  std::cout << "a address: " << &a << std::endl;
  std::cout << "a ref address: " << &referenceToA << std::endl;

  referenceToA = 9;
  std::cout << "a: " << a << std::endl;
  std::cout << "a ref: " << referenceToA << std::endl;

  a = 11;
  std::cout << "a: " << a << std::endl;
  std::cout << "a ref: " << referenceToA << std::endl;

  int x { 5 }, y { 10 };

  std::cout << "Before swap: x = " << x << " y = "  << y << std::endl;

  swap(x, y);
  std::cout << "After swap: x = " << x << " y = "  << y << std::endl;


  std::cout << ptr << std::endl;
  std::cout << *ptr << std::endl;

  int (*funptr) (int, int) = add;
  std::cout << funptr(4, 5) << std::endl;
}
