import csv

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
            print(book)
            all_books.append(book)

    # Allow adding new books, enlist them and print resulting list
    while True:
        if not is_new_book():
            break
        new_book = Book.save_new_book()
        new_entry(all_books, new_book)
    print_all_books(all_books)

    # Access file, save entries (objects) as dict
    with open("all_books.csv", "a") as file:
        # for book in sorted(all_books, key=lambda book: book["author"]):
        for book in all_books:
            writer = csv.DictWriter(file, fieldnames=["title", "author", "publication_year"])
            writer.writerow({"title": book.title, "author": book.author, "publication_year": book.publication_year})

if __name__ == "__main__":
    main()