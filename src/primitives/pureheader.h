// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_PRIMITIVES_PUREHEADER_H
#define BITCOIN_PRIMITIVES_PUREHEADER_H

#include "serialize.h"
#include "uint256.h"

/**
 * Encapsulate a block version.  This takes care of building it up
 * from a base version, the modifier flags (like auxpow) and
 * also the auxpow chain ID.
 */
class CBlockVersion
{
private:
    /* Modifiers to the version.  */
    static const int32_t VERSION_AUXPOW = (1 << 8);

    /** Bits above are reserved for the auxpow chain ID.  */
    static const int32_t VERSION_CHAIN_START = (1 << 16);

    /** The version as integer.  Should not be accessed directly.  */
    int nVersion;

public:
    inline CBlockVersion()
    {
        SetNull();
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
    {
        READWRITE(this->nVersion);
    }

    inline void SetNull()
    {
        nVersion = 0;
    }

    /**
     * Extract the chain ID.
     * @return The chain ID encoded in the version.
     */
    inline int32_t GetChainId() const
    {
        return nVersion >> 16;
    }

    /**
     * Set the chain ID.  This is used for the test suite.
     * @param ch The chain ID to set.
     */
    inline void SetChainId(int32_t chainId)
    {
        nVersion %= VERSION_CHAIN_START;
        nVersion |= chainId * VERSION_CHAIN_START;
    }

    /**
     * Extract the full version.  Used for RPC results and debug prints.
     * @return The full version.
     */
    inline int32_t GetFullVersion() const
    {
        return nVersion;
    }

    /**
     * Set the genesis block version.  This must be a literal write
     * through, to get the correct historic version.
     * @param nGenesisVersion The version to set.
     */
    inline void SetGenesisVersion(int32_t nGenesisVersion)
    {
        nVersion = nGenesisVersion;
    }

    /**
     * Check if the auxpow flag is set in the version.
     * @return True iff this block version is marked as auxpow.
     */
    inline bool IsAuxpow() const
    {
        return nVersion & VERSION_AUXPOW;
    }

    /**
     * Set the auxpow flag.  This is used for testing.
     * @param auxpow Whether to mark auxpow as true.
     */
    inline void SetAuxpow(bool auxpow)
    {
        if (auxpow)
            nVersion |= VERSION_AUXPOW;
        else
            nVersion &= ~VERSION_AUXPOW;
    }

    /**
     * Check whether this is a "legacy" block without chain ID.
     * @return True if it is.
     */
    inline bool IsLegacy() const
    {
        return nVersion == 1
            || (nVersion == 2 && GetChainId() == 0);
    }

    CBlockVersion& operator=(const CBlockVersion& other)
    {
        nVersion = other.nVersion;
        return *this;
    }

    CBlockVersion& operator=(const int nBaseVersion)
    {
        nVersion = (nBaseVersion & 0x000000ff) | (nVersion & 0xffffff00);
        return *this;
    }

    operator int() { return nVersion & 0x000000ff; }
    friend inline bool operator==(const CBlockVersion a, const int b) { return (a.nVersion & 0x000000ff) == b; }
    friend inline bool operator!=(const CBlockVersion a, const int b) { return (a.nVersion & 0x000000ff) != b; }
    friend inline bool operator>(const CBlockVersion a, const int b) { return (a.nVersion & 0x000000ff) > b; }
    friend inline bool operator<(const CBlockVersion a, const int b) { return (a.nVersion & 0x000000ff) < b; }
    friend inline bool operator>=(const CBlockVersion a, const int b) { return (a.nVersion & 0x000000ff) >= b; }
    friend inline bool operator<=(const CBlockVersion a, const int b) { return (a.nVersion & 0x000000ff) <= b; }
};

/**
 * A block header without auxpow information.  This "intermediate step"
 * in constructing the full header is useful, because it breaks the cyclic
 * dependency between auxpow (referencing a parent block header) and
 * the block header (referencing an auxpow).  The parent block header
 * does not have auxpow itself, so it is a pure header.
 */
class CPureBlockHeader
{
public:
    // header
    static const int32_t CURRENT_VERSION = 3;
    CBlockVersion nVersion;
    uint256 hashPrevBlock;
    uint256 hashMerkleRoot;
    uint32_t nTime;
    uint32_t nBits;
    uint32_t nNonce;

    CPureBlockHeader()
    {
        SetNull();
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
    {
        READWRITE(this->nVersion);
        nVersion = this->nVersion;
        READWRITE(hashPrevBlock);
        READWRITE(hashMerkleRoot);
        READWRITE(nTime);
        READWRITE(nBits);
        READWRITE(nNonce);
    }

    void SetNull()
    {
        nVersion.SetNull();
        hashPrevBlock.SetNull();
        hashMerkleRoot.SetNull();
        nTime = 0;
        nBits = 0;
        nNonce = 0;
    }

    bool IsNull() const
    {
        return (nBits == 0);
    }

    uint256 GetHash() const;

    uint256 GetPoWHash() const;

    int64_t GetBlockTime() const
    {
        return (int64_t)nTime;
    }
};

#endif // BITCOIN_PRIMITIVES_PUREHEADER_H
