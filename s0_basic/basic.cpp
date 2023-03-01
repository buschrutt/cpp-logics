#include "basic.h"

using namespace std;

[[maybe_unused]] std::vector <int> zip(const std::vector <int> &a, const std::vector <int> &b)
{
    if (a.size() != b.size())
        throw std::invalid_argument {" --logics zip --vector sizes aren't equal"};
    std::vector <int> x(a.size() * 2);
    auto runner_x = x.begin();
    auto runner_a = a.begin();
    auto runner_b = b.begin();
    while (runner_x != x.end()) {
        *runner_x++ = *runner_a++;
        *runner_x++ = *runner_b++;
    }
    return x;
}

[[maybe_unused]] vector <double> moving_average(const std::vector <int> &arr, int windowSize)
{
    if (arr.size() < windowSize)
        throw std::invalid_argument {" --logics moving_average --vector size less than windowSize"};
    auto runner_arr = arr.begin();
    vector <double> va(arr.size() + 1 - windowSize);
    auto runner_va = va.begin();
    double sum = 0.0;
    for (int i = 0; i < windowSize; i++)
        sum += *runner_arr++;
    *runner_va++ = sum / windowSize;
    auto runner_arr_b = arr.begin();
    while (runner_arr != arr.end()){
        sum += *runner_arr++;
        sum -= *runner_arr_b++;
        *runner_va++ = sum / windowSize;
    }
    return va;
}

[[maybe_unused]] std::vector <int> two_sum(const vector <int> &arr, int targetSum) {
    auto l_runner = arr.begin();
    std::set<int> p = {*l_runner++};
    while (l_runner != arr.end()){
        if (p.count(targetSum - *l_runner))
            return {*l_runner, targetSum - *l_runner};
        p.insert(*l_runner++);
    }
    return {};
}

[[maybe_unused]] std::vector <int> two_sum_ptr(const std::vector <int> &arr, int targetSum)
{
    std::vector <int> arr_copy = arr;
    std::sort(arr_copy.begin(), arr_copy.end());
    auto l_runner = arr_copy.begin();
    auto r_runner = arr_copy.end();
    r_runner--;
    while (l_runner != r_runner) {
        if (*l_runner + *r_runner == targetSum)
            return {*l_runner, *r_runner};
        if (*l_runner + *r_runner < targetSum)
            l_runner++;
        else
            r_runner--;
    }
    return {};
}
