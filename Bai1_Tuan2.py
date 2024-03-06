'''
m: max (tim so lon nhat mang)
'''



# Nhap mang chua duoc sap xep
print("Nhap mang a: ", end='')
a = list(map(int, input().split()))

# Lay phan tu lon nhat mang a
# De tao mang phu, trong counting sort va prefix sum
m = max(a)

b = [0] * (m + 1)
c = [0] * (m + 1)

for i in a: # Counting Sort
    b[i] += 1 
    for x in range(i + 1, len(c)): # Prefix Sum
        c[x] += 1

# Mang luu lai so luong phan tu tuong ung voi index
print("Mang luu so luong cua so tuong ung index: ")
print(b)

# Mang luu lai vi tri index cua so sau khi sap xep
print("Mang luu vi tri bat dau cua so sau sap xep: ")
print(c)

# Xuat mang
for i in range(0, len(a)):
    while (b[i] > 0):
        a[c[i]] = i
        b[i] -= 1
        c[i] += 1

print("Mang a sau khi duoc sap xep: ")
print(a)