#ifndef ULTRASMARTMATRIX_HPP
#define ULTRASMARTMATRIX_HPP

#include <iostream>

template <typename T>
class UltraSmartMatrix {
public:
  void removeColumns();
  // input-output
  template <typename T1>
  friend std::istream& operator>>(std::istream& in, UltraSmartMatrix<T1>& usm);
  template <typename T1>
  friend std::ostream& operator<<(std::ostream& out, const UltraSmartMatrix<T1>& usm);

  UltraSmartMatrix();
  ~UltraSmartMatrix();
  UltraSmartMatrix(const UltraSmartMatrix&) = delete;
  UltraSmartMatrix(UltraSmartMatrix&&) = delete;
  UltraSmartMatrix& operator=(const UltraSmartMatrix&) = delete;
  UltraSmartMatrix& operator=(UltraSmartMatrix&&) = delete;
private:
  static_assert(std::is_integral_v<T>, "T must be an integer type!\n");
  T** cmp_;
  size_t fir_, sec_;
  size_t* action_;
  size_t size_;
  T m_, n_;

  // removing columns
  bool isColumnSuitable(const size_t j) const;
  void reAllocate(const size_t newSize);
  void findSuitableColumns();

  void clean();
};

template <typename T>
std::istream& operator>>(std::istream& in, UltraSmartMatrix<T>& usm);

#endif