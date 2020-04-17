#pragma once

#include <iostream>
#include <cmath>
#include "Stack.h"
#include "Exception.h"

template <class T, class U>
T pov(T a, U b) {
    try {
        if(sizeof(b) != sizeof(int))
            throw Exception("Degree is not integer \nError 1 function pov(T a, U b)");
        return pow(a, b);
    }
    catch (Exception& ex) {
        ex.print();
    }
    return 0;
}