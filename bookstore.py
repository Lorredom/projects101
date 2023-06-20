class Book:
    def __init__(self, title, author, publication_year):
        self.title = title
        self.author = author
        self.publication_year = publication_year
    
    def __str__(self):
        return f"{self.title} by {self.author} was published in {self.publication_year}"


def is_new_book():
    decision = input("Do you wish to add to the bookstore? [Takes yes or no ]\n")
    if decision == "yes":
        return True
    return False

def ask_for_new_book():
    title, author, publication_year = input("What book would you like to add?: \
        [takes title, author's last name and publication year, separate by commas]\n").strip().split(",")
    new_book = Book(title, author, publication_year)
    return new_book

def new_entry(all_books, new_book):
    all_books.append(new_book)

def print_all_books(all_books):
    for book in all_books:
        print(book)

def main():
    all_books = []
    with open("all_books.csv") as file:
        for line in file:
            title, author, publication_year = line.rstrip().split(",")
            book = {"title": title, "author": author, "publicaiton_year": publication_year}
            all_books.append(book)
    while True:
        if not is_new_book():
            break
        new_book = ask_for_new_book()
        new_entry(all_books, new_book)
    print_all_books(all_books)

    with open("all_books.csv", "a") as file:
        for book in all_books:
            file.write(f"{book.title}, {book.author}, {book.publication_year}\n")

main()