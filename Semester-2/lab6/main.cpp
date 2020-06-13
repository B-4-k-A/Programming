#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algo.h"
#include "test.h"

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::string str{"radar"};
    std::queue<float> q;
    for (int i = 0; i < 5; i++)
        q.push(i);
    std::vector<CVector3D> v2{{{0, 0}, {2, 2}}, {{1, 5}, {6, -2}}, {{5, 3}, {-5, -2}}, {{2, 0}, {6, 0}}};
    std::cout << "Vector:" << std::endl;
    print(v.begin(), v.end());
    std::cout << "all_of < 6\t: " << all_of(v.begin(), v.end(), cmp) << std::endl;
    std::cout << "is_sorted\t: " << is_sorted(v.begin(), v.end(), cmp_less) << std::endl;
    std::cout << "is_palindrome\t: " << is_palindrome(v.begin(), v.end(), cmp_equal) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "String:" << std::endl;
    print(str.begin(), str.end());
    std::cout << "all_of < 6\t: " << all_of(str.begin(), str.end(), cmp) << std::endl;
    std::cout << "is_sorted\t: " << is_sorted(str.begin(), str.end(), cmp_less) << std::endl;
    std::cout << "is_palindrome\t: " << is_palindrome(str.begin(), str.end(), cmp_equal) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Queue:" << std::endl;
    std::cout << "all_of < 6\t: " << all_of(&q.front(), &q.back(), cmp) << std::endl;
    std::cout << "is_sorted\t: " << is_sorted(&q.front(), &q.back(), cmp_less) << std::endl;
    std::cout << "is_palindrome\t: " << is_palindrome(&q.front(), &q.back(), cmp_equal) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Vector<CVector3D" << std::endl;
    std::cout << "all_of > 2\t: " << all_of(v2.begin(), v2.end(), cmp_vector) << std::endl;
    std::cout << "is_sorted \t: " << is_sorted(v2.begin(), v2.end(), cmp_vector_less) << std::endl;
    std::cout << "is_palindrome\t: " << is_palindrome(v2.begin(), v2.end(), cmp_vector_equal) << std::endl;

    return 0;
}