//
// Created by zhang on 10/3/22.
//

#include "combination.h"
#include "iostream"

using namespace std;

void combination::genByLoop(int n,int* a) {

    for (a[1] = 1; a[1] <= n; ++a[1]) {
        for (a[2] = a[1]+1; a[2] <= n; ++a[2]) {
            for (a[3] = a[2]+1; a[3] <= n; ++a[3]) {
                cout<<a[1]<<","<<a[2]<<","<<a[3]<<endl;
            }
        }
    }

}

