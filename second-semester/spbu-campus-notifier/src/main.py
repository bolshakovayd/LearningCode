from mongoengine import *
from src.bot import bot

if __name__ == '__main__':
    # test_scrapping()
    connect(db='spbu-campus-notifier', host='localhost', port=27017)
    # scraper = Scraper()
    bot.polling(none_stop=True, interval=0)
