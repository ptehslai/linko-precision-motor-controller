// libcanard v4 stub — provides all types needed by cyphal_can*.c
#ifndef CANARD_H_STUB
#define CANARD_H_STUB
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- transfer kinds / priority ---- */
typedef enum {
    CanardTransferKindMessage  = 0,
    CanardTransferKindRequest  = 1,
    CanardTransferKindResponse = 2,
} CanardTransferKind;

typedef enum {
    CanardPriorityExceptional = 0,
    CanardPriorityImmediate   = 1,
    CanardPriorityHigh        = 2,
    CanardPriorityNominal     = 3,
    CanardPriorityLow         = 4,
    CanardPriorityOptional    = 5,
    CanardPrioritySlow        = 6,
} CanardPriority;

typedef uint64_t CanardMicrosecond;
typedef uint8_t  CanardTransferID;
typedef uint32_t CanardPortID;

/* ---- constants ---- */
#define CANARD_NODE_ID_UNSET                     255U
#define CANARD_TRANSFER_ID_MAX                   31U
#define CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC  2000000ULL
#define CANARD_MTU_CAN_CLASSIC                   8U

/* ---- payload / frame types ---- */
typedef struct {
    size_t         size;
    const uint8_t *data;
} CanardPayload;

typedef struct {
    size_t         size;
    const uint8_t *data;
    size_t         allocated_size;
} CanardRxPayload;

typedef struct {
    uint32_t       extended_can_id;
    CanardPayload  payload;
} CanardFrame;

typedef struct {
    uint32_t        extended_can_id;
    CanardPayload   payload;
    void           *user_data;
} CanardMutableFrame;

/* ---- transfer metadata ---- */
typedef struct {
    CanardPriority      priority;
    CanardTransferKind  transfer_kind;
    CanardPortID        port_id;
    uint8_t             remote_node_id;
    CanardTransferID    transfer_id;
} CanardTransferMetadata;

/* ---- Rx transfer ---- */
typedef struct {
    CanardTransferMetadata metadata;
    CanardRxPayload        payload;
} CanardRxTransfer;

/* ---- subscription ---- */
typedef struct {
    CanardPortID        port_id;
    CanardTransferKind  transfer_kind;
    size_t              extent;
    uint16_t            max_queue_size;
    struct CanardRxSubscription *next;
} CanardRxSubscription;

/* ---- memory resource ---- */
typedef struct {
    void *user_reference;
    void *(*allocate)(void *user, size_t size);
    void  (*deallocate)(void *user, size_t size, void *ptr);
} CanardMemoryResource;

/* ---- main instance ---- */
typedef struct {
    uint32_t             node_id;
    CanardMemoryResource memory;
    CanardRxSubscription *rx_subscriptions;
} CanardInstance;

/* ---- TX queue ---- */
typedef struct {
    size_t capacity;
    size_t size;
} CanardTxQueue;

/* ---- API stubs (no-op, compile only) ---- */
static inline CanardInstance canardInit(CanardMemoryResource mem) {
    CanardInstance ci = {0}; ci.memory = mem; return ci;
}
static inline CanardTxQueue canardTxInit(size_t cap, size_t mtu, CanardMemoryResource mem) {
    (void)mtu; (void)mem; CanardTxQueue tq = {cap, 0}; return tq;
}
static inline int8_t canardRxSubscribe(CanardInstance *ins, CanardTransferKind kind, CanardPortID port,
                                       size_t extent, CanardMicrosecond timeout, CanardRxSubscription *sub) {
    (void)ins; (void)kind; (void)extent; (void)timeout;
    sub->port_id = port; sub->transfer_kind = kind; sub->next = NULL;
    return 1;
}
static inline int8_t canardRxAccept(CanardInstance *ins, CanardMicrosecond now, const CanardFrame *frame,
                                    uint8_t redundancy, CanardRxTransfer *transfer, CanardRxSubscription **sub) {
    (void)ins; (void)now; (void)frame; (void)redundancy; (void)transfer; (void)sub;
    return 0;
}
static inline int32_t canardTxPush(CanardTxQueue *tq, CanardInstance *ins, CanardMicrosecond deadline,
                                   const CanardTransferMetadata *meta, CanardPayload payload,
                                   CanardMicrosecond now, void *arg) {
    (void)tq; (void)ins; (void)deadline; (void)meta; (void)payload; (void)now; (void)arg;
    return 1;
}
static inline int32_t canardTxPoll(CanardTxQueue *tq, CanardInstance *ins, CanardMicrosecond now,
                                   void *user, int8_t (*tx)(void*, CanardMicrosecond, CanardMutableFrame*),
                                   CanardMicrosecond *next_deadline, void *arg) {
    (void)tq; (void)ins; (void)now; (void)user; (void)tx; (void)next_deadline; (void)arg;
    return 0;
}

#ifdef __cplusplus
}
#endif
#endif // CANARD_H_STUB
