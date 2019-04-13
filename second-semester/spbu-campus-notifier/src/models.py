from mongoengine import *


class Room(Document):
    dormitory = IntField(required=True)
    room_number = StringField(required=True)
    id = StringField(required=True, primary_key=True)
    available_female_beds = IntField(required=True)
    available_male_beds = IntField(required=True)
    fully_available_beds = IntField(required=True)
    capacity = IntField(required=True)


class Wish(Document):
    dormitory = IntField()
    female_beds = IntField()
    male_beds = IntField()
    all_beds = IntField()
    capacity = IntField()

    def __str__(self):
        wish_str = ''
        if self.dormitory:
            wish_str += f'Dorm: {self.dormitory} '
        if self.female_beds:
            wish_str += f'f: {self.female_beds} '
        if self.male_beds:
            wish_str += f'm: {self.male_beds} '
        if self.all_beds:
            wish_str += f'a: {self.all_beds} '
        if self.capacity:
            wish_str += f'c: {self.capacity} '
        return wish_str


RUS_LANG = 0
ENG_LANG = 1


class User(Document):
    id = IntField(max_length=50, required=True, primary_key=True)
    language = IntField(required=True)
    wishes = ListField(Wish())
    cur_wish_number = IntField()
