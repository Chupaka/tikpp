#ifndef TIKPP_DATA_CONVERTERS_PROPLIST_COLLECTOR_HPP
#define TIKPP_DATA_CONVERTERS_PROPLIST_COLLECTOR_HPP

#include <string>
#include <utility>

namespace tikpp::data::converters {

template <typename Container>
struct proplist_collector {
    struct [[nodiscard]] dummy_wrapper {
        template <typename T> void operator%(T &&value) {}
    };

    inline auto operator()(std::string key) -> dummy_wrapper {
        proplist.emplace_back(std::move(key));
        return dummy_wrapper {};
    }

    inline auto operator()(std::string key,
                           [[maybe_unused]] const std::string &)
        -> dummy_wrapper {
        return operator()(std::move(key));
    }

    Container proplist;
};

} // namespace tikpp::data::converters

#endif
