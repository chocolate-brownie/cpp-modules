#include "iostream"
#include <limits>

using namespace std;

class DeepCopy {
  private:
    int* data;

  public:
    DeepCopy(int value) : data(new int(value)) { return; }
    DeepCopy(const DeepCopy& other) : data(new int(*other.data)) { return; };
    DeepCopy& operator=(const DeepCopy& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
    ~DeepCopy() { delete data; }

    void setData(int value) { *data = value; }
    void printData() { cout << "data: " << *data << endl; }
};

int main(void) {
    DeepCopy obj1(5);
    DeepCopy obj2(obj1);

    obj1.printData();
    obj2.printData();

    obj1.setData(10);
    DeepCopy obj3 = obj1;

    obj1.printData();
    obj2.printData();
    obj3.printData();
}
