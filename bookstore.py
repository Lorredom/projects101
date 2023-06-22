import csv, sys

class Book:
    def __init__(self, title, author, publication_year):
        self.title = title
        self.author = author
        self.publication_year = publication_year
    
    def __str__(self):
        return f"{self.title} by {self.author} was published in {self.publication_year}"
    
    @classmethod
    def save_new_book(cls):
        title, author, publication_year = input("What book would you like to add?: \
            [takes title, author's last name and publication year, separated by [, ] a comma and a space]\n").strip().split(", ")
        new_book = cls(title, author, publication_year)
        return new_book

def menu(all_books):
    print("MENU: \
        1. Add new book \
        2. Print all books\
        3. Delete a book\
        4. Quit program\n")

    while True:
        option=int(input("Choose menu option by number [takes 1, 2, 3 or 4]\n"))
        match option:
            case 1:
                add_new_book(all_books)
            case 2:
                print("Printing")
                print_all_books(all_books)
            case 3:
                should_delete_book(all_books)
            case 4:
                print("Exiting")
                sys.exit()
            case _:
                continue

def add_new_book(all_books):
    # Allow adding new books, enlist them and print resulting list
    while True:
        if not is_new_book():
            menu(all_books)
            break
        new_book = Book.save_new_book()
        new_entry(all_books, new_book)

    # Access file, save entries (objects) as dict
    with open("all_books.csv", "a") as file:
        # for book in sorted(all_books, key=lambda book: book["author"]):
        for book in all_books:
            writer = csv.DictWriter(file, fieldnames=["title", "author", "publication_year"])
            writer.writerow({"title": book.title, "author": book.author, "publication_year": book.publication_year})

    print_all_books(all_books)


def delete_book(all_books, title=None, author=None):
    if title != None:
        print("m here")
        for i, book in enumerate(all_books):
            if book.title == title:
                decision = input("Book found. Do you wish to delete? [takes yes or no]\n")
                del all_books[i]
            else:
                print("Could not find. Returning to menu()")
                return

    elif author != None: 
        for i, book in enumerate(all_books):
            if book.author == author:
                decision = input("Book found. Do you wish to delete? [takes yes or no]\n")
                del all_books[i]
            else:
                print("Could not find. Returning to menu()")
                return

    # Access file, save entries (objects) as dict
    with open("all_books.csv", "w") as file:
        # for book in sorted(all_books, key=lambda book: book["author"]):
        for book in all_books:
            writer = csv.DictWriter(file, fieldnames=["title", "author", "publication_year"])
            writer.writerow({"title": book.title, "author": book.author, "publication_year": book.publication_year})
    print_all_books(all_books)

def should_delete_book(all_books):
    search_filter = input("Filter your search: title or author's last name [takes 't' or 'a]\n").upper()
    match search_filter:
        case "T":
            to_be_deleted = input("Enter title: \n")
            delete_book(all_books, title=to_be_deleted)
        case "A":
            to_be_deleted = input("Enter author's last name: \n")
            delete_book(all_books, author=to_be_deleted)
        case _:
            print("Book not found")
            menu(all_books)

def is_new_book():
    decision = input("Do you wish to add to the bookstore? [Takes yes or no ]\n")
    if decision == "yes":
        return True
    return False

def new_entry(all_books, new_book):
    all_books.append(new_book)

def print_all_books(all_books):
    for book in all_books:
        print(book)

def main():
    all_books = []

    # 1# Access .csv file
    # 2# Create an instance for every entry (dict-->object)
    # 3# Add objects to the all_books list
    with open("all_books.csv") as file:
        reader = csv.DictReader(file, fieldnames=["title", "author", "publication_year"])
        for entry in reader:
            book = Book(entry["title"], entry["author"], entry["publication_year"])
            # print(book)
            all_books.append(book)

    menu(all_books)

if __name__ == "__main__":
    main()