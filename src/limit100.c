#include "hookapi.h"

// Callback, required by the hooks engine but unused here.
int64_t cbak(uint32_t reserved) {
    return 0;
}

int64_t hook(uint32_t reserved) {
    // Required guard to prevent unbounded execution
    GUARD(1);

    // 1) Only handle Payment transactions
    if (otxn_type() != ttPAYMENT) {
        accept(SBUF("Limit100: Not a Payment tx"), __LINE__);
    }

    // 2) Read the hook account (the account this hook is installed on)
    uint8_t hook_acc[20];
    hook_account(SBUF(hook_acc));

    // 3) Read the Account field from the originating transaction
    uint8_t tx_acc[20];
    int64_t acc_len = otxn_field(SBUF(tx_acc), sfAccount);
    if (acc_len < 20) {
        rollback(SBUF("Limit100: Cannot read sfAccount"), __LINE__);
    }

    // 4) If the tx is not sent from this account, allow it
    int8_t same = 0;
    BUFFER_EQUAL(same, hook_acc, tx_acc, 20);
    if (!same) {
        accept(SBUF("Limit100: Not outgoing from this account"), __LINE__);
    }

    // 5) Read the Amount field
    uint8_t amount_buf[8];
    int64_t a_len = otxn_field(SBUF(amount_buf), sfAmount);
    if (a_len < 8) {
        rollback(SBUF("Limit100: Missing Amount"), __LINE__);
    }

    // 6) Convert Amount to native drops
    int64_t drops = AMOUNT_TO_DROPS(amount_buf);
    if (drops < 0) {
        rollback(SBUF("Limit100: Non-XAH Amount not allowed"), __LINE__);
    }

    // 7) Max = 100 XAH = 100,000,000 drops
    int64_t max_drops = 100000000;

    if (drops > max_drops) {
        rollback(SBUF("Limit100: Payment > 100 XAH blocked"), __LINE__);
    }

    // 8) Allow payments within the limit
    accept(SBUF("Limit100: Payment within 100 XAH"), __LINE__);
}
