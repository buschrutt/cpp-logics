#ifndef CPP_LOGICS_INTRODUCTION_H
#define CPP_LOGICS_INTRODUCTION_H

#include <vector>
#include <algorithm>
#include <string>

///Returns for a matrix element all its neighbors
[[maybe_unused]] std::vector <int> GetNeighbours(const std::vector <std::vector <int> > &matrix, int row, int col);

///Returns number of days that have max temp higher than neighbors
[[maybe_unused]] int GetWeatherRandomness(const std::vector <int> &temperatures);

///E: Returns longest word in the string
[[maybe_unused]] std::string GetLongestWord(const std::string &line);

///F: Checks if line is Palindrome
[[maybe_unused]] bool IsPalindrome(const std::string &line);

///G: Returns binary representation of int number
[[maybe_unused]] std::string ToBinary(int number);

///G: Binary addition
[[maybe_unused]] std::string GetSum(const std::string &firstNumber, const std::string &secondNumber);

///J: Factorizes the number
[[maybe_unused]] std::vector <int> Factorize(int n);

///K: The input is the number of digits of the number X,
/// the list form of the non-negative number X and the non-negative number K.
/// Return the vector of the number X + K
[[maybe_unused]] std::vector<int> GetSum(const std::vector <int> &numberList, int k);

///J: Finds extra char in the longer string
[[maybe_unused]] char GetExcessiveLetter(const std::string &shorter, const std::string &longer);

///FINAL 1_1: Returns distances to zero from each entry elements
[[maybe_unused]] std::vector<int> DistanceToZero(const std::vector<int> & entry);

#endif //CPP_LOGICS_INTRODUCTION_H
