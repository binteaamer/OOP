#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Message {
private:
    string text;
public:
    Message() : text("") {}
    Message(const string &t) : text(t) {}
    virtual string toString() const { return text; }
    void setText(const string &t) { text = t; }
    string getText() const { return text; }
};

class SMS : public Message {
private:
    string recipientContactNo;
public:
    SMS() : Message(), recipientContactNo("") {}
    SMS(const string &t, const string &contact) : Message(t), recipientContactNo(contact) {}
    void setContact(const string &contact) { recipientContactNo = contact; }
    string getContact() const { return recipientContactNo; }
    string toString() const override {
        return "Recipient: " + recipientContactNo + ", Message: " + Message::toString();
    }
};

class Email : public Message {
private:
    string sender;
    string receiver;
    string subject;
public:
    Email() : Message(), sender(""), receiver(""), subject("") {}
    Email(const string &t, const string &s, const string &r, const string &sub)
        : Message(t), sender(s), receiver(r), subject(sub) {}
    string getSender() const { return sender; }
    void setSender(const string &s) { sender = s; }
    string getReceiver() const { return receiver; }
    void setReceiver(const string &r) { receiver = r; }
    string getSubject() const { return subject; }
    void setSubject(const string &sub) { subject = sub; }
    string toString() const override {
        return "Sender: " + sender + ", Receiver: " + receiver +
               ", Subject: " + subject + ", Message: " + Message::toString();
    }
};

bool ContainsKeyword(const Message &messageObject, const string &keyword) {
    return messageObject.toString().find(keyword) != string::npos;
}

string encodeMessage(const string &msg) {
    string encoded = "";
    for (char c : msg) {
        if (isalpha(c)) {
            if (isupper(c))
                encoded += (c == 'Z' ? 'A' : c + 1);
            else
                encoded += (c == 'z' ? 'a' : c + 1);
        } else {
            encoded += c;
        }
    }
    return encoded;
}

int main() {
    SMS sms1("This is an SMS message", "123-456-7890");
    Email email1("This is an Email message", "alice@example.com", "bob@example.com", "Meeting Reminder");
    cout << "SMS: " << sms1.toString() << endl;
    cout << "Email: " << email1.toString() << endl;
    
    string keyword = "SMS";
    cout << "\nDoes the SMS contain the keyword \"" << keyword << "\"? "
         << (ContainsKeyword(sms1, keyword) ? "Yes" : "No") << endl;
    keyword = "Reminder";
    cout << "Does the Email contain the keyword \"" << keyword << "\"? "
         << (ContainsKeyword(email1, keyword) ? "Yes" : "No") << endl;
    
    string originalText = "This is Java";
    string encodedText = encodeMessage(originalText);
    cout << "\nOriginal message: " << originalText << endl;
    cout << "Encoded message: " << encodedText << endl;
    
    sms1.setText("Updated SMS content");
    email1.setText("Updated Email content");
    cout << "\nAfter updating the message text:" << endl;
    cout << "SMS: " << sms1.toString() << endl;
    cout << "Email: " << email1.toString() << endl;
    
    return 0;
}
