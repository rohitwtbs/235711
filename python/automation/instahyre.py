from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
# Set up the browser driver (make sure you have the driver installed)
browser = webdriver.Chrome()
# Navigate to the login page
browser.get('https://instahyre.com/login')
# Find the email and password input fields and enter your credentials
email_input = browser.find_element(By.ID,'email')
email_input.send_keys('')
password_input = browser.find_element(By.ID,'password')
password_input.send_keys(By.ID,'')
# Submit the form by pressing Enter or clicking the login button
password_input.send_keys(Keys.ENTER)
# Alternatively, if there's a login button, you can click it instead:
# login_button = browser.find_element_by_id('login-button')
# login_button.click()
# Wait for the login process to complete (you may need to add more time or wait for a specific element)
browser.implicitly_wait(1000)
# Check that you're logged in (you may need to modify this depending on the website)
# assert 'Welcome' in browser.page_source
# Close the browser
# browser.quit()
import pdb
pdb.set_trace()