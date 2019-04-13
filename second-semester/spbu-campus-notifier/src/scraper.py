import time
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException, StaleElementReferenceException, TimeoutException
from selenium.webdriver.firefox.options import Options
from src.config import *
from src.models import Room


# two functions below are copypasted from http://www.obeythetestinggoat.com/how-to-get-selenium-to-wait-for-page-load-after-a-click.html
# they are purposed to wait until page is loaded after next button click

def wait_for(condition_function):
    start_time = time.time()
    while time.time() < start_time + DELAY:
        if condition_function():
            return True
        else:
            time.sleep(0.1)
    raise TimeoutException(msg=f'Timeout waiting for {condition_function.__name__}')


def click_through_to_new_page(browser, link_text):
    # may raise NoSuchElementException if button is not clickable on the last page
    link = browser.find_element_by_link_text(link_text)
    link.click()

    def link_has_gone_stale():
        try:
            # poll the link with an arbitrary call
            link.find_elements_by_id('doesnt-matter')
            return False
        except StaleElementReferenceException:
            return True

    wait_for(link_has_gone_stale)


class Scraper:
    def __init__(self):
        options = Options()
        options.headless = True
        self.driver = webdriver.Firefox(executable_path=BROWSER_PATH, options=options)
        self.authorize()

    def authorize(self):
        self.driver.get(BASE_URL)
        time.sleep(DELAY)  # give some time for browser to load the page completely
        try:
            username_field = self.driver.find_element_by_id('loginform-username')
            password_field = self.driver.find_element_by_id('loginform-password')
            username_field.send_keys(LOGIN)
            password_field.send_keys(PASSWORD)
            self.driver.find_element_by_name('login-button').click()
        except NoSuchElementException:
            pass

    def _current_page_data(self):
        try:
            rows = self.driver.find_element_by_tag_name('tbody').find_elements_by_tag_name('tr')
            for row in rows:
                columns = row.find_elements_by_tag_name('td')
                current = Room(
                    dormitory=int(columns[0].text.split("№")[-1].strip()),
                    room_number=columns[1].text,
                    available_female_beds=int(columns[2].text),
                    available_male_beds=int(columns[3].text),
                    fully_available_beds=int(columns[4].text),
                    capacity=int(columns[5].text),
                    id=columns[0].text + '_' + columns[1].text
                )
                current.save()
                current.save()
        except (StaleElementReferenceException, TimeoutException):
            return False
        return True

    def scrap(self):
        self.driver.get(BASE_URL)
        time.sleep(1)  # give some time for browser to load the page completely
        start_time = time.time()

        AMOUNT_OF_PARSED_PAGES = 0
        try:
            while True:  # this cycle is finite, because we have only finite amount of pages
                # and on the last page there is no button with text "»"

                if self._current_page_data():
                    AMOUNT_OF_PARSED_PAGES += 1  # we parsed another one page!

                click_through_to_new_page(self.driver, '»')  # catch NoSuchElementException here
        except (NoSuchElementException, TimeoutException):
            pass  # it was the last page cycle is broken now

        # print(f'--- {time.time() - start_time} seconds ---')  # TODO: don't output to console, move to logs
        # print(f'--- {AMOUNT_OF_PARSED_PAGES} pages and {len(data)} entries parsed ---')
