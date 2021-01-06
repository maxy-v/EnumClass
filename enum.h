#pragma once
#include <vector>
#include <type_traits>
#include <algorithm>

#define DECLARE_ENUM(Name, Type, ...)                                           \
class Name final {                                                              \
    static_assert(std::is_integral<Type>());                                    \
public:                                                                         \
    Name(Type a_value)                                                          \
        : m_value(a_value)                                                      \
    {}                                                                          \
    enum: Type { __VA_ARGS__ };                                                 \
    static const auto count()               { return getValues().size(); }      \
    static const auto value(size_t a_index) { return getValues()[a_index]; }    \
    static const bool isValid(Type a_value) {                                   \
        const auto& values = getValues();                                       \
        auto result = std::find(std::begin(values), std::end(values), a_value); \
        return result != std::end(values);                                      \
    }                                                                           \
    bool isValid() const {                                                      \
        return isValid(m_value);                                                \
    }                                                                           \
    bool operator==(const Type& a_value) const {                                \
        return m_value == a_value;                                              \
    }                                                                           \
    bool operator!=(const Type& a_value) const {                                \
        return m_value != a_value;                                              \
    }                                                                           \
    operator Type() const { return m_value; }                                   \
private:                                                                        \
    static const std::vector<Type>& getValues() {                               \
        enum _TmpEnum:Type { __VA_ARGS__ };                                     \
        static const std::vector<Type> values = { __VA_ARGS__ };                \
        return values;                                                          \
    }                                                                           \
    Type m_value;                                                               \
};
