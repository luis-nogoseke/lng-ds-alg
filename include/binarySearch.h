#include <iterator>

namespace lnfAlg {

template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val)
{
    InputIterator it;
    InputIterator end = last;
    it = (last - first) / 2 + first;
    while ((first <= last) && it != end) {
        if (*it == val) {
            return it;
        }
        if (*it < val) {
            first = it + 1;
        }
        else {
            last = it - 1;
        }
        it = (last - first) / 2 + first;
    }
    return end;
}
}  // namespace lnfAlg