'''
arr: array
l: left
r: right
x: target
m: mid
'''


# Nhap du lieu mang
print("Nhap mang a: ", end='')
a = [int(i) for i in input().split()]
print("Nhap mang b: ", end='')
b = [int(j) for j in input().split()]

# Ham tim kiem nhi phan
def binarySearch(arr, l, r, x):
    if r < l:
        return -1
    m = int(l + (r - l) / 2)
    if arr[m] == x:
        return m
    if arr[m] > x:
        return binarySearch(arr, l, m - 1, x)
    if arr[m] < x:
        return binarySearch(arr, m + 1, r, x)

# Mang moi luu tru gia tri phan giao cua 2 mang 
c = []
for i in a:
    if (binarySearch(b, 0, len(b) - 1, i) != -1):
        c.append(i)

print('Giao nhau cau 2 mang a va b:, ', c)
      