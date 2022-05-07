// Copyright 2022 NNTU-CS

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
    T arr[100];
    int first;
    int last;
    
  public:
    TPQueue() : first(0), last(0) {}
    void push(T z1) {
      if (last - first >= size) {
        throw "Full!";
      } else {
        int z2 = last - 1;
        while ((z2 >= first) && (arr[z2 % size].prior < z1.prior)) {
          arr[(z2 + 1) % size] = arr[z2 % size];
          z2--;
        }
        arr[(z2 + 1) % size] = z1;
        last++;
      }
    }
    T front() {
      return arr[first % size];
    }
    T back() {
      return arr[(last - 1) % size];
    }
    T pop() {
      return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif // INCLUDE_TPQUEUE_H_
