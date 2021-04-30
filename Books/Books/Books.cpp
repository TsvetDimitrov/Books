//Създайте приложение, което да поддържа информация за издадени учебници.
//За всеки учебник се пази следната информация : заглавие, автор / творчески
//колектив / , поредно издание, ISBN номер, дата на излизане от печат и
//тираж.Учебниците могат да бъдат одобрени от Министерството на
//образованието, или все още да не са получили този сертификат.Пази се
//също и дата на одобряване.Работи се с няколко книгоразпространителя.За
//това се пази името, адреса и телефона за всеки от
//книгоразпространителите.
//Приложението да има възможност за въвеждане на произволен брой
//различни учебници и книгоразпространители(10 точки).Да има възможност за
//избор на книгоразпространител и за него да се поръчват различни
//учебници, като се изчислява общата цена на поръчката(10 точки).
//Класовете(най - малко 3 класа при реализацията) трябва да капсулира
//всичките детайли.Използват се private инстанции на променливите за
//съхраняване на различните детайли.Трябва да има най - малко два
//конструктора, public getters / setters за private инстанции на
//променливите(30 точки).
//Необходимо е да извършвате проверка на входните данни(10 точки).
//Да се предефинира операцията << , която да се използва за извеждане на
//данните(10 точки).Данните да се четат и съхраняват във файл(20
//    точки).
//    Класовете да се опишат с UML клас диаграма(10 точки).
//    Задължително данните да се въвеждат динамично, чрез меню.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class MinistryApproval {
private:
    bool isEditionApproved;
    bool sertificate;
    int idForApproval;
public:
    MinistryApproval(bool isEditionApproved, bool sertificate, int idForApproval);
    bool getIsEditionApproved();
    bool getSertificate();
    int getIdForApproval();
    void setIsEditionApproved(bool isEditionApproved);
    void setSertificate(bool sertificate);
    void setIdForApproval(int idForApproval);
    friend std::ostream& operator<<(std::ostream& os, const MinistryApproval& ministryApproval);
};

MinistryApproval::MinistryApproval(bool isEditionApproved, bool sertificate, int idForApproval) {
    this->isEditionApproved = isEditionApproved;
    this->sertificate = sertificate;
    this->idForApproval = idForApproval;
}

bool MinistryApproval::getIsEditionApproved() {
    return this->isEditionApproved;
}

bool MinistryApproval::getSertificate() {
    return this->sertificate;
}

int MinistryApproval::getIdForApproval() {
    return this->idForApproval;
}

void MinistryApproval::setIsEditionApproved(bool isEditionApproved) {
    this->isEditionApproved = isEditionApproved;
}

void MinistryApproval::setSertificate(bool sertificate) {
    this->sertificate = sertificate;
}

void MinistryApproval::setIdForApproval(int idForApproval) {
    this->idForApproval = idForApproval;
}

std::ostream& operator<<(std::ostream& os, const MinistryApproval& ministryApproval) {
    os << "IdForApproval: " << ministryApproval.idForApproval << " IsEditionApproved: " << ministryApproval.isEditionApproved
        << " Does it have sertificate? " << ministryApproval.isEditionApproved;
    return os;

}



class Book {
private:
    std::string title;
    std::string author;
    int edition;
    std::string ISBNNumber;
    int dateManufactured;
    int tiraj;
    double pricePerOne;
    int bookId; //file navigation
public:
    Book();
    Book(std::string title, std::string author, int edition, std::string ISBNNumber, int dateManufactured, int tiraj, double pricePerOne, int bookId);
    std::string getTitle();
    std::string getAuthor();
    int getEdition();
    int getISBNNumber();
    int getDateManufactured();
    int getTiraj();
    double getPricePerOne();
    int getBookId(); //file navigation
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setEdition(int edition);
    void setISBNNumber(std::string ISBNNumber);
    void setDateManufactured(int dateManufactured);
    void setTiraj(int tiraj);
    void setPricePerOne(double pricePerOne);
    void setBookId(int bookId);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
Book::Book() {
    this->title = "";
}

Book::Book(std::string title, std::string author, int edition, std::string ISBNNumber, int dateManufactured, int tiraj, double pricePerOne, int bookId) {
    this->title = title;
    this->author = author;
    this->edition = edition;
    this->ISBNNumber = ISBNNumber;
    this->dateManufactured = dateManufactured;
    this->tiraj = tiraj;
    this->pricePerOne = pricePerOne;
    this->bookId = bookId;
}

std::string Book::getTitle() {
    return this->title;
}

std::string Book::getAuthor() {
    return this->author;
}

int Book::getEdition() {
    return this->edition;
}

std::string Book::getISBNNumber() {
    return this->ISBNNumber;
}

int Book::getDateManufactured() {
    return this->dateManufactured;
}

int Book::getTiraj() {
    return this->tiraj;
}

double Book::getPricePerOne() {
    return this->pricePerOne;
}

int Book::getBookId() {
    return this->bookId;
}

void Book::setTitle(std::string title) {
    this->title = title;
}

void Book::setAuthor(std::string author) {
    this->author = author;
}

void Book::setEdition(int edition) {
    this->edition = edition;
}

void Book::setISBNNumber(int ISBNNumber) {
    this->ISBNNumber = ISBNNumber;
}

void Book::setDateManufactured(int dateManufactured) {
    this->dateManufactured = dateManufactured;
}

void Book::setTiraj(int tiraj) {
    this->tiraj = tiraj;
}

void Book::setPricePerOne(double pricePerOne) {
    this->pricePerOne = pricePerOne;
}

void Book::setBookId(int bookId) {
    this->bookId = bookId;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "BookId: " << book.bookId << " Title: " << book.title << " Author: " << book.author << " Edition: " << book.edition << " ISBNNumber: " << book.ISBNNumber
        << " YearManuFactured: " << book.dateManufactured << " Tiraj: " << book.tiraj << " PricePerOne " << book.pricePerOne;
    return os;
}


class BookSeller {
private:
    int sellerId; //file navigation
    std::string nameBookSeller;
    std::string address;
    int telNumber;
public:
    BookSeller(int sellerId, std::string nameBookSeller, std::string address, int telNumber);
    std::string getNameBookSeller();
    std::string getAddress();
    int getSellerId(); //file navigation
    int getTelNumber();
    void setNameBookSeller(std::string nameBookSeller);
    void setAddress(std::string address);
    void setSellerId(int sellerId);
    void setTelNumber(int telNumber);
    friend std::ostream& operator<<(std::ostream& os, const BookSeller& bookSeller);
};

BookSeller::BookSeller(int sellerId, std::string nameBookSeller, std::string address, int telNumber) {
    this->sellerId = sellerId;
    this->nameBookSeller = nameBookSeller;
    this->address = address;
    this->telNumber = telNumber;
}
std::string BookSeller::getNameBookSeller() {
    return this->nameBookSeller;
}

std::string BookSeller::getAddress() {
    return this->address;
}

int BookSeller::getSellerId() {
    return this->sellerId;
}

int BookSeller::getTelNumber() {
    return this->telNumber;
}

void BookSeller::setNameBookSeller(std::string nameBookSeller) {
    this->nameBookSeller = nameBookSeller;
}

void BookSeller::setAddress(std::string address) {
    this->address = address;
}

void BookSeller::setSellerId(int sellerId) {
    this->sellerId = sellerId;
}

void BookSeller::setTelNumber(int telNumber) {
    this->telNumber = telNumber;
}


std::ostream& operator<<(std::ostream& os, const BookSeller& bookSeller) {
    os << "SellerID: " << bookSeller.sellerId << " BookSellerName: " << bookSeller.nameBookSeller << " Address: " << bookSeller.address << " TelNumber: "
        << bookSeller.telNumber;
    return os;
}

void addNewBook();
void addNewBookSeller();
void addSertificate();

bool isUniqueBookId(Book object, std::string fileName);
bool isUniqueSellerID(BookSeller object, std::string fileName);
bool isUniqueApproval(MinistryApproval object, std::string fileName);
template <class T>
void appendFileWithObj(T object, std::string filename);

int main()
{
    std::cout << std::endl << "Make a choice:" << std::endl;
    std::cout << "Enter 1 - Add new book." << std::endl;
    std::cout << "Enter 2 - Add new bookSeller." << std::endl;
    std::cout << "Enter 3 - Add sertificate from the ministry." << std::endl;
    std::cout << "Enter 4 - Get all books info." << std::endl;
    std::cout << "Enter 5 - Get all book sellers info." << std::endl;
    std::cout << "Enter 6 - Get all serificates." << std::endl;
    std::cout << "Enter 7 to exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1: {
        addNewBook();
        break;
    }
    case 2: {
        addNewBookSeller();
        break;
    }
    case 3: {
        addSertificate();
        break;
    }
    case 4: {
        //std::vector<Firm> firmNames;
       // getFirmNames(firmNames);
        //for (Firm name : firmNames) {
        //    std::cout << name << std::endl;
        //}
        break;
    }
    case 5: {
        //getDepartments();
        break;
    }
    case 6: {
        //getEmployees();
        break;
    }
    case 7: {
        exit(0);
    }
    }
    main();
}

void addNewBook() {
    std::string userInput;
    std::cout << "Enter book title:" << std::endl;
    std::cin >> userInput;
    std::cout << "Enter book author:" << std::endl;
    std::string bookAuthor;
    std::cin >> bookAuthor;
    std::cout << "Enter book edition:" << std::endl;
    int edition;
    std::cin >> edition;
jump:
    std::cout << "Enter 13 digit ISBN Number:" << std::endl;
    std::string ISBNNum;
    std::cin >> ISBNNum;
    if (ISBNNum.length() != 13) {
        std::cout << "Wrong input! Try again!" << std::endl;
        goto jump;
    }
jump2:
    std::cout << "Enter year manufactured:" << std::endl;
    int yearManufactured;
    std::cin >> yearManufactured;
    if (yearManufactured > 2021) {
        std::cout << "Wrong input year! Try again!" << std::endl;
        goto jump2;
    }
    std::cout << "Enter tiraj number:" << std::endl;
    int tiraj;
    std::cin >> tiraj;
    std::cout << "Enter price per one book:" << std::endl;
    double pricePerBook;
    std::cin >> pricePerBook;
jump3:
    std::cout << "Enter unique book ID:" << std::endl;
    int bookId;
    std::cin >> bookId;
    Book book(userInput, bookAuthor, edition, ISBNNum, yearManufactured, tiraj, pricePerBook, bookId);
    bool isUnique = isUniqueBookId(book, "books.txt");
    if (!isUnique) {
        std::cout << "Entered id was not unique." << std::endl;
        goto jump3;
    }
    appendFileWithObj(book, "books.txt");
}


void addNewBookSeller() {
start:
    std::cout << "Enter the name of the book seller:" << std::endl;
    std::string bookSellerName;
    std::cin >> bookSellerName;
    std::cout << "Enter book seller address:" << std::endl;
    std::string bookSellerAddress;
    std::cin >> bookSellerAddress;
    std::cout << "Enter book seller phone number:" << std::endl;
    int bookSellerPhoneNumber;
    std::cin >> bookSellerPhoneNumber;
    std::cout << "Enter seller Id:" << std::endl;
    int sellerId;
    std::cin >> sellerId;
    BookSeller bookSeller(sellerId, bookSellerName, bookSellerAddress, bookSellerPhoneNumber);
    bool isUniqueSellerId = isUniqueSellerID(bookSeller, "bookSellers.txt");
    if (!isUniqueSellerId) {
        std::cout << "Duplicated bookSeller id, please try again..." << std::endl;
        goto start;
    }
    appendFileWithObj(bookSeller, "bookSellers.txt");
}

void addSertificate() {
    std::cout << "Enter ID for certification and approval:" << std::endl;
    int idForApproval;
    std::cin >> idForApproval;
jump:
    std::cout << "Does the books are certicified? (yes/no)" << std::endl;
    std::string isSertificiedInput;
    std::cin >> isSertificiedInput;
    bool isSertificied;
    if (isSertificiedInput.compare("yes")) {
        isSertificied = false;
    }
    else if (isSertificiedInput.compare("no")) {
        isSertificied = true;
    }
    else {
        std::cout << "Wrong input! Try again" << std::endl;
        goto jump;
    }
jump2:
    std::cout << "Does the books are approved? (yes/no)" << std::endl;
    std::string isApprovedInput;
    std::cin >> isApprovedInput;
    bool isApproved;
    if (isApprovedInput.compare("yes")) {
        isApproved = false;
    }
    else if (isApprovedInput.compare("no")) {
        isApproved = true;
    }
    else {
        std::cout << "Wrong input! Try again" << std::endl;
        goto jump2;
    }
jump3:
    std::cout << "Enter ID check for approval" << std::endl;
    int idForApproval;
    std::cin >> idForApproval;
    MinistryApproval min(isApproved, isSertificied, idForApproval);
    bool isUniqueApprovalId = isUniqueApproval(min, "ministryApproved.txt");
    if (!isUniqueApprovalId) {
        std::cout << "Entered id was not unique." << std::endl;
        goto jump3;
    }
    appendFileWithObj(min, "ministryApproved.txt");
}

template <class T>
void appendFileWithObj(T object, std::string fileName) {
    std::ofstream outfile;
    outfile.open(fileName, std::ios::app);
    if (outfile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    outfile << object << std::endl;
    outfile.close();
}

bool isUniqueBookId(Book object, std::string fileName) {
    std::ifstream infile;
    infile.open(fileName, std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    std::string ignore;
    std::string title;
    std::string author;
    int edition;
    std::string ISBNNumber;
    int dateManufactured;
    int tiraj;
    double pricePerOne;
    int bookId; //file navigation
    while (infile >> ignore >> bookId >> ignore >> title >> ignore >> author >> ignore >> edition >> ignore >> ISBNNumber >> ignore >> dateManufactured >> ignore
        >> tiraj >> ignore >> pricePerOne) {
        if (bookId == object.getBookId()) {
            infile.close();
            return false;
        }
    }
    infile.close();
    return true;
}

bool isUniqueSellerID(BookSeller object, std::string fileName) {
    std::ifstream infile;
    infile.open(fileName, std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }

    std::string ignore;
    std::string bookSellerName;
    std::string bookSellerAddress;
    int bookSellerPhoneNumber;
    int sellerId;
    while (infile >> ignore >> sellerId >> ignore >> bookSellerName >> ignore >> bookSellerAddress >> ignore >> bookSellerPhoneNumber) {
        if (sellerId == object.getSellerId()) {
            infile.close();
            return false;
        }
    }
    infile.close();
    return true;
}


bool isUniqueApproval(MinistryApproval object, std::string fileName) {
    std::ifstream infile;
    infile.open(fileName, std::ios::in);
    if (infile.fail()) {
        std::cout << "File was not found\n";
        system("PAUSE");
        exit(1);
    }
    std::string ignore;
    bool isEditionApproved;
    bool sertificate;
    int idForApproval;
    while (infile >> ignore >> idForApproval >> ignore >> isEditionApproved >> ignore >> sertificate) {
        if (idForApproval == object.getIdForApproval()) {

        }
    }
}