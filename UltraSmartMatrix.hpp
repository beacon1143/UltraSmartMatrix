#ifndef ULTRASMARTMATRIX_HPP
#define ULTRASMARTMATRIX_HPP

#include <iostream>

template <typename T>
class UltraSmartMatrix {
private:
  T** cmp_;
  size_t fir_, sec_;
  size_t* action_;
public:
  template <typename T1>
  friend std::istream& operator>>(std::istream& in, UltraSmartMatrix<T1>& usm);
  template <typename T1>
  friend std::ostream& operator<<(std::ostream& out, const UltraSmartMatrix<T1>& usm);

  void clean();

  UltraSmartMatrix();
  ~UltraSmartMatrix();

  UltraSmartMatrix(const UltraSmartMatrix&) = delete;
  UltraSmartMatrix(UltraSmartMatrix&&) = delete;
  UltraSmartMatrix& operator=(const UltraSmartMatrix&) = delete;
  UltraSmartMatrix& operator=(UltraSmartMatrix&&) = delete;
};

template <typename T>
std::istream& operator>>(std::istream& in, UltraSmartMatrix<T>& usm);

#endif