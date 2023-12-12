"""
Date: 2023-10-24 21:57:48
LastEditTime: 2023-10-24 22:52:42
"""
from django.contrib import admin
from .models import *

# Register your models here.

admin.site.register(WeChatUser)
admin.site.register(Status)