/*!
@file
Forward declares `boost::hana::unique`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_UNIQUE_HPP
#define BOOST_HANA_FWD_UNIQUE_HPP

#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/by_fwd.hpp>


namespace boost { namespace hana {
    //! Removes all consecutive duplicate elements from a Sequence.
    //! @relates Sequence
    //!
    //! Given a `Sequence` and an optional binary predicate, `unique` returns
    //! a new sequence containing only the first element of every subrange
    //! of the original sequence whose elements are all equal. In other words,
    //! it turns a sequence of the form `[a, a, b, c, c, c, d, d, d, a]` into
    //! a sequence `[a, b, c, d, a]`. The equality of two elements is
    //! determined by the provided `predicate`, or by `equal` if no
    //! `predicate` is provided.
    //!
    //!
    //! Signature
    //! ---------
    //! Given a `Sequence` `S(T)`, a `Logical` `Bool` and a binary predicate
    //! \f$ T \times T \to Bool \f$, `unique` has the following signature:
    //! \f[
    //!     \mathtt{unique} : S(T) \times (T \times T \to Bool) \to S(T)
    //! \f]
    //!
    //! @param xs
    //! The sequence from which to remove consecutive duplicates.
    //!
    //! @param predicate
    //! A function called as `predicate(x, y)`, where `x` and `y` are adjacent
    //! elements of the sequence, and returning a `Logical` representing
    //! whether `x` and `y` should be considered equal. `predicate` should
    //! define an [equivalence relation][1] over the elements of the sequence.
    //! In the current implementation of the library, `predicate` has to
    //! return a compile-time `Logical`. This parameter is optional; it
    //! defaults to `equal` if it is not provided, which then requires the
    //! elements of the sequence to be compile-time `Comparable`.
    //!
    //! ### Example
    //! @snippet example/sequence.cpp unique
    //!
    //!
    //! Syntactic sugar (`unique.by`)
    //! -----------------------------
    //! `unique` can be called in an alternate way, which provides a nice
    //! syntax, especially in conjunction with the `comparing` combinator:
    //! @code
    //!     unique.by(predicate, xs) == unique(xs, predicate)
    //!     unique.by(predicate) == unique(-, predicate)
    //! @endcode
    //!
    //! where `unique(-, predicate)` denotes the partial application of
    //! `unique` to `predicate`.
    //!
    //!
    //! Example
    //! -------
    //! @snippet example/sequence.cpp unique.by
    //!
    //! [1]: http://en.wikipedia.org/wiki/Equivalence_relation#Definition
#if defined(BOOST_HANA_DOXYGEN_INVOKED)
    constexpr auto unique = [](auto&& xs[, auto&& predicate]) {
        return tag-dispatched;
    };
#else
    template <typename S, typename = void>
    struct unique_impl : unique_impl<S, when<true>> { };

    struct unique_t : detail::by<unique_t> {
        template <typename Xs>
        constexpr auto operator()(Xs&& xs) const;

        template <typename Xs, typename Predicate>
        constexpr auto operator()(Xs&& xs, Predicate&& predicate) const;
    };

    constexpr unique_t unique{};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_UNIQUE_HPP