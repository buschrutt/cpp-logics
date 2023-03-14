#include "introduction.h"

[[maybe_unused]] std::vector <int> GetNeighbours(const std::vector <std::vector <int> > &matrix, int row, int col) {
    std::vector <int> rv;
    if (row != 0)
        rv.push_back(matrix[row - 1][col]);
    if (col != 0)
        rv.push_back(matrix[row][col - 1]);
    if (row + 1 != matrix.size())
        rv.push_back(matrix[row + 1][col]);
    if (col + 1 != matrix[0].size())
        rv.push_back(matrix[row][col + 1]);
    std::sort(rv.begin(), rv.end());
    return rv;
}

[[maybe_unused]] int GetWeatherRandomness(const std::vector <int> &temperatures) {
    if (temperatures.size() == 1)
        return 1;
    int randomness = 0;
    if (temperatures[0] > temperatures[1])
        randomness = 1;
    for (int i = 1; i < temperatures.size() - 1; ++i) {
        if (temperatures[i] > temperatures[i + 1] && temperatures[i] > temperatures[i - 1])
            randomness++;
    }
    if (temperatures[temperatures.size() - 1] > temperatures[temperatures.size() - 2])
        randomness++;
    return randomness;
}

[[maybe_unused]] std::string GetLongestWord(const std::string &line) {
    std::string longest_word;
    std::string word;
    for (char chr : line) {
        if (chr == ' ') {
            if (word.size() > longest_word.size()) {
                longest_word = word;
            }
            word = "";
        } else {
            word += chr;
        }
    }
    if (word.size() > longest_word.size())
        longest_word = word;
    return longest_word;
}

[[maybe_unused]] bool IsPalindrome(const std::string &line) {
    std::string r_line, l_line;
    for (auto chr : line){
        if ((chr >= 'a' && chr <= 'z')){
            r_line.push_back(std::toupper(chr));
        }
        if ((chr >= '0' && chr <= '9') || (chr >= 'A' && chr <= 'Z'))
            r_line.push_back(chr);
    }
    l_line = r_line;
    std::reverse(l_line.begin(), l_line.end());
    return l_line == r_line;
}

[[maybe_unused]] std::string ToBinary(int number) {
    if (number == 0)
        return "0";
    std::string binary_representation;
    int n = number;
    while (n != 0) {
        if (n % 2 == 0)
            binary_representation += '0';
        else
            binary_representation += '1';
        if (n == 1) {
            break;
        }
        n = n / 2;
    }
    std::reverse(binary_representation.begin(), binary_representation.end());
    return binary_representation;
}

[[maybe_unused]] std::string GetSum(const std::string &firstNumber, const std::string &secondNumber) {
    std::string sum;
    int res_register = 0;
    char second;
    int def = (int)(firstNumber.size() - secondNumber.size());
    if (firstNumber.size() >= secondNumber.size()) {
        for (int i = (int)firstNumber.size(); i != 0; i--) {
            if (i - 1 - def < 0)
                second = '0';
            else
                second = secondNumber[i - 1 - def];
            int last_register = firstNumber[i - 1] + second + res_register;
            if (last_register == 99) {
                sum += '1';
                res_register = 1;
            } else if (last_register == 98) {
                sum += '0';
                res_register = 1;
            } else if (last_register == 97) {
                sum += '1';
                res_register = 0;
            } else {
                sum += '0';
                res_register = 0;
            }
        }
    }
    else {
        def = def * (-1);
        for (int i = (int)secondNumber.size(); i != 0; i--) {
            if (i - 1 - def < 0)
                second = '0';
            else
                second = firstNumber[i - 1 - def];
            int last_register = secondNumber[i - 1] + second + res_register;
            if (last_register == 99) {
                sum += '1';
                res_register = 1;
            } else if (last_register == 98) {
                sum += '0';
                res_register = 1;
            } else if (last_register == 97) {
                sum += '1';
                res_register = 0;
            } else {
                sum += '0';
                res_register = 0;
            }
        }
    }
    if (res_register == 1)
        sum += '1';
    std::reverse(sum.begin(), sum.end());
    return sum;
}

[[maybe_unused]] std::vector <int> Factorize(int n) {
    std::vector<int> factorized;
    for (int i = 2; i * i <= n; i++){
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) break;
        }
        while (n % i == 0) {
            factorized.push_back(i);
            n = n / i;
        }
    }
    if (n != 1) factorized.push_back(n);
    return factorized;
}

[[maybe_unused]] std::vector<int> GetSum(const std::vector <int> &numberList, int k) {
    int reg = 0;
    int left, right;
    std::vector<int> result_v;
    std::vector<int> left_v;
    std::vector<int> right_v = numberList;
    while (k >= 1) {
        left_v.push_back(k % 10);
        k = (k - k % 10) / 10;
    }
    reverse(left_v.begin(), left_v.end());
    while (!(right_v.empty() && left_v.empty())) {
        if (left_v.empty())
            left = 0;
        else {
            left = left_v.at(left_v.size() - 1);
            left_v.pop_back();
        }
        if (right_v.empty())
            right = 0;
        else {
            right = right_v.at(right_v.size() - 1);
            right_v.pop_back();
        }
        int a = right + left + reg;
        if (a >= 10)
            reg = 1;
        else
            reg = 0;
        result_v.push_back(a % 10);
    }
    if (reg > 0)
        result_v.push_back(reg);
    reverse(result_v.begin(), result_v.end());
    return result_v;
}

[[maybe_unused]] char GetExcessiveLetter(const std::string &shorter, const std::string &longer) {
    auto l = longer;
    for (auto itr = shorter.begin(); itr != shorter.end(); itr++) {
        auto l_itr = find(l.begin(), l.end(), *itr);
        if (l_itr == l.end())
            return *itr;
        l.erase(l_itr);
    }
    return *l.begin();
}

[[maybe_unused]] std::vector<int> DistanceToZero(const std::vector<int> & entry)
{
    int l = 0;
    bool was_zero = false;
    std::vector<int> distances(entry.size());
    for (int i = 0; i < entry.size(); i++) {
        if (entry[i] == 0) {
            if (was_zero) {
                for (int j = 1; j <= l / 2; j++) {
                    distances[i - j] = j;
                }
                for (int j = l / 2 + 1; j <= l; j++) {
                    distances[i - j] = l + 1 - j;
                }
                l = 0;
            } else {
                was_zero = true;
                for (int j = 1; j <= l; j++) {
                    distances[i - j] = j;
                }
                l = 0;
            }
        } else {
            l++;
        }
    }
    if (entry[entry.size() - 1] != 0) {
        for (int j = 1; j <= l; j++) {
            distances[entry.size() - j] = l - j + 1;
        }
    }
    return distances;
}