import telebot
from telebot import types, apihelper
from src.models import User, ENG_LANG, RUS_LANG

IP = 'IP'  # Proxy credentials
PORT = 'Port'
USERNAME = 'Login'
PASSWORD = 'Password'

apihelper.proxy = {
    'https': f'socks5://{USERNAME}:{PASSWORD}@{IP}:{PORT}'
}
bot = telebot.TeleBot('Telegram Bot Token')  # Telegram bot token

buttons = {
    'wish_list_btn': ('Мои запросы', 'My wishes'),
    'settings_btn': ('Настройки', 'Settings'),
    'language_settings_btn': ('Язык', 'Language'),
    'language_btn': ('Русский', 'English'),
    'info_btn': ('Информация', 'Information'),
    'back_from_settings': ('🔙', '🔙'),
    'new_wish': ('➕', '➕'),
    'status_btn': ('Статус', 'Status'),
    'deny_wish': ('Отказаться', 'Deny'),
    'back_from_wish': ('⬅️', '⬅️'),
    'back_from_wishes_list': ('⏪', '⏪'),
    'add_wish': ('➕', '➕'),
    'unspecified_param_btn': ('Не выбрано', 'Not specified'),
    'dormitory_btn': ('Общежитие', "Dormitory"),
    'female_beds_btn': ('Количество свободных женских мест', 'Available Female Beds'),
    'male_beds_btn': ('Количество свободных мужских мест', 'Available Male Beds'),
    '_btn': ('Количество полностью свободных мест', 'Fully Available Beds'),
    '_btn': ('Общее количество мест в комнате', 'Capacity'),
}

messages = {
    'choose_lang': ('Выберите язык бота', 'Choose bot language'),
    'menu': ('Меню', 'Menu'),
    'wish_list': ('Список запросов', 'Wish list'),
}


@bot.message_handler(commands=['start'])
def start(message):
    user = User(id=message.chat.id, language=ENG_LANG, cur_wish_number=-1)
    user.save()
    # bot.send_message(message.chat.id, messages['start_message'][lang])
    open_language_settings(message)


@bot.message_handler(
    func=lambda message: message and message.text in buttons['back_from_settings'] or message.text in buttons[
        'back_from_wishes_list'])
def open_main_menu(message):
    markup = types.ReplyKeyboardMarkup(row_width=1)
    bottun1 = types.KeyboardButton(buttons['wish_list_btn'][User.objects.get(id=message.chat.id).language])
    bottun2 = types.KeyboardButton(buttons['settings_btn'][User.objects.get(id=message.chat.id).language])
    markup.add(bottun1, bottun2)
    bot.send_message(message.chat.id, messages['menu'][User.objects.get(id=message.chat.id).language],
                     reply_markup=markup)


@bot.message_handler(func=lambda message: message and message.text in buttons['language_settings_btn'])
def open_language_settings(message):
    markup = types.ReplyKeyboardMarkup(row_width=1)
    bottun1 = types.KeyboardButton('Русский')
    bottun2 = types.KeyboardButton('English')
    markup.add(bottun1, bottun2)
    bot.send_message(message.chat.id, messages['choose_lang'][User.objects.get(id=message.chat.id).language],
                     reply_markup=markup)


@bot.message_handler(func=lambda message: message and message.text in buttons['language_btn'])
def change_language(message):
    user = User.objects.get(id=message.chat.id)
    if message.text == buttons['language_btn'][0]:
        user.language = RUS_LANG
    if message.text == buttons['language_btn'][1]:
        user.language = ENG_LANG
    user.save()
    open_main_menu(message)


@bot.message_handler(
    func=lambda message: message and message.text in buttons['wish_list_btn'] or message.text in buttons[
        'back_from_wish'])
def open_wish_list(message):
    user = User.objects.get(id=message.chat.id)
    user.cur_wish_number = -1
    markup = types.ReplyKeyboardMarkup(row_width=1)
    i = 1
    for w in user.wishes:
        markup.add(types.KeyboardButton(str(i) + ')' + str(w) + ' 🔹'))
    markup.add(types.KeyboardButton('➕'))
    bot.send_message(message.chat.id, messages['wish_list'][User.objects.get(id=message.chat.id).language],
                     reply_markup=markup)


@bot.message_handler(func=lambda message: message and message.text.find(')'))
def open_wish(message):
    # TODO: fix invalid literal
    User.objects.get(id=message.chat.id).cur_wish_number = int(message.text[0]) - 1
    markup = types.ReplyKeyboardMarkup(row_width=1)
    button1 = types.KeyboardButton(buttons['status_btn'][User.objects.get(id=message.chat.id).language])
    button2 = types.KeyboardButton(buttons['deny_wish'][User.objects.get(id=message.chat.id).language])
    button3 = types.KeyboardButton(buttons['back_from_wish'][User.objects.get(id=message.chat.id).language])
    markup.add(button1, button2, button3)


@bot.message_handler(func=lambda message: message and message.text in buttons['settings_btn'])
def open_settings(message):
    markup = types.ReplyKeyboardMarkup(row_width=1)
    button1 = types.KeyboardButton(buttons['language_settings_btn'][User.objects.get(id=message.chat.id).language])
    button2 = types.KeyboardButton(buttons['info_btn'][User.objects.get(id=message.chat.id).language])
    button3 = types.KeyboardButton(buttons['back_from_settings'][User.objects.get(id=message.chat.id).language])
    markup.add(button1, button2, button3)
