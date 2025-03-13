#include "UltraSmartMatrix.hpp"

/* REMOVING COLUMNS */
template <typename T>
void UltraSmartMatrix<T>::removeColumns() {
  findSuitableColumns();
  std::cout << "Suitable columns are (zero-based numbering):\n";
  for (size_t i = 0; i < size_; i++) {
    std::cout << action_[i] << " ";
  }
  std::cout << "\n";
}
template <typename T>
bool UltraSmartMatrix<T>::isColumnSuitable(const size_t j) const {
  if (j >= sec_) {
    throw std::invalid_argument("Error! In isColumnSuitable(): wrong column index!\n");
  }
  for (size_t i = 0; i < fir_; i++) {
    if ((cmp_[i][j] & m_) != m_) {
      return false;
    }
  }
  return true;
}
template <typename T>
void UltraSmartMatrix<T>::reAllocate(const size_t newSize) {
  size_t* tmp = new size_t[newSize];
  for (size_t i = 0; i < std::min(size_, newSize); i++) {
    tmp[i] = action_[i];
  }
  delete[] action_;
  action_ = tmp;
  size_ = newSize;
}
template <typename T>
void UltraSmartMatrix<T>::findSuitableColumns() {
  size_t nextIdx = 0;
  for (size_t j = 0; j < sec_; j++) {
    if (isColumnSuitable(j)) {
      if (nextIdx >= size_) {
        if (size_ == 0) {
          action_ = new size_t[1];
          size_ = 1;
        }
        else {
          reAllocate(2 * size_);
        }
      }
      action_[nextIdx++] = j;
    } // if (isColumnSuitable)
  } // for
  reAllocate(nextIdx);
}

/* INPUT-OUTPUT */
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
  in >> usm.m_;
  in >> usm.n_;
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
  size_ = 0;
  m_ = 0;
  n_ = 0;
}
template <typename T>
UltraSmartMatrix<T>::~UltraSmartMatrix() {
  clean();
}