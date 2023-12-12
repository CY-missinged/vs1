"""
Date: 2023-10-24 21:57:34
LastEditTime: 2023-10-24 22:06:56
"""
"""wechat URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from moments.views import *
from django.contrib.auth.views import LoginView, LogoutView

urlpatterns = [
    path("admin/", admin.site.urls),
    # path('', home),
    path('', LoginView.as_view(template_name='homepage.html')),
    path('user', show_user),
    path('status', show_status),
    path('post', submit_post),
    path('exit', LogoutView.as_view(next_page='/'))
]
