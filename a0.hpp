/*  ZeMing 
 *  Zhang
 *  zemingzh
 */

#ifndef A0_HPP
#define A0_HPP
#include <chrono>
#include <iostream>
#include <vector>

void filter_2d(int n, int m, const std::vector<float>& K, std::vector<float>& A) {
  int KA1 = K[0], KA2 = K[1], KA3 = K[2];
  int KB1 = K[3], KB2 = K[4], KB3 = K[5];
  int KC1 = K[6], KC2 = K[7], KC3 = K[8];

  std::vector<float> holderA = A;

  #pragma omp parallel for shared(holderA) collapse(2)
  for (int rowIdx = 1; rowIdx < n-1 ; ++rowIdx){
    for (int colIdx = 1; colIdx< m-1 ; ++colIdx){
      int center = (rowIdx * m) + (colIdx);
      int top = center - m;
      int bottom = center + m;

      int A1 = A[top -1], A2 = A[top], A3 = A[top+1];
      int B1 = A[center -1], B2 = A[center], B3 = A[center+1];
      int C1 = A[bottom -1], C2 = A[bottom], C3 = A[bottom+1];

      int r0c0 = (A1*KA1) + (A2*KB1) + (A3*KC1), r0c1 = (A1*KA2) + (A2*KB2) + (A3*KC2), r0c2 = (A1*KA3) + (A2*KB3) + (A3*KC3);
      int r1c0 = (B1*KA1) + (B2*KB1) + (B3*KC1), r1c1 = (B1*KA2) + (B2*KB2) + (B3*KC2), r1c2 = (B1*KA3) + (B2*KB3) + (B3*KC3);
      int r2c0 = (C1*KA1) + (C2*KB1) + (C3*KC1), r2c1 = (C1*KA2) + (C2*KB2) + (C3*KC2), r2c2 = (C1*KA3) + (C2*KB3) + (C3*KC3);

      int updateCenter = r0c0 + r0c1 + r0c2 + r1c0 + r1c1 + r1c2 + r2c0 + r2c1 + r2c2;
      holderA[center] = updateCenter; 
    }
  }
  A = holderA;   
  
} // filter_2d

#endif // A0_HPP
 
