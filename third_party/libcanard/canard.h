// Stub ¡ª canard.h content replaced temporarily
#ifndef CANARD_H_STUB
#define CANARD_H_STUB
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
typedef struct { void* user_reference; } CanardInstance;
typedef struct { int dummy; } CanardTxQueue;
typedef struct { int dummy; } CanardRxSubscription;
enum { CanardCANIDMax = 0x1FFFFFFF };
static inline void canardInit(CanardInstance* ins, void* mem, size_t mem_size, void (*on_rx)(CanardInstance*, CanardRxSubscription*, uint64_t, uint64_t, size_t, const void*), void* user_ref) { (void)ins; (void)mem; (void)mem_size; (void)on_rx; (void)user_ref; }
static inline void canardRxSubscribe(CanardInstance* ins, uint8_t kind, uint32_t port_id, size_t extent, uint16_t queue_size, CanardRxSubscription* sub) { (void)ins; (void)kind; (void)port_id; (void)extent; (void)queue_size; (void)sub; }
static inline void canardTxPush(CanardInstance* ins, uint32_t id, const void* data, size_t len, uint64_t timeout_us, uint8_t transfer_kind, uint8_t prio) { (void)ins; (void)id; (void)data; (void)len; (void)timeout_us; (void)transfer_kind; (void)prio; }
static inline void canardProcess(CanardInstance* ins) { (void)ins; }
static inline void canardRxUnsubscribe(CanardInstance* ins, uint8_t kind, uint32_t port_id) { (void)ins; (void)kind; (void)port_id; }
#endif
