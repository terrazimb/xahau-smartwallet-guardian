# SmartWallet Guardian — Architecture Overview

SmartWallet Guardian is a simple on-account Hook for Xahau that enforces a 100 XAH per-transaction outgoing payment limit.

## How it works

1. The hook is installed on a Xahau account using a `SetHook` transaction.
2. It triggers only on `ttPAYMENT` transactions.
3. The hook:
   - Reads the originating account (`sfAccount`)
   - Verifies that the transaction is sent **from** the guarded account
   - Reads the Amount (`sfAmount`)
   - Converts the value to native drops using `AMOUNT_TO_DROPS`
   - Compares with the maximum allowed amount (100,000,000 drops = 100 XAH)
4. If the payment is:
   - **≤ 100 XAH** → `accept(...)`
   - **> 100 XAH** → `rollback(...)`
5. The hook does **not** block incoming payments or non-payment transactions.

## File Structure

/src/limit100.c         # The hook logic (C → WASM)
docs/architecture.md    # This document
README.md               # Main documentation
LICENSE                 # MIT

## Design choices

- Protect users from large mistaken transactions  
- No coding required for end-users  
- Clear messages via `accept` or `rollback`  
- Minimal complexity → predictable & reliable behavior  

---

## Future Extensions

- Configurable limit per account  
- Daily spending limits  
- Whitelists / blacklists  
- Time-based rules (office hours)  
