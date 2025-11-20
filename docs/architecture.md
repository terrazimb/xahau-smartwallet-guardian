# SmartWallet Guardian — Architecture Overview

SmartWallet Guardian is an on-account Hook for Xahau that enforces a hard limit of 100 XAH on outgoing payments.

---

## How the Hook Works

1. Trigger only on `ttPAYMENT`
2. Validate the transaction is **sent from** the guarded account
3. Read the amount (`sfAmount`)
4. Convert from issued format → native drops
5. Compare against 100,000,000 drops (100 XAH)
6. Decision:
   - ≤100 XAH → `accept`
   - >100 XAH → `rollback`
7. Incoming payments and non-payment transactions are always accepted

---

## File Structure

/src/limit100.c # The Hook logic (C → WASM)
/docs/architecture.md # This document
/README.md # Main documentation
/LICENSE # MIT License
/submission.md # Contest submission file

---


---

## Design Choices

- Minimal logic → predictable and safe  
- Helpful rollback messages  
- No coding required for end-users  
- Useful as a template for bigger security systems

---

## Future Extensions

- User-configurable limits  
- Daily spending caps  
- Whitelist / blacklist  
- Smart time windows (office hours)  

