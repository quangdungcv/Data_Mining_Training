import re

# Nhap mot xau url vao de kiem tra
url = input("Nhap url: ")

# Tim kiem trong xau vua roi co thoa man dieu kien cua 1 url
x = re.search(r"^(https?://)(www.)?[\w-]+(\.[a-z]{2,6})+\/([^\s]*)$", url)

# Neu khong tim duoc x se tra ve None, nguoc lai ta dung x.string de tra ve url
if x == None:
    print("url khong hop le")
else:
    print("url hop le: ", x.string) 