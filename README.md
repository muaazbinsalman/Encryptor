# 🔐 Encryptor - File Encryption & Decryption Manager

## 📌 About
**Encryptor** is a simple web-based **File Encryption & Decryption Manager** that allows users to:
- **Create files**
- **Encrypt files** using a Caesar cipher
- **Decrypt files** using a provided key

Built using **C++ for CGI scripting** with a **JavaScript-powered frontend** for seamless interactions.

## 🚀 Features
✅ **File Creation**: Create and store text files.  
✅ **Encryption**: Apply a shift cipher for basic encryption.  
✅ **Decryption**: Reverse the shift cipher to retrieve original data.  
✅ **AJAX-Powered**: Frontend dynamically communicates with backend.  

## 🛠 Installation
### 1️⃣ Clone the Repository
```bash
git clone https://github.com/your-username/Encryptor.git
```

### 2️⃣ Setup on XAMPP (Apache Server)
- Place project files in `C:/xampp/htdocs/Encryptor/`
- Ensure `.htaccess` allows CGI execution:
  ```
  Options +ExecCGI
  AddHandler cgi-script .cgi
  ```

### 3️⃣ Compile the CGI Script
```bash
cd C:/xampp/htdocs/Encryptor
g++ encryptor.cpp -o encryptor.cgi -O2
```

### 4️⃣ Restart Apache & Open Browser
Visit:
```
http://localhost/Encryptor/index.html
```

## 📂 Project Structure
```
Encryptor/
├── index.html          # Frontend UI
├── encryptor.cpp       # CGI backend source
├── encryptor.cgi       # Compiled C++ CGI executable
├── .htaccess           # Enables CGI execution
└── README.md           # Project Documentation
```

## ✨ Usage
1. Open **index.html** in a browser.
2. Create a file with **filename** and **content**.
3. Encrypt the file with a **shift key** (1-25).
4. Decrypt an encrypted file using the correct **key**.

## 🎯 Contributing
Want to improve Encryptor? Feel free to:
- **Fork the repo**
- **Create a pull request**
- **Suggest enhancements**

## 👥 Contributors
🚀 **Muaaz Bin Salman** – Lead Developer & Main Contributor  
🛠️ **Aayan Rashid** – Co-Author 

## 📖 License
This project is licensed under the **MIT License**.
