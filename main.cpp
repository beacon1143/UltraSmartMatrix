#include <fstream>
#include "UltraSmartMatrix.cpp"

int main() {
  try {
    UltraSmartMatrix<int> usm;
    std::ifstream inp("data.dat");
    if (!inp.is_open()) {
      throw std::runtime_error("Error! Cannot open file data.dat!\n");
    }
    inp >> usm;
    inp.close();
    usm.removeColumns();
    std::ofstream out("data.res");
    out << usm;
    out.close();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}