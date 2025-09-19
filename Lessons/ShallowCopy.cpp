#include "iostream"

using namespace std;

class ShallowCopy {
  private:
    int* data;

  public:
    ShallowCopy(int value) : data(new int(value)) { return; }
    ShallowCopy(const ShallowCopy& other) : data(other.data) { return; };
    ~ShallowCopy() { delete data; }

    void setData(int value) { *data = value; }
    void printData() { cout << "data: " << *data << endl; }
};
/*
int main(void) {
    ShallowCopy obj1(5);
    ShallowCopy obj2(obj1);
    obj1.printData();
    obj2.printData();
    obj1.setData(10);
    obj1.printData();
    obj2.printData();
}
 */
