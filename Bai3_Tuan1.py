'''
arr: array
l: left
r: right
x: target
'''


# Nhap mang cac so cach nhau boi dau cach
a = list(map(int, input("Nhap mang a: ")))
x = int(input("So can tim"))

# Dung BSL(binary search left) de tim cac so bang x con ben trai (dau tien)
def BSL(arr, l, r, x):
    result = -1
    while r >= l:
        m = l + (r - l) // 2
        if arr[m] < x:
            l = m + 1
        elif arr[m] > x:
            r = m - 1
        else:
            result = m
            r = m - 1  
    return result

# Dung BSR(binary search right) de tim cac so x con ben phai (cuoi cung)
def BSR(arr, l, r, x):
    result = -1
    while r >= l:
        m = l + (r - l) // 2
        if arr[m] < x:
            l = m + 1
        elif arr[m] > x:
            r = m - 1
        else:
            result = m
            l = m + 1
    return result

print("Vi tri dau tien cua x la: ", BSL(a, 0, len(a) - 1, x))
print("Vi tri cuoi cung cua x la: ", BSR(a, 0, len(a) - 1, x))
