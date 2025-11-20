# SmartWallet Guardian — Xahau Contest Submission

**Author:** terrazimb
**Project:** SmartWallet Guardian  
**Category:** Web Services + Hooks  
**Online Service:** https://proactiveducation.com/xahau-smartwallet-guardian/  
**GitHub Repo:** https://github.com/terrazimb/xahau-smartwallet-guardian  

---

## 1. Summary

SmartWallet Guardian is a no-code security Hook that protects Xahau users by limiting outgoing payments to 100 XAH.  
It prevents high-value mistakes and scam-triggered transfers.

---

## 2. Problem

Wallets normally send any signed transaction, even if:

- the amount is too large  
- the destination is wrong  
- the user is tricked into confirming  

Users need an easy way to make their wallet “smart.”

---

## 3. Solution

A small on-account Hook:

- Checks outgoing payments
- Reads amount
- Blocks transfers above 100 XAH
- Requires no coding from the user
- Installable in minutes using Hooks Builder + Xaman

---

## 4. Architecture

See `/docs/architecture.md`.

---

## 5. Online Service

A public web page that explains the Guardian to non-developers and links to the Hooks Builder installer.

https://proactiveducation.com/xahau-smartwallet-guardian/

---

## 6. Demo Account

rsMd9CdXk71RtkgiuQHJZsHqMw9qxssERc

Outgoing over 100 XAH is blocked.

---

## 7. Testing

- Hooks Builder TEST tab  
- Mainnet test: ≤100 accept, >100 rollback  

---

## 8. Future Work

- Customizable limit  
- Daily spending caps  
- Address whitelisting  
- Dashboard UI  



