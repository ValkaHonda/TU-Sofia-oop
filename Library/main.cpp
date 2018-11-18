#include <iostream>
#include <vector>


using namespace std;


class BookData{
private:
    string bookName;
    vector<string> authors;
    string takenDate;
public:
    BookData(string,vector<string>,string);
    BookData();
    string getBookName() const;
    string getTakenDate();
};
BookData::BookData(){}
BookData::BookData(string bookName,vector<string> authors,string takenDate):bookName(bookName),authors(authors),takenDate(takenDate){}
string BookData::getBookName() const{
    return bookName;
}
string BookData::getTakenDate(){
    return takenDate;
}
class Library{
private:
    int booksCount;
    vector<BookData> books;
public:
    Library();
    Library(int, vector<BookData>);
    void displayBooksAtDate(string date);
    vector<BookData> getBooks() const;
    int getBooksCount() const;
};
Library::Library(){}
Library::Library(int booksCount, vector<BookData> books):booksCount(booksCount),books(books){}
vector<BookData> Library::getBooks() const{
    return books;
}
int Library::getBooksCount() const{
    return booksCount;
}

ostream& operator<<(ostream& os, const Library& library)
{
    vector<BookData> temp = library.getBooks();
    for(unsigned int i = 0; i < temp.size(); i++){
        os << temp[i].getBookName() << endl;
    }
    return os;
}

void Library::displayBooksAtDate(string date){
    vector<BookData> temp = getBooks();
    for(unsigned int i = 0; i < temp.size(); i++){
        BookData book = temp[i];
        if(book.getTakenDate() == date){
            cout << book.getBookName() << endl;
        }
    }
}

int main()
{
    vector<string> authors;
    authors.push_back("A.M.");
    BookData book1("Harry",authors,"1996-02-01");
    BookData book2("Lightning",authors,"1996-02-02");
    vector<BookData> books;
    books.push_back(book1);
    books.push_back(book2);
    Library library(2,books);
    cout << library << endl;
    library.displayBooksAtDate("1996-02-02");
    return 0;
}
