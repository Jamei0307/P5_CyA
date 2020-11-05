#include <iostream>
#include <vector>

class Set {
  private:
    int num_elementos_;
    int num_long_;
    std::vector<long> vector_long_; 
  public:   
    Set();
    Set(int);
    ~Set();

    void set_num_elementos(int);
    void set_num_long(int);

    int get_num_elementos();
    int get_num_long();
    std::vector<long> get_long_vect();

    void AddElement(int);
    void RemoveElement(int);
    void ClearSet();
    bool IsEmpty();
    bool CheckSet(int);
    void WriteSet();

    void operator =(Set);
    Set operator +(const Set);
    Set operator -(const Set);
    Set operator *(const Set);
    Set operator !();
    


    //void operator =(const int);
};