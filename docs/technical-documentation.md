<h1 align="center">Technical Documentation: HealthMobi</h1>
<a name="top"></a>


## Table of Contents
1. [Project Overview](#1-project-overview)
2. [Key Features](#2-key-features)
3. [Tech Stack](#3-tech-stack)
4. [System Architecture](#4-system-architecture)
5. [User Flow](#5-user-flow)
6. [How It Works](#6-how-it-works)
7. [Conclusion](#conclusion)


## 1. Project Overview

**HealthMobi** is a smart **Medication Adherence Monitoring System** designed to bridge the gap between doctors and patients. It digitizes physical prescriptions, schedules medications automatically, monitors intake using **smart pillboxes**, and encourages users with **daily motivational quotes** and **reward-based incentives**.

By leveraging a blend of AI, embedded systems, and multi-language support, HealthMobi ensures that patients, especially the elderly, never miss their medications.

## 2. Key Features

---

### 2.1 Prescription Digitisation

Upload prescriptions via camera to digitise medication data.

**How it works:**
- Click **Upload Prescription** → Camera opens
- Capture the prescription → Processes text
- Medications are added to today’s schedule with dosage timings

**User Feedback:**  
*“Medication added to mobile successfully.”*

---

### 2.2 Medication Scheduling & Tracking

Displays:
- Medication names
- Icons indicating dosage timing (🌞 Morning, 🌜 Night, etc.)
- Coloured adherence status indicators:
  - 🔴 **Red**: Not taken today
  - 🟠 **Orange**: Time to take is upcoming
  - 🟢 **Green**: Medicine taken

---

### 2.3 Smart Pillbox Integration

**What it is:**  
A smart pillbox for real-time adherence monitoring.

**How it works:**
- Pillbox buzzer rings when it’s time for medication
- WhatsApp notification:  
  📲 *“Have the medicine and open box number 1.”*
- Pillbox tracks compartment openings; status turns green in the app if the medicine is taken

---

### 2.4 AI Chatbot Assistant

**Purpose:**  
Natural language interface for medication management.

**Capabilities:**
- Supports **English** and **Hindi** inputs
- Provides daily medication schedules on request
- Allows users to add/update medication timings
- Dynamically updates the schedule in real-time

---

### 2.5 Daily Motivation Quote

- Displays motivational quotes **daily** within the app
- Sends motivational **notifications** in the user’s regional language (set during registration)
- Boosts user encouragement and consistency

---

### 2.6 Reward System

**Incentivises consistent medication intake** by offering:
- 🎁 Discounts (e.g., **10% off doctor check-ups**, medicine offers)
- Encouraging long-term adherence via gamification

## 3. Tech Stack

The project has a multi-layered tech stack to bridge hardware, software, and AI components:

- **Python**
- **Flutter**
- **PyTesseract**
- **LangChain** 
- **C (Embedded)**
- **ESP32**
- **Node.js**
- **FastAPI**
- **Socket.IO**

## 4. System Architecture

The following diagram shows how different components of HealthMobi interact:

```
[User] ⇄ [Flutter App] ⇄ [FastAPI Server (Python)]
                         ⇅       ↑         ⇡
                  [PyTesseract OCR]    [LangChain AI Chatbot]
                         ↑
                   [Prescription Image]
                         
[ESP32 Pillbox] ⇄ [FastAPI or Node Socket Server] ⇄ [Mobile App]
```

## 5. User Flow

The following diagram illustrates the typical user journey within the HealthMobi app, from uploading a prescription to receiving medication reminders and rewards:

<div align="center">

Start  
  ↓  
User Registration  
  ↓  
Upload Prescription  
  ↓  
Medication Schedule Created  
  ↓  
Smart Pillbox Notification Sent  
  ↓  
User Takes Medicine  
  ↓  
App Updates Status (🔴 Not Taken / 🟠 Upcoming / 🟢 Taken)  
  ↓  
User can interact with AI Chatbot (for schedule updates / queries)  
  ↓  
Daily Motivational Quote Displayed  
  ↓  
Reward Points Updated  
  ↓  
End  

</div>

## 6. How It Works

This section breaks down the inner workings of HealthMobi from the moment a user joins, to real-time pillbox pings and AI chat support.

---

### 1. User Registration & Profile Setup
- The user signs up and selects their **preferred language**.
- Basic profile and health info is stored securely in the backend.

---

### 2. Prescription Upload & OCR
- User clicks **Upload Prescription** → Camera opens → Image is captured.
- Image is sent to **FastAPI** backend.
- **PyTesseract** performs OCR (Optical Character Recognition) on the image.
- Extracted medication names, dosages, and timings are parsed and stored.

---

### 3. Schedule Creation
- Based on OCR data, the app automatically:
  - Creates a **daily medication schedule**.
  - Assigns timings (🌞 Morning, 🌆 Afternoon, 🌜 Night).
  - Adds default adherence status: 🔴 Not Taken.

---

### 4. Smart Pillbox Sync (IoT)
- At the time of medication:
  - **ESP32 smart pillbox** buzzes.
  - Sends a real-time message via **Socket.IO server** to the app.
  - App shows notification:  
    *“Time to take your medicine. Open Pillbox number 1.”*
- If user opens the right box:
  - Signal sent back to the app.
  - Status updates to 🟢 Taken.

---

### 5. AI Chatbot Assistant (LangChain)
- User types:  
  “What medicine should I take now?”  
  “Change my night dose to 9 PM.”
- The chatbot, powered by **LangChain**, fetches or updates schedules on the fly.
- Supports **English and Hindi**, with plans for more languages.

---

### 6. Motivation & Rewards System
- Each day the user follows the schedule:
  - Earns reward points.
  - Gets motivational quote in their **preferred language**.
- Points can later be redeemed for:
  - **10% off doctor check-ups**
  - **Medicine discounts**

---

### Tech in Action

| Component          | Role                                                                 |
|--------------------|----------------------------------------------------------------------|
| **Flutter App**     | UI/UX interface for user interaction                                 |
| **FastAPI (Python)**| Backend server for API and OCR processing                            |
| **PyTesseract**     | OCR engine to read text from prescriptions                           |
| **LangChain**       | Powers the AI chatbot                                                |
| **ESP32**           | Embedded system inside the smart pillbox                             |
| **Socket.IO**       | Real-time communication between hardware and app                     |

# Conclusion

HealthMobi combines the power of AI, embedded systems, and mobile tech to tackle one of healthcare’s most critical issues, **medication adherence**.

With a user-centric design, smart hardware integration, and multilingual support, this system ensures no patient is left behind, especially the elderly.

> *"It's more than just an app — it’s a step towards compassionate, connected, and tech-powered healthcare."*

<div align="center">

[🔝 Back to Top](#top)

</div>
