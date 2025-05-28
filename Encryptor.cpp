#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// URL-decode a string (converting '+' to space and decoding hex codes)
string urlDecode(const string &value) {
    string result;
    for (size_t i = 0; i < value.length(); ++i) {
        if (value[i] == '%') {
            if (i + 2 < value.length()) {
                string hex = value.substr(i + 1, 2);
                result += static_cast<char>(strtol(hex.c_str(), NULL, 16));
                i += 2;
            }
        } else if (value[i] == '+') {
            result += ' ';
        } else {
            result += value[i];
        }
    }
    return result;
}

// Extract a parameter's value from the query string
string getParam(const string &query, const string &key) {
    size_t pos = query.find(key + "=");
    if (pos == string::npos)
        return "";
    size_t start = pos + key.length() + 1;
    size_t end = query.find("&", start);
    if (end == string::npos)
        end = query.length();
    return urlDecode(query.substr(start, end - start));
}

void createFile(const string &filename, const string &content) {
    ofstream out(filename);
    if (out) {
        out << content;
        cout << "<p>✅ File <b>" << filename << "</b> created successfully.</p>";
    } else {
        cout << "<p>❌ Error creating file.</p>";
    }
}

void encryptFile(const string &inFile, const string &outFile, int key) {
    ifstream in(inFile);
    ofstream out(outFile);
    if (!in || !out) {
        cout << "<p>❌ Error opening files.</p>";
        return;
    }
    char ch;
    while (in.get(ch)) {
        if (isalpha(ch)) {
            if (isupper(ch))
                ch = (ch - 'A' + key) % 26 + 'A';
            else
                ch = (ch - 'a' + key) % 26 + 'a';
        }
        out << ch;
    }
    cout << "<p>🔐 Encrypted <b>" << inFile << "</b> to <b>" << outFile << "</b> with key <b>" << key << "</b>.</p>";
}

void decryptFile(const string &inFile, const string &outFile, int key) {
    ifstream in(inFile);
    ofstream out(outFile);
    if (!in || !out) {
        cout << "<p>❌ Error opening files.</p>";
        return;
    }
    char ch;
    while (in.get(ch)) {
        if (isalpha(ch)) {
            if (isupper(ch))
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            else
                ch = (ch - 'a' - key + 26) % 26 + 'a';
        }
        out << ch;
    }
    cout << "<p>🔓 Decrypted <b>" << inFile << "</b> to <b>" << outFile << "</b> with key <b>" << key << "</b>.</p>";
}

int main() {
    // Send the correct HTTP header.
    cout << "Content-Type: text/html\n\n";
    
    // Seed the random number generator.
    srand(time(0));

    // Retrieve query string from the environment.
    string query = getenv("QUERY_STRING") ? getenv("QUERY_STRING") : "";
    string action = getParam(query, "action");

    if (action == "create") {
        string filename = getParam(query, "filename");
        string content = getParam(query, "content");
        createFile(filename, content);
    } else if (action == "encrypt") {
        string filename = getParam(query, "filename");
        string outputFile = getParam(query, "outputFile");
        string keyStr = getParam(query, "key");
        int key = keyStr.empty() ? (rand() % 25 + 1) : stoi(keyStr);
        encryptFile(filename, outputFile, key);
    } else if (action == "decrypt") {
        string filename = getParam(query, "filename");
        string outputFile = getParam(query, "outputFile");
        string keyStr = getParam(query, "key");
        int key = keyStr.empty() ? 0 : stoi(keyStr);
        decryptFile(filename, outputFile, key);
    } else {
        cout << "<p>❌ Unknown action.</p>";
    }

    return 0;
}