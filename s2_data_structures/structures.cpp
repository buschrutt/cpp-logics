#include "structures.h"

[[maybe_unused]] std::vector<std::vector<int>> MatrixTransposition(std::vector<std::vector<int>> matrix)
{
    if (matrix.empty())
        return matrix;
    std::vector<std::vector<int>> rev_matrix (matrix.at(0).size(), std::vector<int>(matrix.size()));
    for (int i = 0; i < matrix.at(0).size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            std::swap(rev_matrix[i][j], matrix[j][i]);
        }
    }
    return rev_matrix;
}

Node::Node(int value, Node* next, Node* prev): value(value), next(next), prev(prev)
{
    if (prev == nullptr)
        max = value;
    else if (prev->max > value)
        max = prev->max;
    else
        max = value;
}

[[maybe_unused]] int StackMaxEffective::push (int x)
{
    if (tail_ == nullptr)
        tail_ = new Node(x, nullptr, nullptr);
    else {
        Node* node = new Node(x, nullptr, tail_);
        tail_->next = node;
        tail_ = node;
    }
    return tail_->value;
}

[[maybe_unused]] int StackMaxEffective::pop ()
{
    if (tail_ == nullptr)
        throw std::out_of_range{"StackMax > pop: empty StackMax"};
    int v = tail_->value;
    auto ptr_to_delete = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr)
        tail_->next = nullptr;
    delete ptr_to_delete;
    return v;
}

[[maybe_unused]] [[nodiscard]] int StackMaxEffective::get_max() const
{
    if (tail_ == nullptr)
        throw std::out_of_range{"StackMax > get_max: empty StackMax"};
    return tail_->max;
}

[[maybe_unused]] bool IsCorrectBracketSeq(const std::string & s) {
    if (s.empty())
        return true;
    if (!std::all_of(s.begin(), s.end(), [](char c){return (c == '{' || c == '[' || c == '(' || c == ')' || c == ']' || c == '}');}))
        return false;
    std::map<char, char> m = {{'}', '{'}, {')', '('}, {']', '['}};
    std::deque<char> _stack;
    for (char c : s) {
        if ((c == '}' || c == ')' || c == ']') && _stack.empty())
            return false;
        if (c == '{' || c == '(' || c == '[')
            _stack.emplace_back(c);
        else if (m.at(c) == _stack.back())
            _stack.pop_back();
        else
            return false;
    }
    return _stack.empty();
}

[[maybe_unused]] int MyQueue::put (int x)
{
    if (tail_ == nullptr) {
        tail_ = new Node_q(x, nullptr, nullptr);
        head_ = tail_;
    }
    else {
        auto* node = new Node_q(x, nullptr, tail_);
        tail_->next = node;
        tail_ = node;
    }
    size_++;
    return tail_->value;
}

[[maybe_unused]] int MyQueue::get ()
{
    if (size_ == 0)
        throw std::out_of_range{"StackMax > get: empty MyQueue"};
    int _h = head_->value;
    auto ptr_to_delete = head_;
    head_ = head_->next;
    if (head_ != nullptr)
        head_->prev = nullptr;
    else
        tail_ = nullptr;
    delete ptr_to_delete;
    size_--;
    return _h;
}

[[maybe_unused]] [[nodiscard]] int MyQueue::size() const
{
    return size_;
}

int RecursiveFibonacci (int n)
{
    if (n == 0 || n == 1)
        return 1;
    return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}