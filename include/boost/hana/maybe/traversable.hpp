/*!
@file
Defines the instance of `boost::hana::Traversable` for `boost::hana::Maybe`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_MAYBE_TRAVERSABLE_HPP
#define BOOST_HANA_MAYBE_TRAVERSABLE_HPP

#include <boost/hana/applicative/applicative.hpp>
#include <boost/hana/functor/functor.hpp>
#include <boost/hana/maybe/maybe.hpp>
#include <boost/hana/traversable/traverse_mcd.hpp>


namespace boost { namespace hana {
    //! Instance of `Traversable` for `Maybe`s.
    //!
    //! Traversing `nothing` yields `nothing` in the new applicative, and
    //! traversing `just(x)` applies the function and maps `just` inside
    //! the resulting applicative.
    //!
    //! ### Example
    //! @snippet example/maybe/traversable.cpp main
    template <>
    struct Traversable::instance<Maybe> : Traversable::traverse_mcd {
        template <typename A, typename M, typename F>
        static constexpr auto traverse_impl(M mx, F f) {
            return maybe(
                lift<A>(nothing),
                [=](auto x) { return fmap(f(x), just); },
                mx
            );
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_MAYBE_TRAVERSABLE_HPP