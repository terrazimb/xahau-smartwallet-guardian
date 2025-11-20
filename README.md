# Xahau SmartWallet Guardian

SmartWallet Guardian is a simple, no-code security Hook for Xahau Mainnet that protects users by limiting outgoing payments to **100 XAH per transaction**.  
This prevents accidental large transfers and reduces scam-related high-value losses.

The project includes:

- A working Xahau Hook (`limit100.c`)
- A public online service website
- Documentation & architecture notes
- A demo Xahau account with the Hook installed

---

## 🚀 Features

- Blocks outgoing payments **>100 XAH**
- Allows outgoing payments **≤100 XAH**
- Incoming payments always allowed
- Minimal, reliable, and beginner-friendly logic
- 100% on-chain via Xahau Hooks
- Installable without coding using Hooks Builder + Xaman

---

## 🧱 Architecture Overview

The Hook:

1. Runs only on `ttPAYMENT`
2. Checks sender = guarded account  
3. Reads `sfAmount`
4. Converts to drops with `AMOUNT_TO_DROPS`
5. If amount > 100 XAH → rollback  
6. Else → accept

Full architecture: `/docs/architecture.md`

---

## 📁 Project Structure

/src/limit100.c # The Hook logic (C → WASM)
/docs/architecture.md # Architecture overview
/README.md # Main documentation
/LICENSE # MIT License
/submission.md # Contest submission file

---

## 🔧 Demo Account (Hook Installed)

A public demo account with SmartWallet Guardian installed:

rsMd9CdXk71RtkgiuQHJZsHqMw9qxssERc

---

Behavior:

- Send ≤100 XAH → ACCEPT  
- Send >100 XAH → REJECTED  
- Receive XAH → ALWAYS ACCEPTED  

---

## 🧪 Testing

### ✔ Hooks Builder (no real funds)
1. Go to TEST tab  
2. Tx Type: Payment  
3. Amount: 50 → should ACCEPT  
4. Amount: 150 → should ROLLBACK  
5. Fee: use **Suggest** button  
6. Run Test  

### ✔ Live on Xahau Mainnet
From the guarded account:

| Amount | Result |
|--------|--------|
| 50 XAH | ✔ Accepted |
| 120 XAH | ❌ Blocked |
| Incoming → any amount | ✔ Allowed |

---

## 🛠 Deploying the Hook

1. Open Xahau Hooks Builder  
2. Paste `src/limit100.c`  
3. Click **Compile to WASM**  
4. Go to **Deploy**  
5. Network: Xahau Mainnet  
6. HookOn: `ttPAYMENT`  
7. Upload compiled WASM  
8. Click **Set Hook**  
9. Sign with **Xaman**

---

## 🌐 Online Service

For non-technical users:  
https://proactiveducation.com/xahau-smartwallet-guardian/

This site explains SmartWallet Guardian in simple language and links to the Hook installer.

---

## 🛣 Future Extensions

- Custom user-defined limit  
- Daily/weekly spending caps  
- Whitelists & blacklists  
- Time-window restrictions (office hours)  
- Multi-rule guardian dashboard  

---

## 📄 License

MIT License – free to use and modify.

