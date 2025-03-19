
/*Visualize a digital multimedia library management system designed
 to catalog and circulate a diverse range of media items,

including books, DVDs, CDs, and magazines. The Media class serves
as the base, encapsulating core data members such as title,publicationDate, uniqueID, and publisher. It provides
functions like displayInfo() to output media details,
checkOut() to process lending, and returnItem() 
to handle returns.

Derived classes—Book, DVD, CD, and Magazine—
introduce additional attributes:

Book includes author, ISBN, and numberOfPages, 
modifying displayInfo() for books.

DVD incorporates director, duration, and rating,
 updating displayInfo() for movie details.

CD includes artist, numberOfTracks, and genre, 
adapting displayInfo() for music albums.

The system supports function overloading for searching media
by different attributes (e.g., title, author, or publication year).*/

#include<iostream>
#include<string>
using namespace std;

class media {
    string title;
    string publicationDate;
    const int uniqueID;
    string publisher;
    public:
    media(string t, string pdate, int id,string p):title(t),
    publicationDate(pdate),uniqueID(id), publisher(p){}

    virtual void displayInfo(){
        cout<<"title : "<< title <<endl;
        cout<<"publication/release: "<< publicationDate<<endl;
        cout<<"publisher/director : "<<publisher<<endl;
    }
    void checkout(){
    cout<<"checking out item"<<endl;

    }
    void returnItem(){
        cout<<"returning done "<<endl;
    }
bool search(string t){return title==t;}
bool search(int id){return uniqueID==id;}
};

class book: public media{
    string author;
    string ISBN;
    int numOfPages;
    public:
    book(string t, string pdate, int id,string p, string a, 
        string isbn, int n):media(t,pdate,id,p), author(a),
        ISBN(isbn),numOfPages(n)
        {}
void displayInfo()override{
    cout << "Author: " << author << "\nISBN: " << ISBN 
    << "\nPages: " << numOfPages << endl;
}

};

class dvd: public media{
string director;
int duration;
float rating;
public:
dvd(string t, string pdate, int id,string p,string d, int dur,
float r):media(t,pdate,id,p), director(d), duration(dur),rating(r){}

void displayInfo()override {
    media::displayInfo();
    cout << "Director: " << director << "\nDuration: " << 
    duration << " min\nRating: " << rating << "/5" << endl;
}


};


class CD : public media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, int id, string pub, string art, int tracks, string g)
        : media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(g) {}

    void displayInfo() override {
        media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};





int main() {
    book b1("C++ Programming", "2022", 101, "O'Reilly", "Bjarne Stroustrup", "123-456-789", 350);
    dvd d1("Inception", "2010", 201, "Warner Bros.", "Christopher Nolan", 148, 4.8);
    CD c1("Thriller", "1982", 301, "Epic Records", "Michael Jackson", 9, "Pop");

    cout << "\n--- Library Collection ---\n";
    b1.displayInfo();
    cout << "---------------------\n";
    d1.displayInfo();
    cout << "---------------------\n";
    c1.displayInfo();
    cout << "---------------------\n";

    // Check out and return example
    b1.media::checkout();
    b1.media::returnItem();
    if(b1.media::search(101))
    {
        cout<<"book found"<<endl;
    }
    


    return 0;
}
