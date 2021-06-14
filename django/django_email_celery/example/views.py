from django.shortcuts import render
from django.http import HttpResponse
from .task import sleepy, send_email_task, experiment

# Create your views here.
def index(request ):
    experiment.delay()
    return HttpResponse('<h1>Task is Done but with experiment!</h1')
