// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2013-2014 The Dogecoin developers
// Copyright (c)      2018 The Artiqox developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0x6ad3d655, 0x9f363f2d,
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xdf;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0x48;
        vAlertPubKey = ParseHex("0454b623a703b0091a70024d318f6c443e755e0519fdf43d4f6df007b6a0bbd57de456ef86be8556a6d8f5f2e123f6aca3a942f994dff6e449987adf6625b4ddc2");
        nDefaultPort = 19427;
        nRPCPort = 19421;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        nSubsidyHalvingInterval = 210000;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        // CBlock(hash=fb0f6b30ccc9852b01c153a6b95d65f22f9b2f46d6874453e70d27671d5cd6c3, input=01000000000000000000000000000000000000000000000000000000000000000000000048c95128675271283f2262ff02baa81688aad0b60e7bed57598e87f3b8cc156ff9a5a55af0ff0f1e24d21300, PoW=00000cb72b569a4493ba1af1b487b45a579594325a340be816e60b951af5702d, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=6f15ccb8f3878e5957ed7b0eb6d0aa8816a8ba02ff62223f287152672851c948, nTime=1520805369, nBits=1e0ffff0, nNonce=1298980, vtx=1)
        //   CTransaction(hash=6f15ccb8f3878e5957ed7b0eb6d0aa8816a8ba02ff62223f287152672851c948, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //     CTxIn(COutPoint(0000000000000000000000000000000000000000000000000000000000000000, 4294967295), coinbase 04ffff001d0104454c6561726e696e6720657870657269656e63653a20596f75206b6e6f772074686174207468696e6720796f75206a757374206469643f20446f6e277420646f20746861742e)
        //     CTxOut(nValue=88.00000000, scriptPubKey=049054f351bc935ccf5f514baa6293)
        //   vMerkleTree: 6f15ccb8f3878e5957ed7b0eb6d0aa8816a8ba02ff62223f287152672851c948 
        const char* pszTimestamp = "Learning experience: You know that thing you just did? Don't do that.";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 88 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("049054f351bc935ccf5f514baa6293bf8b8da93a89b2aab0be37747a2d63a50fcd0281d18d669f1a89c8e44cd8a2062430163ea8ea24bf0211446efa956940d7eb") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1520805369;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 1298980;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xfb0f6b30ccc9852b01c153a6b95d65f22f9b2f46d6874453e70d27671d5cd6c3"));
        assert(genesis.hashMerkleRoot == uint256("0x6f15ccb8f3878e5957ed7b0eb6d0aa8816a8ba02ff62223f287152672851c948"));

        vSeeds.push_back(CDNSSeedData("artiqox.com", "seed.artiqox.com"));

        // Workaround for Boost not being quite compatible with C++11;
        std::vector<unsigned char> pka = list_of(23);
        base58Prefixes[PUBKEY_ADDRESS] = pka;
        
        std::vector<unsigned char> sca = list_of(82);
        base58Prefixes[SCRIPT_ADDRESS] = sca;
        
        std::vector<unsigned char> sk  = list_of(158);
        base58Prefixes[SECRET_KEY]     = sk;
        
        std::vector<unsigned char> epk = list_of(0x04)(0x88)(0x2A)(0x2E);
        base58Prefixes[EXT_PUBLIC_KEY] = epk;
        
        std::vector<unsigned char> esk = list_of(0x04)(0x88)(0xE1)(0xF7);
        base58Prefixes[EXT_SECRET_KEY] = esk;

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const uint64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v2)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xfc;
        pchMessageStart[1] = 0xc1;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xdc;
        vAlertPubKey = ParseHex("046fc2b3f121760a430cd969a1d14ec06d6c4607deab2c8925db70e344f95642a13b61cd7fe043a4ac478c8f85d6622c0678746f0b3278b09109fd3c503ff2e807");
        nDefaultPort = 19459;
        nRPCPort = 19458;
        strDataDir = "testnet2";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1520806619;
        genesis.nNonce = 1651712;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x4f3d4c0b5f1d3e8e8b3945861b91ce118ad34ef14113b439fab0d53a068d224a"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testaiq.artiqox.com", "testaiq-seed.artiqox.com"));

        // Boost sucks, and should not be used. Workaround for Boost not being compatible with C++11;
        
        std::vector<unsigned char> pka = list_of(113);
        base58Prefixes[PUBKEY_ADDRESS] = pka;
        std::vector<unsigned char> sca = list_of(196);
        base58Prefixes[SCRIPT_ADDRESS] = sca;
        std::vector<unsigned char> sk  = list_of(241);
        base58Prefixes[SECRET_KEY]     = sk;
        std::vector<unsigned char> epk = list_of(0x04)(0x35)(0xD1)(0xDF);
        base58Prefixes[EXT_PUBLIC_KEY] = epk;
        std::vector<unsigned char> esk = list_of(0x04)(0x35)(0x75)(0xA4);
        base58Prefixes[EXT_SECRET_KEY] = esk;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1520807336;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1973092;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        assert(hashGenesisBlock == uint256("0xe31c23c98de390242c6fbd5aa303b766d783cb48babd963fad53981da7e4c49c"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual bool SimplifiedRewards() const { return true; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
