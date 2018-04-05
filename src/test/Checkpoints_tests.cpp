// Copyright (c) 2011-2013 The Bitcoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p42279 = uint256("0xc0dd807aa55cde1c421f8eff19751cdc3401f0d5ca0978159bea1e86534454f1");
    uint256 p42400 = uint256("0x9a28408ae1c7c947812d5197335c53bbfcbdea76577632617db92fd5abcee3b0");
    BOOST_CHECK(Checkpoints::CheckBlock(42279, p42279));
    BOOST_CHECK(Checkpoints::CheckBlock(42400, p42400));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(42279, p42400));
    BOOST_CHECK(!Checkpoints::CheckBlock(42400, p42279));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(42279+1, p42400));
    BOOST_CHECK(Checkpoints::CheckBlock(42400+1, p42279));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 42400);
}    

BOOST_AUTO_TEST_SUITE_END()
