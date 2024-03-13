
# Nhap du lieu
s = input("Nhap xau: ")
print("Nhap tu dien: ", end ='')
wordDict = {x for x in input().split()}

# Tao mot dict luu tru ket qua
demo = {}

# Su dung ky thuat backtracking
def backTrack(start):
        # Neu start da den cuoi xau tra ve xau rong
        if start == len(s):
            return [""]
        if start in demo:
             return demo[start]
        
        # Tao mot list rong de luu lai cac xau tim duoc trong dict
        results = []
        for end in range(start + 1, len(s) + 1):
            word = s[start:end]
            if word in wordDict:
                # Tiep tuc tim cac tu con lai cua xau trong dict tu vi tri end
                for result in backTrack(end):
                    if result:
                        results.append(word + " " + result)
                    else:
                        results.append(word)
        # Luu ket qua vao demo
        demo[start] = results
        print(demo)
        return results

# In ra danh sach cac xau tim duoc
print(backTrack(0))