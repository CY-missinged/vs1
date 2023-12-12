from django.shortcuts import render, redirect
from django.http import HttpResponse
from .models import *
from django.contrib.auth.decorators import login_required

# Create your views here.

@login_required
def home(request):
    return render(request, 'homepage.html')

@login_required
def show_user(request):
    po = {
            'name': 'xiao po',
            'motto': 'i love kungfu',
            'email': 'po@disney.com',
            'region': 'Shaanxi',
            'pic': 'Po2.jpg'
            }
    return render(request, 'user.html', {'user': po})

@login_required
def show_status(request):
    statuses = Status.objects.all()
    # import pdb                  
    # pdb.set_trace()
    # return render(request, 'status.html')
    return render(request, 'status.html', {'statuses': statuses})

@login_required
def submit_post(request):
    user = WeChatUser.objects.get(user=request.user)
    text = request.POST.get('text')
    uploaded_file = request.FILES.get("pics")
    if uploaded_file:
        name = uploaded_file.name
        with open("./moments/static/image/{}".format(name), 'wb') as handle:
            for block in uploaded_file.chunks():
                handle.write(block)
    else:
        name = ''

    if text:
        status = Status(user=user, text=text, pics=name)   #注意此处有改动
        status.save()
        return redirect('/status')
    return render(request, 'my_post.html')