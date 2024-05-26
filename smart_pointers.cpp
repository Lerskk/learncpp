#include <iostream>
#include <memory>
#include <unistd.h>

class MyClass {
  public:
    MyClass() { std::cout << "Constructor is called." << std::endl; }
    ~MyClass() { std::cout << "Deconstructor is called." << std::endl; }
};

struct MyDeleter {
  void operator()(int* ptr) {
    std::cout << "Custom Deleter: Deleting pointer" << std::endl;
    delete ptr;
  }
};

void timeout() {
  std::unique_ptr<int, MyDeleter> p1(new int(22), MyDeleter());
  std::unique_ptr<int, MyDeleter> p2 = std::move(p1);

  std::cout << "Starting calculation..." << std::endl;
  sleep(2); 
  std::cout << "Done." << std::endl;
}

int main() {
  std::shared_ptr<MyClass> ptr1(new MyClass());
  std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>();

  {
    std::shared_ptr<MyClass> ptr3 = ptr1;

    std::cout << "Inside inner scope." << std::endl;
  }

  std::cout << "Outside the inner scope." << std::endl;

  std::unique_ptr<int> p1(new int(5));
  std::unique_ptr<int> p2 = std::make_unique<int>(10); // preferred method since C++14

  std::cout << *p1 << ", " << *p2 << std::endl;

  std::cout << "Unscoped p1: " << *p1 << std::endl;
  {
    std::unique_ptr<int> p1 = std::make_unique<int>(14);
    std::cout << "Scoped p1: " << *p1 << std::endl;
  }
  std::cout << "Unscoped p1: " << *p1 << std::endl;

  std::unique_ptr<int> p3 = std::move(p1);

  std::unique_ptr<int, MyDeleter> p4(new int(20), MyDeleter());
  timeout();

  if (p1) {
    std::cout << "p1 owns the object" << std::endl;
  } else if (p3) {
    std::cout << "p3 owns the object" << std::endl;
  }


  
  return 0;
}
