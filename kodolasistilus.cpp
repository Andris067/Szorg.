#include <iostream>

struct Par{
  int elso;
  int masodik;
};

void rendezes(Par* adat, int hossz) {
  for (int i = 0; i < hossz; ++i) {
    for (int j = 0; j < hossz - 1; ++j) {
      if (adat[j].elso > adat[j + 1].elso) {
        int seged = adat[j].elso;
        adat[j].elso = adat[j + 1].elso;
        adat[j + 1].elso = seged;

        seged = adat[j].masodik;
        adat[j].masodik = adat[j + 1].masodik;
        adat[j + 1].masodik = seged;
      }
    }
  }
}

void elvalaszto_egyenlo() {
  std::cout << "===" << std::endl;
}

void elvalaszto_gondolatjel() {
  std::cout << "---" << std::endl;
}

void Output() {
  std::cout << "Output:" << std::endl;
}

void eredmeny_kiiras(const Par* Array, int hossz) {
  for (int i = 0; i < hossz; ++i) {
    int x = Array[i].elso;
    int y = Array[i].masodik;
    int eredmeny = 0;

    if (x % 2 == 0) {
      if (y % 2 == 0) {
        eredmeny = x * y;
      } else {
        eredmeny = x + y;
      }
    } else {
      if (y % 2 == 0) {
        eredmeny = x - y;
      } else {
        eredmeny = x;
      }
    }

    std::cout << eredmeny << std::endl;
  }
}

void execute(Par* adat, int hossz) {
  rendezes(adat, hossz);
  elvalaszto_egyenlo();
  Output();
  elvalaszto_gondolatjel();
  eredmeny_kiiras(adat, hossz);
}

int main() {
  Par Array[5];
  Array[0].elso = 5;
  Array[0].masodik = 1;
  Array[1].elso = 2;
  Array[1].masodik = 4;
  Array[2].elso = 3;
  Array[2].masodik = 7;
  Array[3].elso = 1;
  Array[3].masodik = 6;
  Array[4].elso = 4;
  Array[4].masodik = 5;

  execute(Array, 5);

  return 0;
}
