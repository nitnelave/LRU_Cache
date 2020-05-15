#include "lru_cache/traits_util.h"

#include "catch_util.h"

namespace lru_cache::internal {

struct Return {};
struct Arg1 {};
struct Arg2 {};

Return simple(Arg1 a) { return {}; }
Return two_arg(Arg1 a, Arg2 b) { return {}; }
Return const_simple(const Arg1& a) { return {}; }
Return const_two_arg(const Arg1& a, const Arg2& b) { return {}; }

TEST_CASE("Result type works with functions", "[traits]") {
  static_assert(std::is_same_v<return_t<decltype(&simple)>, Return>);
  static_assert(std::is_same_v<args_t<decltype(&simple)>, std::tuple<Arg1>>);
  static_assert(std::is_same_v<return_t<decltype(&two_arg)>, Return>);
  static_assert(
      std::is_same_v<args_t<decltype(&two_arg)>, std::tuple<Arg1, Arg2>>);
  static_assert(std::is_same_v<return_t<decltype(&const_simple)>, Return>);
  static_assert(
      std::is_same_v<args_t<decltype(&const_simple)>, std::tuple<const Arg1&>>);
  static_assert(std::is_same_v<return_t<decltype(&const_two_arg)>, Return>);
  static_assert(std::is_same_v<args_t<decltype(&const_two_arg)>,
                               std::tuple<const Arg1&, const Arg2&>>);
}

template <typename T>
struct print_t;

TEST_CASE("Result type works with lambdas", "[traits]") {
  {
    auto simple = [](Arg1 a) -> Return { return {}; };
    auto two_arg = [](Arg1 a, Arg2 b) -> Return { return {}; };
    auto const_simple = [](const Arg1& a) -> Return { return {}; };
    auto const_two_arg = [](const Arg1& a, const Arg2& b) -> Return {
      return {};
    };
    static_assert(std::is_same_v<return_t<decltype(simple)>, Return>);
    static_assert(std::is_same_v<args_t<decltype(simple)>, std::tuple<Arg1>>);
    static_assert(std::is_same_v<return_t<decltype(two_arg)>, Return>);
    static_assert(
        std::is_same_v<args_t<decltype(two_arg)>, std::tuple<Arg1, Arg2>>);
    static_assert(std::is_same_v<return_t<decltype(const_simple)>, Return>);
    static_assert(std::is_same_v<args_t<decltype(const_simple)>,
                                 std::tuple<const Arg1&>>);
    static_assert(std::is_same_v<return_t<decltype(const_two_arg)>, Return>);
    static_assert(std::is_same_v<args_t<decltype(const_two_arg)>,
                                 std::tuple<const Arg1&, const Arg2&>>);
  }

  {
    Return ret;
    auto simple = [&](Arg1 a) -> Return& { return ret; };
    auto two_arg = [&](Arg1 a, Arg2 b) -> Return& { return ret; };
    auto const_simple = [&](const Arg1& a) -> Return& { return ret; };
    auto const_two_arg = [&](const Arg1& a, const Arg2& b) -> Return& {
      return ret;
    };
    static_assert(std::is_same_v<return_t<decltype(simple)>, Return&>);
    static_assert(std::is_same_v<args_t<decltype(simple)>, std::tuple<Arg1>>);
    static_assert(std::is_same_v<return_t<decltype(two_arg)>, Return&>);
    static_assert(
        std::is_same_v<args_t<decltype(two_arg)>, std::tuple<Arg1, Arg2>>);
    static_assert(std::is_same_v<return_t<decltype(const_simple)>, Return&>);
    static_assert(std::is_same_v<args_t<decltype(const_simple)>,
                                 std::tuple<const Arg1&>>);
    static_assert(std::is_same_v<return_t<decltype(const_two_arg)>, Return&>);
    static_assert(std::is_same_v<args_t<decltype(const_two_arg)>,
                                 std::tuple<const Arg1&, const Arg2&>>);
  }
}

struct Simple {
  Return operator()(Arg1 a) { return {}; }
};

struct TwoArg {
  Return operator()(Arg1 a, Arg2 b) { return {}; }
};

struct ConstSimple {
  Return operator()(const Arg1& a) { return {}; }
};

struct ConstTwoArg {
  Return operator()(const Arg1& a, const Arg2& b) { return {}; }
};

TEST_CASE("Result type works with non-const operator in classes", "[traits]") {
  static_assert(std::is_same_v<return_t<Simple>, Return>);
  static_assert(std::is_same_v<args_t<Simple>, std::tuple<Arg1>>);
  static_assert(std::is_same_v<return_t<TwoArg>, Return>);
  static_assert(
                std::is_same_v<args_t<TwoArg>, std::tuple<Arg1, Arg2>>);
  static_assert(std::is_same_v<return_t<ConstSimple>, Return>);
  static_assert(std::is_same_v<args_t<ConstSimple>,
                std::tuple<const Arg1&>>);
  static_assert(std::is_same_v<return_t<ConstTwoArg>, Return>);
  static_assert(std::is_same_v<args_t<ConstTwoArg>,
                std::tuple<const Arg1&, const Arg2&>>);
}

}  // namespace lru_cache::internal
