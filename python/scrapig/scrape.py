import os
import requests
from bs4 import BeautifulSoup

url = "https://unsplash.com/t/wallpapers" # replace with the website you want to scrape
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')
img_tags = soup.find_all('img')

urls = [img['src'] for img in img_tags]

for i, url in enumerate(urls[:10000]):
    response = requests.get(url)
    with open(f'image_{i}.jpg', 'wb') as f:
        f.write(response.content)
