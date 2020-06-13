from celery import shared_task 
from time import sleep
from django.core.mail import send_mail

@shared_task
def sleepy(duration):
    sleep(duration)
    return None

@shared_task
def send_email_task():
    send_mail('Celery task worked',
    'this is a clery task example. i have used a clery task to send email ',
    'rohit.kumar@comfyapp.com',
    ['psit.rahul93@gmail.com']
    )
    return None

@shared_task
def experiment():
    for i in range(1,100):
        send_email_task.delay()
    return None
