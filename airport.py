class Service:
    def __init__(self, name, branch, contact_number):
        self.name = name
        self.branch = branch.capitalize()
        self.contact_number = contact_number

    def __str__(self):
        return f"{self.branch} {self.name} can be contacted at {self.contact_number}.\n"

service = Service("Ryanair", "airline", 9990003209)
print(service)