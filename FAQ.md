# 📌 Frequently Asked Questions (FAQ)

Welcome to the **HealthMobi** project!  
This document provides answers to common setup, troubleshooting, and contribution questions.  
Please review these FAQs before raising an issue.

---

## ❓ General Setup

### 1. How do I run the backend server?

- Navigate to the Backend folder:

    ```bash
    cd Backend
    npm install
    node server.js
    ```

- The server will start on **http://localhost:3001**.

- ✅ If you see this response when visiting [http://localhost:3001](http://localhost:3001):

    ```json
    {"message":"Welcome to the healthmobi!"}
    ```

  It means the backend is running correctly.

---

### 2. Why do I get `ECONNREFUSED 127.0.0.1:3306`?

This error means the backend cannot connect to MySQL.

**Fix:**

1. Ensure MySQL is running:

    ```bash
    brew services start mysql
    ```

2. Log in to MySQL:

    ```bash
    mysql -u root -p
    ```

3. Create the database:

    ```sql
    CREATE DATABASE medical_system;
    ```

4. Add credentials in `Backend/.env`:

    ```env
    DB_HOST=localhost
    DB_USER=root
    DB_PASSWORD=
    DB_NAME=medical_system
    DB_PORT=3306
    ```

---

### 3. Where do I set environment variables?

- Create a `.env` file inside the Backend folder.

**Example:**

    ```env
    DB_HOST=localhost
    DB_USER=root
    DB_PASSWORD=
    DB_NAME=medical_system
    DB_PORT=3306

    TWILIO_ACCOUNT_SID=your_twilio_sid
    TWILIO_AUTH_TOKEN=your_twilio_token
    ```

---

### 4. How do I run the frontend?

- If the project uses **Flutter**:

    ```bash
    cd Frontend
    flutter pub get
    flutter run
    ```

- If the project uses **React**:

    ```bash
    cd Frontend
    npm install
    npm start
    ```

---

## ❓ Troubleshooting

### 5. I get `zsh: command not found: flutter`.

This means Flutter is not installed.

**Fix:**

    ```bash
    brew install --cask flutter
    flutter --version
    ```

---

### 6. I see “Unable to connect to prescription extraction AI service.”

This appears when the external AI microservice is not running.

**Fix:**

- Check `.env` for:

    ```env
    PRESCRIPTION_AI_URL=<your-service-url>
    ```

- Contact maintainers if the value is missing or the service isn’t available.

---

### 7. How do I test Twilio notifications locally?

1. Install ngrok and start it:

    ```bash
    brew install ngrok
    ngrok http 3001
    ```

2. Copy the generated `https://xxxx.ngrok.io` URL and set it in the Twilio webhook.

3. Test with:

    ```bash
    curl -X POST http://localhost:3001/notify -d "message=Test notification"
    ```

---

## ❓ Contribution Guidelines

### 8. How do I contribute to HealthMobi?

1. Fork the repository on GitHub.

2. Clone your fork:

    ```bash
    git clone <your-fork-url>
    cd Medical-Adherence-Monitoring-System
    ```

3. Create a new branch:

    ```bash
    git checkout -b add-faq
    ```

4. Make your changes.

5. Commit and push:

    ```bash
    git add .
    git commit -m "Added FAQ section"
    git push origin add-faq
    ```

6. Open a Pull Request to the original repository.

---

<p align="center">
  <a href="#top" style="font-size: 18px; padding: 8px 16px; display: inline-block; border: 1px solid #ccc; border-radius: 6px; text-decoration: none;">
    ⬆️ Back to Top
  </a>
</p>
