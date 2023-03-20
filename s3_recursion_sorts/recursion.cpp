#include "recursion.h"

int FindFirstNSmallerNumber(const std::vector<int>& _day_sum,int _price, int left, int right)
{
    if (right < left)
        return - 1;
    int pos = (left + right) / 2;
    if ((_day_sum[pos] >= _price && pos == 0) || (_day_sum[pos] >= _price && _day_sum[pos - 1] < _price))
        return pos + 1;
    else if (_day_sum[pos] >= _price)
        FindFirstNSmallerNumber(_day_sum, _price, left, pos);
    else
        FindFirstNSmallerNumber(_day_sum, _price, pos + 1, right);
}
