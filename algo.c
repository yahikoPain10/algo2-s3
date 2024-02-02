#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void fillRandom(int T[], int n, int min, int max) {
  int i;
  for(i = 0; i < n; i++) {
    T[i] = (rand() % (max - min)) + min;
  }
}

void swap(int T[], int i, int j) {
  int temp = T[i];
  T[i] = T[j];
  T[j] = temp;
}

void printTable(int T[], int n) {
  int i;
  printf("[ ");
  for(i = 0; i < n; i++) {
    printf("%d ", T[i]);
  }
  printf("] \n");
}

// Sorting algorithms

void bubbleSort(int T[], int n) {
  int i, reloop;
  do {
    reloop = 0;
    for(i = 0; i < n - 1; i++) {
      if(T[i] > T[i+1]) {
        swap(T, i, i+1);
        reloop = 1;
      }
    }
  }while(reloop);
}

void selectSort(int T[], int n) {
  int imin, i, j;
  for(i = 0; i < n - 1; i++) {
    imin = i;
    for(j = i + 1; j < n; j++) {
      if(T[imin] > T[j]) imin = j;
    }
    if(imin != i) swap(T, i, imin);
  }
}

void insertSort(int T[], int n) {
  int i, j;
  for(i = 1; i < n; i++) {
    for(j = i; j > 0; j--) {
      if(T[j] < T[j - 1]) swap(T, j, j - 1);
    }
  }
}

// Merge sort

void copy(int T[], int s, int e, int C[]) {
  int i, j;
  for(i = s, j = 0; i < e; i++, j++) {
    C[j] = T[i];
  }
}

void merge(int L[], int lsize, int R[], int rsize, int T[]) {
  int i = 0, l = 0, r = 0;
  while(l < lsize && r < rsize) {
    if(L[l] < R[r]) {
      T[i] = L[l];
      l++; i++;
    }
    else {
      T[i] = R[r];
      r++; i++;
    }
  }

  while(l < lsize) {
    T[i] = L[l];
    l++; i++;
  }

  while(r < rsize) {
    T[i] = R[r];
    r++; i++;
  }
}

void mergeSort(int T[], int n) {
  int L[MAX], R[MAX], middle = n / 2;
  if(n <= 1) return;
  copy(T, 0, middle, L);
  copy(T, middle, n, R);
  mergeSort(L, middle);
  mergeSort(R, n - middle);
  merge(L, middle, R, n - middle, T);
}

// Quick sort

int partition(int T[], int s, int e) {
  int i, j, p;
  for(i = s-1,j = s, p = T[e]; j <= e; j++) {
    if(T[j] < p) swap(T, ++i, j);
  }
  swap(T, ++i, e);
  return i;
}

void quickSort(int T[], int s, int e) {
  int p;
  if(s >= e) return;
  p = partition(T, s, e);
  quickSort(T, s, p-1);
  quickSort(T, p+1, e);
}

// Structures

struct Position {
  int x;
  int y;
};

int multiByRef(struct Position *pos) {
  return pos->x * pos->y;
}

int multi(struct Position pos) {
  return pos.x * pos.y;
}

void declareStruct() {
  struct Position pos;
  pos.x = 10;
  pos.y = 919;
}

int fibR(int n) {
  if(n <= 1) return n;
  return fibR(n - 1) + fibR(n - 2);
}

int fibI(int n) {
  int f0, f1, f, i;
  if(n <= 1) return n;
  for(i = 2; i <= n; i++) {
    f = f0 + f1;
    f0 = f1;
    f1 = f;
  }
  return f;
}

int binarySearch(int T[], int n, int x) {
  int d = 0, f = n - 1, m;
  while(d <= f) {
    m = (d+f)/2;
    if(T[m] == x) return m;
    else if(x > T[m]) d = m + 1;
    else f = m - 1;
  }
  return -1;
}

int main() {
  return 0;
}