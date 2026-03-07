class User: 
    def __init__(self, full_name, birthday):
        self.name = full_name
        self.birthday = birthday    ## yymmdd

        name_pieces = full_name.split(" ")
        self.first_name = name_pieces[0]
        self.last_name = name_pieces[1]

user1 = User("Dave Smith", "900101")
print(user1.name)
print(user1.first_name)
print(user1.last_name)
print(user1.birthday)