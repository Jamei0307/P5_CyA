#include <iostream>
#include <vector>

#include "Set.h"

Set::Set(){
  vector_long_.push_back(0);
  num_long_ = 1;
  num_elementos_ = 8 * sizeof(long);
}

Set::Set(int num) {
  num_elementos_ = num;
  num_long_ = (num / (8 * sizeof(long))) + 1;
  for (int i = 0; i < num_long_; i++) {
    vector_long_.push_back(0);
  }      
}

Set::~Set(){}

void Set::set_num_elementos(int elementos) { num_elementos_ = elementos; }
void Set::set_num_long(int longs) { num_long_ = longs; }

int Set::get_num_elementos() { return num_elementos_; }
int Set::get_num_long() { return num_long_; }
std::vector<long> Set::get_long_vect() { return vector_long_; }

void Set::AddElement(int num) {
  unsigned int posicion_vect = num / (8 * sizeof(long));
  int desp = num % (8 * sizeof(long));
  if (num >= num_elementos_) {
    std::cout << "ERROR: Al insertar un elemento." 
              << "Sobrepasa el rango del long: [0-" 
              << (num_elementos_ - 1) << "].\n"; 
    exit(1); 
  }
  if ((*this).CheckSet(num)) {
    std::cout << "ERROR: No se puede insertar un elemento" 
              << "que ya pertenece al conjunto.\n";
    exit(1);
  }
  vector_long_[posicion_vect] = vector_long_[posicion_vect] | (1 << desp);
}

void Set::RemoveElement(int num) {
  int posicion_vect = num / (8 * sizeof(long));
  int desp = num % (8 * sizeof(long));
  if (num >= num_elementos_) {
    std::cout << "ERROR: Al borrar un elemento." 
              << "Sobrepasa el rango del long: [0-" 
              << (num_elementos_ - 1) << "].\n"; 
    exit(1); 
  }
  if (!(*this).CheckSet(num)) {
    std::cout << "ERROR: No se puede eliminar un elemento" 
              << "que no pertenece al conjunto.\n";
    exit(1);
  }
  vector_long_[posicion_vect] = vector_long_[posicion_vect] & ~(1 << desp);
}

void Set::ClearSet() {
  for (int i = 0; i < num_long_; i++){
    for (unsigned int j = (i * 8 * sizeof(long)); j < ((i + 1) * 8 * sizeof(long)); j++) {
        if (vector_long_[i] & (1 << j)) 
        vector_long_[i] = vector_long_[i] & ~(1 << j);
    }
  } 
}

bool Set::IsEmpty() {
  for (int i = 0; i < num_long_; i++){
    for (unsigned int j = (i * 8 * sizeof(long)); j < ((i + 1) * 8 * sizeof(long)); j++) {
      if (vector_long_[i] & (1 << j)) 
        return false;
    }
  }
  return true; 
}

bool Set::CheckSet(int num) {
  int posicion_vect = num / (8 * sizeof(long));
  int desp = num % (8 * sizeof(long));
  if (vector_long_[posicion_vect] & (1 << desp)) return true;
  return false;
}

void Set::WriteSet() {
  for (int i = 0; i < num_long_; i++){
    for (unsigned int j = (i * 8 * sizeof(long)); j < ((i + 1) * 8 * sizeof(long)); j++) { 
      if (vector_long_[i] & (1 << j))
        std::cout << j << " "; 
    }
  }
}


void Set::operator =(Set Set1) {
  
}

Set Set::operator +(Set Set1) {
  if (num_elementos_ < Set1.get_num_elementos()) {
    Set aux(Set1.get_num_elementos());
    int carry = 0;
    for (int i = 0; i < num_long_; i++) {
      aux.get_long_vect()[i] = vector_long_[i] | Set1.get_long_vect()[i]; 
      carry++;
    }
    for (int i = carry; i < Set1.get_num_long(); i++) {
      aux.get_long_vect()[i] = Set1.get_long_vect()[i];
    } 
    return aux;
  } else { 
    Set aux(num_elementos_);
    int carry = 0;
    for (int i = 0; i < Set1.get_num_long(); i++) {
      aux.get_long_vect()[i] = vector_long_[i] | Set1.get_long_vect()[i]; 
      carry++;
    }
    for (int i = carry; i < num_long_; i++) {
      aux.get_long_vect()[i] = vector_long_[i];
    }
    return aux; 
  }
}
/*     Set operator -(const Set);
    Set operator *(const Set);
    Set operator !(); */