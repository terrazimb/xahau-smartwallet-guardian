# Xahau SmartWallet Guardian

SmartWallet Guardian is a **no-code security hook** for Xahau wallets.  
It automatically limits outgoing payments to **100 XAH per transaction** to protect users from mistakes, scams, and accidental large transfers.

This project is built for the Xahau Contest as a simple and practical example of how Hooks can improve everyday safety on the Xahau network.

---

## 🚀 Features

- Protects your wallet from sending more than **100 XAH**
- Blocks only **outgoing** payments — incoming payments remain fully allowed
- Works entirely on-chain using Xahau Hooks
- No coding required for end-users
- Easy deployment through the official Xahau Hooks Builder
- Fully open-source

---

## 🏗 Architecture

The Hook is implemented in `src/limit100.c` using the official Hooks API.

Logic:

1. Trigger only on `ttPAYMENT`
2. Check if transaction is from the guarded account
3. Read `sfAmount` from the transaction
4. Convert amount to drops using `AMOUNT_TO_DROPS`
5. Compare against `100,000,000` drops (100 XAH)
6. `accept` if below limit, `rollback` if above limit

Full design docs: `/docs/architecture.md`

---

## 📦 Project Structure

src/
limit100.c # Hook implementation
docs/
architecture.md # Internal documentation
README.md # Main project info
LICENSE # MIT License


---

## 🧪 Testing

### 1. Using Hooks Builder (no real funds)

1. Open the **TEST** tab in Hooks Builder  
2. Choose `Payment` as the transaction type  
3. Test two cases:
   - 50 XAH → **ACCEPT**
   - 150 XAH → **ROLLBACK**
4. Use **Suggest** button for proper fees

### 2. Live test (Xahau Mainnet)

Once deployed on your real account:

- Sending **≤100 XAH** → success  
- Sending **>100 XAH** → blocked by hook  
- Incoming payments → always allowed  

---

## 🧩 Deploying the Hook

1. Open Xahau Hooks Builder  
2. Paste the content from `src/limit100.c`  
3. Click **Compile to WASM**  
4. Go to **Deploy** tab  
5. Select:
   - Network: **Xahau Mainnet**
   - HookOn: `ttPAYMENT`
   - WASM file: `limit100.wasm`
6. Click **Set Hook**
7. Scan & sign using **Xaman**

---

## 🌐 Online Service

https://proactiveducation.com/xahau-smartwallet-guardian/

This page explains the Guardian Hook in simple terms so non-developers can use it.

---

## 🛣 Roadmap

- Customizable limits (user-defined)
- Daily spending caps
- Emergency freeze mode
- Whitelisted accounts
- Dashboard UI to manage policies

---

## 📄 License

This project is released under the **MIT License**.
