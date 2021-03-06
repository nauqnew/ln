/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: lightning.proto */

#ifndef PROTOBUF_C_lightning_2eproto__INCLUDED
#define PROTOBUF_C_lightning_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Sha256Hash Sha256Hash;
typedef struct _Preimage Preimage;
typedef struct _Signature Signature;
typedef struct _Locktime Locktime;
typedef struct _BitcoinPubkey BitcoinPubkey;
typedef struct _Funding Funding;
typedef struct _Authenticate Authenticate;
typedef struct _Init Init;
typedef struct _OpenChannel OpenChannel;
typedef struct _OpenAnchor OpenAnchor;
typedef struct _OpenCommitSig OpenCommitSig;
typedef struct _OpenComplete OpenComplete;
typedef struct _RouteStep RouteStep;
typedef struct _Route Route;
typedef struct _Routing Routing;
typedef struct _UpdateAddHtlc UpdateAddHtlc;
typedef struct _UpdateFulfillHtlc UpdateFulfillHtlc;
typedef struct _FailInfo FailInfo;
typedef struct _FailReason FailReason;
typedef struct _UpdateFailHtlc UpdateFailHtlc;
typedef struct _UpdateFee UpdateFee;
typedef struct _UpdateCommit UpdateCommit;
typedef struct _UpdateRevocation UpdateRevocation;
typedef struct _CloseShutdown CloseShutdown;
typedef struct _CloseSignature CloseSignature;
typedef struct _Error Error;
typedef struct _NestedPkt NestedPkt;
typedef struct _Pkt Pkt;


/* --- enums --- */

typedef enum _OpenChannel__AnchorOffer {
  /*
   * I will create the anchor
   */
  OPEN_CHANNEL__ANCHOR_OFFER__WILL_CREATE_ANCHOR = 1,
  /*
   * I won't create the anchor
   */
  OPEN_CHANNEL__ANCHOR_OFFER__WONT_CREATE_ANCHOR = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(OPEN_CHANNEL__ANCHOR_OFFER)
} OpenChannel__AnchorOffer;

/* --- messages --- */

/*
 * Protobufs don't have fixed-length fields, so these are a hack.
 */
struct  _Sha256Hash
{
  ProtobufCMessage base;
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};
#define SHA256_HASH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sha256_hash__descriptor) \
    , 0, 0, 0, 0 }


struct  _Preimage
{
  ProtobufCMessage base;
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};
#define PREIMAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&preimage__descriptor) \
    , 0, 0, 0, 0 }


struct  _Signature
{
  ProtobufCMessage base;
  uint64_t r1;
  uint64_t r2;
  uint64_t r3;
  uint64_t r4;
  uint64_t s1;
  uint64_t s2;
  uint64_t s3;
  uint64_t s4;
};
#define SIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&signature__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0 }


typedef enum {
  LOCKTIME__LOCKTIME__NOT_SET = 0,
  LOCKTIME__LOCKTIME_SECONDS = 1,
  LOCKTIME__LOCKTIME_BLOCKS = 2,
} Locktime__LocktimeCase;

struct  _Locktime
{
  ProtobufCMessage base;
  Locktime__LocktimeCase locktime_case;
  union {
    uint32_t seconds;
    uint32_t blocks;
  };
};
#define LOCKTIME__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&locktime__descriptor) \
    , LOCKTIME__LOCKTIME__NOT_SET, {0} }


/*
 * Pubkey for commitment transaction input.
 */
struct  _BitcoinPubkey
{
  ProtobufCMessage base;
  /*
   * Must be 33 bytes.
   */
  ProtobufCBinaryData key;
};
#define BITCOIN_PUBKEY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&bitcoin_pubkey__descriptor) \
    , {0,NULL} }


/*
 * How much a node charges (or pays!) for sending.
 */
struct  _Funding
{
  ProtobufCMessage base;
  /*
   * Base amount (in satoshi).
   */
  protobuf_c_boolean has_fixed;
  int64_t fixed;
  /*
   * This is charge per millionth of a satoshi.
   */
  protobuf_c_boolean has_per_micro_satoshi;
  int32_t per_micro_satoshi;
};
#define FUNDING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&funding__descriptor) \
    , 0,0ll, 0,0 }


/*
 * Set channel params.
 */
struct  _Authenticate
{
  ProtobufCMessage base;
  /*
   * Which node this is.
   */
  BitcoinPubkey *node_id;
  /*
   * Signature of your session key. * 
   */
  Signature *session_sig;
};
#define AUTHENTICATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&authenticate__descriptor) \
    , NULL, NULL }


/*
 * We're authenticated.  Here's what we've received already.
 */
struct  _Init
{
  ProtobufCMessage base;
  /*
   * How many update_commit and update_revocation messages already received
   */
  uint64_t ack;
  /*
   * What features do we support (odd) and require (even)
   */
  protobuf_c_boolean has_features;
  ProtobufCBinaryData features;
};
#define INIT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&init__descriptor) \
    , 0, 0,{0,NULL} }


/*
 * Set channel params.
 */
struct  _OpenChannel
{
  ProtobufCMessage base;
  /*
   * Relative locktime for outputs going to us.
   */
  Locktime *delay;
  /*
   * Hash for revoking first commitment transaction.
   */
  Sha256Hash *revocation_hash;
  /*
   * Hash for revoking second commitment transaction.
   */
  Sha256Hash *next_revocation_hash;
  /*
   * Pubkey for anchor to pay into commitment tx.
   */
  BitcoinPubkey *commit_key;
  /*
   * How to pay money to us from commit_tx.
   */
  BitcoinPubkey *final_key;
  OpenChannel__AnchorOffer anch;
  /*
   * How far must anchor be buried before we consider channel live?
   */
  protobuf_c_boolean has_min_depth;
  uint32_t min_depth;
  /*
   * How much fee would I like on commitment tx?
   */
  uint64_t initial_fee_rate;
};
#define OPEN_CHANNEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_channel__descriptor) \
    , NULL, NULL, NULL, NULL, NULL, 0, 0,0u, 0 }


/*
 * Whoever is supplying anchor sends this.
 */
struct  _OpenAnchor
{
  ProtobufCMessage base;
  /*
   * Transaction ID of anchor.
   */
  Sha256Hash *txid;
  /*
   * Which output is going to the 2 of 2.
   */
  uint32_t output_index;
  /*
   * Amount of anchor output.
   */
  uint64_t amount;
};
#define OPEN_ANCHOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_anchor__descriptor) \
    , NULL, 0, 0 }


/*
 * Reply: signature for your initial commitment tx
 */
struct  _OpenCommitSig
{
  ProtobufCMessage base;
  Signature *sig;
};
#define OPEN_COMMIT_SIG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_commit_sig__descriptor) \
    , NULL }


/*
 * Indicates we've seen anchor reach min-depth.
 */
struct  _OpenComplete
{
  ProtobufCMessage base;
  /*
   * Block it went into.
   */
  /*
   * FIXME: add a merkle proof plus block headers here?
   */
  Sha256Hash *blockid;
};
#define OPEN_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_complete__descriptor) \
    , NULL }


typedef enum {
  ROUTE_STEP__NEXT__NOT_SET = 0,
  ROUTE_STEP__NEXT_END = 1,
  ROUTE_STEP__NEXT_BITCOIN = 2,
} RouteStep__NextCase;

struct  _RouteStep
{
  ProtobufCMessage base;
  /*
   * How much to forward (difference is fee)
   */
  uint32_t amount;
  RouteStep__NextCase next_case;
  union {
    /*
     * Actually, this is the last one
     */
    protobuf_c_boolean end;
    /*
     * Next lightning node.
     */
    /*
     * Other realms go here...
     */
    BitcoinPubkey *bitcoin;
  };
};
#define ROUTE_STEP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route_step__descriptor) \
    , 0, ROUTE_STEP__NEXT__NOT_SET, {0} }


struct  _Route
{
  ProtobufCMessage base;
  size_t n_steps;
  RouteStep **steps;
};
#define ROUTE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__descriptor) \
    , 0,NULL }


struct  _Routing
{
  ProtobufCMessage base;
  ProtobufCBinaryData info;
};
#define ROUTING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&routing__descriptor) \
    , {0,NULL} }


/*
 * Start a new commitment tx to add an HTLC me -> you.
 */
struct  _UpdateAddHtlc
{
  ProtobufCMessage base;
  /*
   * Unique identifier for this HTLC.
   */
  uint64_t id;
  /*
   * Amount for htlc (millisatoshi)
   */
  uint64_t amount_msat;
  /*
   * Hash for HTLC R value.
   */
  Sha256Hash *r_hash;
  /*
   * Time at which HTLC expires (absolute)
   */
  Locktime *expiry;
  /*
   * Onion-wrapped routing information.
   */
  Routing *route;
};
#define UPDATE_ADD_HTLC__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_add_htlc__descriptor) \
    , 0, 0, NULL, NULL, NULL }


/*
 * Complete your HTLC: I have the R value, pay me!
 */
struct  _UpdateFulfillHtlc
{
  ProtobufCMessage base;
  /*
   * Which HTLC
   */
  uint64_t id;
  /*
   * HTLC payment_preimage.
   */
  Preimage *r;
};
#define UPDATE_FULFILL_HTLC__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_fulfill_htlc__descriptor) \
    , 0, NULL }


/*
 * This is encrypted in fail_reason.
 */
struct  _FailInfo
{
  ProtobufCMessage base;
  BitcoinPubkey *id;
  uint32_t error_code;
  char *reason;
};
#define FAIL_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&fail_info__descriptor) \
    , NULL, 0, NULL }


struct  _FailReason
{
  ProtobufCMessage base;
  ProtobufCBinaryData info;
};
#define FAIL_REASON__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&fail_reason__descriptor) \
    , {0,NULL} }


struct  _UpdateFailHtlc
{
  ProtobufCMessage base;
  /*
   * Which HTLC
   */
  uint64_t id;
  /*
   * Reason for failure (for relay to initial node)
   */
  FailReason *reason;
};
#define UPDATE_FAIL_HTLC__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_fail_htlc__descriptor) \
    , 0, NULL }


/*
 * Fee rate change proposal
 */
struct  _UpdateFee
{
  ProtobufCMessage base;
  uint32_t fee_rate;
};
#define UPDATE_FEE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_fee__descriptor) \
    , 0 }


/*
 * Commit all the staged changes.
 */
struct  _UpdateCommit
{
  ProtobufCMessage base;
  /*
   * Signature for your new commitment tx (if any outputs are HTLCs or to you)
   */
  Signature *sig;
};
#define UPDATE_COMMIT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_commit__descriptor) \
    , NULL }


/*
 * Complete the update.
 */
struct  _UpdateRevocation
{
  ProtobufCMessage base;
  /*
   * Hash preimage which revokes old commitment tx.
   */
  Sha256Hash *revocation_preimage;
  /*
   * Revocation hash for my next commit transaction
   */
  Sha256Hash *next_revocation_hash;
};
#define UPDATE_REVOCATION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_revocation__descriptor) \
    , NULL, NULL }


/*
 * Start clearing out the channel HTLCs so we can close it
 */
struct  _CloseShutdown
{
  ProtobufCMessage base;
  /*
   * Output script for mutual close tx.
   */
  ProtobufCBinaryData scriptpubkey;
};
#define CLOSE_SHUTDOWN__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&close_shutdown__descriptor) \
    , {0,NULL} }


struct  _CloseSignature
{
  ProtobufCMessage base;
  /*
   * Fee in satoshis.
   */
  uint64_t close_fee;
  /*
   * Signature on the close transaction.
   */
  Signature *sig;
};
#define CLOSE_SIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&close_signature__descriptor) \
    , 0, NULL }


/*
 * This means we're going to hang up; it's to help diagnose only! 
 */
struct  _Error
{
  ProtobufCMessage base;
  char *problem;
};
#define ERROR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&error__descriptor) \
    , NULL }


/*
 * Nested message to transport standard protocol messages through the legacy transport
 */
struct  _NestedPkt
{
  ProtobufCMessage base;
  uint32_t type;
  ProtobufCBinaryData inner_pkt;
};
#define NESTED_PKT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&nested_pkt__descriptor) \
    , 0, {0,NULL} }


typedef enum {
  PKT__PKT__NOT_SET = 0,
  PKT__PKT_AUTH = 50,
  PKT__PKT_INIT = 51,
  PKT__PKT_OPEN = 20,
  PKT__PKT_OPEN_ANCHOR = 21,
  PKT__PKT_OPEN_COMMIT_SIG = 22,
  PKT__PKT_OPEN_COMPLETE = 23,
  PKT__PKT_UPDATE_ADD_HTLC = 2,
  PKT__PKT_UPDATE_FULFILL_HTLC = 3,
  PKT__PKT_UPDATE_FAIL_HTLC = 4,
  PKT__PKT_UPDATE_FEE = 5,
  PKT__PKT_UPDATE_COMMIT = 6,
  PKT__PKT_UPDATE_REVOCATION = 7,
  PKT__PKT_CLOSE_SHUTDOWN = 30,
  PKT__PKT_CLOSE_SIGNATURE = 31,
  PKT__PKT_ERROR = 40,
  PKT__PKT_NESTED = 128,
} Pkt__PktCase;

/*
 * This is the union which defines all of them
 */
struct  _Pkt
{
  ProtobufCMessage base;
  Pkt__PktCase pkt_case;
  union {
    /*
     * Start of connection
     */
    Authenticate *auth;
    Init *init;
    /*
     * Opening
     */
    OpenChannel *open;
    OpenAnchor *open_anchor;
    OpenCommitSig *open_commit_sig;
    OpenComplete *open_complete;
    /*
     * Updating (most common)
     */
    UpdateAddHtlc *update_add_htlc;
    UpdateFulfillHtlc *update_fulfill_htlc;
    UpdateFailHtlc *update_fail_htlc;
    UpdateFee *update_fee;
    UpdateCommit *update_commit;
    UpdateRevocation *update_revocation;
    /*
     * Closing
     */
    CloseShutdown *close_shutdown;
    CloseSignature *close_signature;
    /*
     * Unexpected issue.
     */
    Error *error;
    /*
     * Shim to upgrade to new packet format
     */
    NestedPkt *nested;
  };
};
#define PKT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&pkt__descriptor) \
    , PKT__PKT__NOT_SET, {0} }


/* Sha256Hash methods */
void   sha256_hash__init
                     (Sha256Hash         *message);
size_t sha256_hash__get_packed_size
                     (const Sha256Hash   *message);
size_t sha256_hash__pack
                     (const Sha256Hash   *message,
                      uint8_t             *out);
size_t sha256_hash__pack_to_buffer
                     (const Sha256Hash   *message,
                      ProtobufCBuffer     *buffer);
Sha256Hash *
       sha256_hash__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   sha256_hash__free_unpacked
                     (Sha256Hash *message,
                      ProtobufCAllocator *allocator);
/* Preimage methods */
void   preimage__init
                     (Preimage         *message);
size_t preimage__get_packed_size
                     (const Preimage   *message);
size_t preimage__pack
                     (const Preimage   *message,
                      uint8_t             *out);
size_t preimage__pack_to_buffer
                     (const Preimage   *message,
                      ProtobufCBuffer     *buffer);
Preimage *
       preimage__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   preimage__free_unpacked
                     (Preimage *message,
                      ProtobufCAllocator *allocator);
/* Signature methods */
void   signature__init
                     (Signature         *message);
size_t signature__get_packed_size
                     (const Signature   *message);
size_t signature__pack
                     (const Signature   *message,
                      uint8_t             *out);
size_t signature__pack_to_buffer
                     (const Signature   *message,
                      ProtobufCBuffer     *buffer);
Signature *
       signature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   signature__free_unpacked
                     (Signature *message,
                      ProtobufCAllocator *allocator);
/* Locktime methods */
void   locktime__init
                     (Locktime         *message);
size_t locktime__get_packed_size
                     (const Locktime   *message);
size_t locktime__pack
                     (const Locktime   *message,
                      uint8_t             *out);
size_t locktime__pack_to_buffer
                     (const Locktime   *message,
                      ProtobufCBuffer     *buffer);
Locktime *
       locktime__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   locktime__free_unpacked
                     (Locktime *message,
                      ProtobufCAllocator *allocator);
/* BitcoinPubkey methods */
void   bitcoin_pubkey__init
                     (BitcoinPubkey         *message);
size_t bitcoin_pubkey__get_packed_size
                     (const BitcoinPubkey   *message);
size_t bitcoin_pubkey__pack
                     (const BitcoinPubkey   *message,
                      uint8_t             *out);
size_t bitcoin_pubkey__pack_to_buffer
                     (const BitcoinPubkey   *message,
                      ProtobufCBuffer     *buffer);
BitcoinPubkey *
       bitcoin_pubkey__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   bitcoin_pubkey__free_unpacked
                     (BitcoinPubkey *message,
                      ProtobufCAllocator *allocator);
/* Funding methods */
void   funding__init
                     (Funding         *message);
size_t funding__get_packed_size
                     (const Funding   *message);
size_t funding__pack
                     (const Funding   *message,
                      uint8_t             *out);
size_t funding__pack_to_buffer
                     (const Funding   *message,
                      ProtobufCBuffer     *buffer);
Funding *
       funding__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   funding__free_unpacked
                     (Funding *message,
                      ProtobufCAllocator *allocator);
/* Authenticate methods */
void   authenticate__init
                     (Authenticate         *message);
size_t authenticate__get_packed_size
                     (const Authenticate   *message);
size_t authenticate__pack
                     (const Authenticate   *message,
                      uint8_t             *out);
size_t authenticate__pack_to_buffer
                     (const Authenticate   *message,
                      ProtobufCBuffer     *buffer);
Authenticate *
       authenticate__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   authenticate__free_unpacked
                     (Authenticate *message,
                      ProtobufCAllocator *allocator);
/* Init methods */
void   init__init
                     (Init         *message);
size_t init__get_packed_size
                     (const Init   *message);
size_t init__pack
                     (const Init   *message,
                      uint8_t             *out);
size_t init__pack_to_buffer
                     (const Init   *message,
                      ProtobufCBuffer     *buffer);
Init *
       init__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   init__free_unpacked
                     (Init *message,
                      ProtobufCAllocator *allocator);
/* OpenChannel methods */
void   open_channel__init
                     (OpenChannel         *message);
size_t open_channel__get_packed_size
                     (const OpenChannel   *message);
size_t open_channel__pack
                     (const OpenChannel   *message,
                      uint8_t             *out);
size_t open_channel__pack_to_buffer
                     (const OpenChannel   *message,
                      ProtobufCBuffer     *buffer);
OpenChannel *
       open_channel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_channel__free_unpacked
                     (OpenChannel *message,
                      ProtobufCAllocator *allocator);
/* OpenAnchor methods */
void   open_anchor__init
                     (OpenAnchor         *message);
size_t open_anchor__get_packed_size
                     (const OpenAnchor   *message);
size_t open_anchor__pack
                     (const OpenAnchor   *message,
                      uint8_t             *out);
size_t open_anchor__pack_to_buffer
                     (const OpenAnchor   *message,
                      ProtobufCBuffer     *buffer);
OpenAnchor *
       open_anchor__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_anchor__free_unpacked
                     (OpenAnchor *message,
                      ProtobufCAllocator *allocator);
/* OpenCommitSig methods */
void   open_commit_sig__init
                     (OpenCommitSig         *message);
size_t open_commit_sig__get_packed_size
                     (const OpenCommitSig   *message);
size_t open_commit_sig__pack
                     (const OpenCommitSig   *message,
                      uint8_t             *out);
size_t open_commit_sig__pack_to_buffer
                     (const OpenCommitSig   *message,
                      ProtobufCBuffer     *buffer);
OpenCommitSig *
       open_commit_sig__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_commit_sig__free_unpacked
                     (OpenCommitSig *message,
                      ProtobufCAllocator *allocator);
/* OpenComplete methods */
void   open_complete__init
                     (OpenComplete         *message);
size_t open_complete__get_packed_size
                     (const OpenComplete   *message);
size_t open_complete__pack
                     (const OpenComplete   *message,
                      uint8_t             *out);
size_t open_complete__pack_to_buffer
                     (const OpenComplete   *message,
                      ProtobufCBuffer     *buffer);
OpenComplete *
       open_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_complete__free_unpacked
                     (OpenComplete *message,
                      ProtobufCAllocator *allocator);
/* RouteStep methods */
void   route_step__init
                     (RouteStep         *message);
size_t route_step__get_packed_size
                     (const RouteStep   *message);
size_t route_step__pack
                     (const RouteStep   *message,
                      uint8_t             *out);
size_t route_step__pack_to_buffer
                     (const RouteStep   *message,
                      ProtobufCBuffer     *buffer);
RouteStep *
       route_step__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route_step__free_unpacked
                     (RouteStep *message,
                      ProtobufCAllocator *allocator);
/* Route methods */
void   route__init
                     (Route         *message);
size_t route__get_packed_size
                     (const Route   *message);
size_t route__pack
                     (const Route   *message,
                      uint8_t             *out);
size_t route__pack_to_buffer
                     (const Route   *message,
                      ProtobufCBuffer     *buffer);
Route *
       route__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__free_unpacked
                     (Route *message,
                      ProtobufCAllocator *allocator);
/* Routing methods */
void   routing__init
                     (Routing         *message);
size_t routing__get_packed_size
                     (const Routing   *message);
size_t routing__pack
                     (const Routing   *message,
                      uint8_t             *out);
size_t routing__pack_to_buffer
                     (const Routing   *message,
                      ProtobufCBuffer     *buffer);
Routing *
       routing__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   routing__free_unpacked
                     (Routing *message,
                      ProtobufCAllocator *allocator);
/* UpdateAddHtlc methods */
void   update_add_htlc__init
                     (UpdateAddHtlc         *message);
size_t update_add_htlc__get_packed_size
                     (const UpdateAddHtlc   *message);
size_t update_add_htlc__pack
                     (const UpdateAddHtlc   *message,
                      uint8_t             *out);
size_t update_add_htlc__pack_to_buffer
                     (const UpdateAddHtlc   *message,
                      ProtobufCBuffer     *buffer);
UpdateAddHtlc *
       update_add_htlc__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_add_htlc__free_unpacked
                     (UpdateAddHtlc *message,
                      ProtobufCAllocator *allocator);
/* UpdateFulfillHtlc methods */
void   update_fulfill_htlc__init
                     (UpdateFulfillHtlc         *message);
size_t update_fulfill_htlc__get_packed_size
                     (const UpdateFulfillHtlc   *message);
size_t update_fulfill_htlc__pack
                     (const UpdateFulfillHtlc   *message,
                      uint8_t             *out);
size_t update_fulfill_htlc__pack_to_buffer
                     (const UpdateFulfillHtlc   *message,
                      ProtobufCBuffer     *buffer);
UpdateFulfillHtlc *
       update_fulfill_htlc__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_fulfill_htlc__free_unpacked
                     (UpdateFulfillHtlc *message,
                      ProtobufCAllocator *allocator);
/* FailInfo methods */
void   fail_info__init
                     (FailInfo         *message);
size_t fail_info__get_packed_size
                     (const FailInfo   *message);
size_t fail_info__pack
                     (const FailInfo   *message,
                      uint8_t             *out);
size_t fail_info__pack_to_buffer
                     (const FailInfo   *message,
                      ProtobufCBuffer     *buffer);
FailInfo *
       fail_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   fail_info__free_unpacked
                     (FailInfo *message,
                      ProtobufCAllocator *allocator);
/* FailReason methods */
void   fail_reason__init
                     (FailReason         *message);
size_t fail_reason__get_packed_size
                     (const FailReason   *message);
size_t fail_reason__pack
                     (const FailReason   *message,
                      uint8_t             *out);
size_t fail_reason__pack_to_buffer
                     (const FailReason   *message,
                      ProtobufCBuffer     *buffer);
FailReason *
       fail_reason__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   fail_reason__free_unpacked
                     (FailReason *message,
                      ProtobufCAllocator *allocator);
/* UpdateFailHtlc methods */
void   update_fail_htlc__init
                     (UpdateFailHtlc         *message);
size_t update_fail_htlc__get_packed_size
                     (const UpdateFailHtlc   *message);
size_t update_fail_htlc__pack
                     (const UpdateFailHtlc   *message,
                      uint8_t             *out);
size_t update_fail_htlc__pack_to_buffer
                     (const UpdateFailHtlc   *message,
                      ProtobufCBuffer     *buffer);
UpdateFailHtlc *
       update_fail_htlc__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_fail_htlc__free_unpacked
                     (UpdateFailHtlc *message,
                      ProtobufCAllocator *allocator);
/* UpdateFee methods */
void   update_fee__init
                     (UpdateFee         *message);
size_t update_fee__get_packed_size
                     (const UpdateFee   *message);
size_t update_fee__pack
                     (const UpdateFee   *message,
                      uint8_t             *out);
size_t update_fee__pack_to_buffer
                     (const UpdateFee   *message,
                      ProtobufCBuffer     *buffer);
UpdateFee *
       update_fee__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_fee__free_unpacked
                     (UpdateFee *message,
                      ProtobufCAllocator *allocator);
/* UpdateCommit methods */
void   update_commit__init
                     (UpdateCommit         *message);
size_t update_commit__get_packed_size
                     (const UpdateCommit   *message);
size_t update_commit__pack
                     (const UpdateCommit   *message,
                      uint8_t             *out);
size_t update_commit__pack_to_buffer
                     (const UpdateCommit   *message,
                      ProtobufCBuffer     *buffer);
UpdateCommit *
       update_commit__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_commit__free_unpacked
                     (UpdateCommit *message,
                      ProtobufCAllocator *allocator);
/* UpdateRevocation methods */
void   update_revocation__init
                     (UpdateRevocation         *message);
size_t update_revocation__get_packed_size
                     (const UpdateRevocation   *message);
size_t update_revocation__pack
                     (const UpdateRevocation   *message,
                      uint8_t             *out);
size_t update_revocation__pack_to_buffer
                     (const UpdateRevocation   *message,
                      ProtobufCBuffer     *buffer);
UpdateRevocation *
       update_revocation__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_revocation__free_unpacked
                     (UpdateRevocation *message,
                      ProtobufCAllocator *allocator);
/* CloseShutdown methods */
void   close_shutdown__init
                     (CloseShutdown         *message);
size_t close_shutdown__get_packed_size
                     (const CloseShutdown   *message);
size_t close_shutdown__pack
                     (const CloseShutdown   *message,
                      uint8_t             *out);
size_t close_shutdown__pack_to_buffer
                     (const CloseShutdown   *message,
                      ProtobufCBuffer     *buffer);
CloseShutdown *
       close_shutdown__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   close_shutdown__free_unpacked
                     (CloseShutdown *message,
                      ProtobufCAllocator *allocator);
/* CloseSignature methods */
void   close_signature__init
                     (CloseSignature         *message);
size_t close_signature__get_packed_size
                     (const CloseSignature   *message);
size_t close_signature__pack
                     (const CloseSignature   *message,
                      uint8_t             *out);
size_t close_signature__pack_to_buffer
                     (const CloseSignature   *message,
                      ProtobufCBuffer     *buffer);
CloseSignature *
       close_signature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   close_signature__free_unpacked
                     (CloseSignature *message,
                      ProtobufCAllocator *allocator);
/* Error methods */
void   error__init
                     (Error         *message);
size_t error__get_packed_size
                     (const Error   *message);
size_t error__pack
                     (const Error   *message,
                      uint8_t             *out);
size_t error__pack_to_buffer
                     (const Error   *message,
                      ProtobufCBuffer     *buffer);
Error *
       error__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   error__free_unpacked
                     (Error *message,
                      ProtobufCAllocator *allocator);
/* NestedPkt methods */
void   nested_pkt__init
                     (NestedPkt         *message);
size_t nested_pkt__get_packed_size
                     (const NestedPkt   *message);
size_t nested_pkt__pack
                     (const NestedPkt   *message,
                      uint8_t             *out);
size_t nested_pkt__pack_to_buffer
                     (const NestedPkt   *message,
                      ProtobufCBuffer     *buffer);
NestedPkt *
       nested_pkt__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   nested_pkt__free_unpacked
                     (NestedPkt *message,
                      ProtobufCAllocator *allocator);
/* Pkt methods */
void   pkt__init
                     (Pkt         *message);
size_t pkt__get_packed_size
                     (const Pkt   *message);
size_t pkt__pack
                     (const Pkt   *message,
                      uint8_t             *out);
size_t pkt__pack_to_buffer
                     (const Pkt   *message,
                      ProtobufCBuffer     *buffer);
Pkt *
       pkt__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   pkt__free_unpacked
                     (Pkt *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Sha256Hash_Closure)
                 (const Sha256Hash *message,
                  void *closure_data);
typedef void (*Preimage_Closure)
                 (const Preimage *message,
                  void *closure_data);
typedef void (*Signature_Closure)
                 (const Signature *message,
                  void *closure_data);
typedef void (*Locktime_Closure)
                 (const Locktime *message,
                  void *closure_data);
typedef void (*BitcoinPubkey_Closure)
                 (const BitcoinPubkey *message,
                  void *closure_data);
typedef void (*Funding_Closure)
                 (const Funding *message,
                  void *closure_data);
typedef void (*Authenticate_Closure)
                 (const Authenticate *message,
                  void *closure_data);
typedef void (*Init_Closure)
                 (const Init *message,
                  void *closure_data);
typedef void (*OpenChannel_Closure)
                 (const OpenChannel *message,
                  void *closure_data);
typedef void (*OpenAnchor_Closure)
                 (const OpenAnchor *message,
                  void *closure_data);
typedef void (*OpenCommitSig_Closure)
                 (const OpenCommitSig *message,
                  void *closure_data);
typedef void (*OpenComplete_Closure)
                 (const OpenComplete *message,
                  void *closure_data);
typedef void (*RouteStep_Closure)
                 (const RouteStep *message,
                  void *closure_data);
typedef void (*Route_Closure)
                 (const Route *message,
                  void *closure_data);
typedef void (*Routing_Closure)
                 (const Routing *message,
                  void *closure_data);
typedef void (*UpdateAddHtlc_Closure)
                 (const UpdateAddHtlc *message,
                  void *closure_data);
typedef void (*UpdateFulfillHtlc_Closure)
                 (const UpdateFulfillHtlc *message,
                  void *closure_data);
typedef void (*FailInfo_Closure)
                 (const FailInfo *message,
                  void *closure_data);
typedef void (*FailReason_Closure)
                 (const FailReason *message,
                  void *closure_data);
typedef void (*UpdateFailHtlc_Closure)
                 (const UpdateFailHtlc *message,
                  void *closure_data);
typedef void (*UpdateFee_Closure)
                 (const UpdateFee *message,
                  void *closure_data);
typedef void (*UpdateCommit_Closure)
                 (const UpdateCommit *message,
                  void *closure_data);
typedef void (*UpdateRevocation_Closure)
                 (const UpdateRevocation *message,
                  void *closure_data);
typedef void (*CloseShutdown_Closure)
                 (const CloseShutdown *message,
                  void *closure_data);
typedef void (*CloseSignature_Closure)
                 (const CloseSignature *message,
                  void *closure_data);
typedef void (*Error_Closure)
                 (const Error *message,
                  void *closure_data);
typedef void (*NestedPkt_Closure)
                 (const NestedPkt *message,
                  void *closure_data);
typedef void (*Pkt_Closure)
                 (const Pkt *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor sha256_hash__descriptor;
extern const ProtobufCMessageDescriptor preimage__descriptor;
extern const ProtobufCMessageDescriptor signature__descriptor;
extern const ProtobufCMessageDescriptor locktime__descriptor;
extern const ProtobufCMessageDescriptor bitcoin_pubkey__descriptor;
extern const ProtobufCMessageDescriptor funding__descriptor;
extern const ProtobufCMessageDescriptor authenticate__descriptor;
extern const ProtobufCMessageDescriptor init__descriptor;
extern const ProtobufCMessageDescriptor open_channel__descriptor;
extern const ProtobufCEnumDescriptor    open_channel__anchor_offer__descriptor;
extern const ProtobufCMessageDescriptor open_anchor__descriptor;
extern const ProtobufCMessageDescriptor open_commit_sig__descriptor;
extern const ProtobufCMessageDescriptor open_complete__descriptor;
extern const ProtobufCMessageDescriptor route_step__descriptor;
extern const ProtobufCMessageDescriptor route__descriptor;
extern const ProtobufCMessageDescriptor routing__descriptor;
extern const ProtobufCMessageDescriptor update_add_htlc__descriptor;
extern const ProtobufCMessageDescriptor update_fulfill_htlc__descriptor;
extern const ProtobufCMessageDescriptor fail_info__descriptor;
extern const ProtobufCMessageDescriptor fail_reason__descriptor;
extern const ProtobufCMessageDescriptor update_fail_htlc__descriptor;
extern const ProtobufCMessageDescriptor update_fee__descriptor;
extern const ProtobufCMessageDescriptor update_commit__descriptor;
extern const ProtobufCMessageDescriptor update_revocation__descriptor;
extern const ProtobufCMessageDescriptor close_shutdown__descriptor;
extern const ProtobufCMessageDescriptor close_signature__descriptor;
extern const ProtobufCMessageDescriptor error__descriptor;
extern const ProtobufCMessageDescriptor nested_pkt__descriptor;
extern const ProtobufCMessageDescriptor pkt__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_lightning_2eproto__INCLUDED */
