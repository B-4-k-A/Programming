#include <iterator>


template<class iter, class object>
bool all_of(const iter begin, const iter end, bool(&func)(object)) {
    for(auto it = begin; it != end; it = std::next(it))
        if(!func(*it))
            return false;
    return true;
}

template<class iter, class object>
bool is_sorted(const iter& begin, const iter& end, bool(&func)(object, object)) {
    for(auto it = begin; it != end - 1; it = std::next(it)) {
        for(auto next_it = it + 1; next_it != end; next_it = std::next(next_it)) {
            if(!func(*it, *next_it)) {
                return false;
            }
        }
    }
    return true;
}

template<class iter, class object>
bool is_palindrome(const iter& begin, const iter& end, bool(&func)(object, object)) {
    auto it_ = begin;
    auto _it = (end - 1);
    while(it_ < _it) {
        if(!func(*it_, *_it)) {
            return false;
        }
        it_ = std::next(it_);
        _it = std::prev(_it);
    }
    return true;
}