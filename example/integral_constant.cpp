/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;


int main() {
    {
        //! [integral_constant]
        BOOST_HANA_CONSTANT_ASSERT(
            integral_constant<Integral, int, 2>
            ==
            int_<2>
        );

        BOOST_HANA_CONSTANT_ASSERT(equal(
            integral_constant<StdIntegralConstant, bool, true>,
            std::true_type{}
        ));
        //! [integral_constant]
    }
}