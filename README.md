# Arduino to Arduino Bit-Level Communication (Interrupt-Based)

⚡ A fast, lightweight and low-level communication protocol between two Arduino Mega boards using digital pins and interrupt-driven bit reading.

---

## 🔧 Project Overview

This project implements **a custom synchronous serial communication** between two Arduino Mega boards using two wires:

- **Clock** (`clock_in` / `clock_out`)
- **Data** (`data_in` / `data_out`)

The sender transmits data bit-by-bit on each clock pulse.  
The receiver uses **hardware interrupts** to read the data bits in real-time and reconstruct bytes.

---

## 💡 Why this project?

This project showcases:
- Low-level manipulation of data using bitwise operations
- Use of `attachInterrupt()` and ISR for precise timing
- Real-time data reception without using standard protocols (like I2C/SPI/UART)
- Efficient use of `millis()` instead of `delay()`
- Clean, modular code structure with a focus on timing and reliability

If you're looking for an engineer who understands both software **and** how it interacts with hardware in real time – this project is a live example.

---

## 🛠️ Hardware Requirements

- 2 × Arduino Mega boards
- 2 × Jumper wires:
  - One for **Clock**
  - One for **Data**
- Common ground between the boards

---

## 🔌 Wiring

| Sender Pin | Receiver Pin |
|------------|--------------|
| pin 2 (Clock) | pin 2 (Clock) |
| pin 3 (Data)  | pin 3 (Data)  |

Make sure both boards share a common GND connection.

---

## 📂 File Structure

- `sender.ino` – Sends user-input strings from Serial Monitor bit-by-bit to the other board
- `receiver.ino` – Receives data bits via interrupts, reconstructs characters, and prints the received word after a timeout

---

## 🧠 How it works

1. **Sender Side**
   - Waits for a user to input a string via Serial Monitor
   - Sends each character bit-by-bit (MSB first)
   - Toggling the clock pin and setting the data pin accordingly

2. **Receiver Side**
   - Listens for **RISING edge interrupts** on the clock line
   - Reads one bit on each interrupt from the data line
   - Accumulates 8 bits into a byte
   - Appends the character to a string buffer
   - If no new bits arrive for 2.5 seconds, it prints the full string

---

## 🧪 Example

https://youtu.be/2Bm-ze5r-bk



