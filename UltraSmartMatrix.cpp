#include "UltraSmartMatrix.hpp"

template <typename T>
std::istream& operator>>(std::istream& in, UltraSmartMatrix<T>& usm) {
  usm.clean();
  in >> usm.fir_;
  usm.cmp_ = new T*[usm.fir_];
  in >> usm.sec_;
  for (size_t i = 0; i < usm.fir_; i++) {
    usm.cmp_[i] = new T[usm.sec_];
  }
  for (size_t i = 0; i < usm.fir_; i++) {
    for (size_t j = 0; j < usm.sec_; j++) {
      in >> usm.cmp_[i][j];
    }
  }
  return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const UltraSmartMatrix<T>& usm) {
  for (size_t i = 0; i < usm.fir_; i++) {
    for (size_t j = 0; j < usm.sec_; j++) {
      out << usm.cmp_[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}

template <typename T>
void UltraSmartMatrix<T>::clean() {
  if (cmp_ != nullptr) {
    for (size_t i = 0; i < fir_; i++) {
      if (cmp_[i] != nullptr) {
        delete[] cmp_[i];
        cmp_[i] = nullptr;
      }
    }
    delete[] cmp_;
    cmp_ = nullptr;
  }
  if (action_ != nullptr) {
    delete[] action_;
    action_ = nullptr;
  }
}

template <typename T>
UltraSmartMatrix<T>::UltraSmartMatrix() {
  cmp_ = nullptr;
  fir_ = 0;
  sec_ = 0;
  action_ = nullptr;
}

template <typename T>
UltraSmartMatrix<T>::~UltraSmartMatrix() {
  clean();
}