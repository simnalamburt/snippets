class Type:
    def __init__(self):
        self.object = [0]

    def call(self):
        self.object[0] += 2
        return self.object

instance = Type()

a = instance.call()
print(a)
b = instance.call()
print(a, b)

# [2]
# [4] [4]
