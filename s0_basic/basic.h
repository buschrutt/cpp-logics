#ifndef CPP_LOGICS_BASIC_H
#define CPP_LOGICS_BASIC_H

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/// Returns vector<int> of 2n size, that combines two vectors of n size,
/// and where input vectors elements alternate.
/// The relative order of the elements from input vectors are preserved
[[maybe_unused]] std::vector <int> zip(const std::vector <int> &a, const std::vector <int> &b);

/// Moving Average calculation
/// Given a series of numbers --arr and a fixed subset size --windowSize
/// Returns a series of averages of different subsets
[[maybe_unused]] std::vector <double> moving_average(const std::vector <int> &arr, int windowSize);

/// Returns indices of two elements in the vector --arr such that,
/// when we add these two elements it's equal to the target sum given
/// Returns empty vector if not found
/// Using set to check that next elem has desired value in checked plurality
[[maybe_unused]] std::vector <int> two_sum(const std::vector <int> &arr, int targetSum);
/// Using two pointers
[[maybe_unused]] std::vector <int> two_sum_ptr(const std::vector <int> &arr, int targetSum);

#endif //CPP_LOGICS_BASIC_H
