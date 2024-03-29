#ifndef CPP_LOGICS_STRUCTURES_H
#define CPP_LOGICS_STRUCTURES_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // std::all_of
#include <deque>
#include <map>

/// A: Matrix columns to rows Transposition
[[maybe_unused]] std::vector<std::vector<int>> MatrixTransposition(std::vector<std::vector<int>> matrix);

/// StackMaxEffective
struct Node {
    Node(int value, Node* next, Node* prev);
    int value;
    [[maybe_unused]] Node* next;
    Node* prev;
    int max;
};

class [[maybe_unused]] StackMaxEffective {
public:
    [[maybe_unused]] int push (int x);

    [[maybe_unused]] int pop ();

    [[maybe_unused]] [[nodiscard]] int get_max() const;

private:
    Node* tail_ = nullptr;
};
/// END OF StackMaxEffective

/// Checks id s is a correct bracket sequence
[[maybe_unused]] bool IsCorrectBracketSeq(const std::string & s);

/// MyQueue
struct Node_q {
    Node_q(int value, Node_q* next, Node_q* prev): value(value), next(next), prev(prev) {}
    int value;
    [[maybe_unused]] Node_q* next;
    [[maybe_unused]] Node_q* prev;
};

class [[maybe_unused]] MyQueue{
public:

    [[maybe_unused]] int put (int x);

    [[maybe_unused]] int get ();

    [[maybe_unused]] [[nodiscard]] int size() const;

private:
    Node_q* head_ = nullptr;
    Node_q* tail_ = nullptr;
    int size_ = 0;
};
/// END OF MyQueue

/// Recursive Fibonacci sequence calculation
int RecursiveFibonacci (int n);

/// BEGIN OF MyDequeueSized
class [[maybe_unused]] MyDequeueSized{
public:
    [[maybe_unused]] explicit MyDequeueSized(int _size);

    [[maybe_unused]] void push_back (int x);

    [[maybe_unused]] void push_front (int x);

    [[maybe_unused]] int pop_back ();

    [[maybe_unused]] int pop_front ();

private:
    int head_ = 0;
    int tail_ = 0;
    std::vector<int> arr_;
    int size_ = 0;
    int max_size_;
};
/// END OF MyDequeueSized

/// Execute Postfix Notation Expression; _str is parsed vector of operands and operators
[[maybe_unused]] int ExecutePostfixNotationExpression(const std::vector<std::string>& _str);

#endif //CPP_LOGICS_STRUCTURES_H
