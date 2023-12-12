'''
Date: 2022-10-05 17:31:33
LastEditTime: 2023-10-19 08:52:33
'''
import requests


def get_public_ip():
    response = requests.get("https://api.ipify.org?format=json")
    if response.status_code == 200:
        data = response.json()
        return data["ip"]
    else:
        return None


public_ip = get_public_ip()
print(public_ip)
