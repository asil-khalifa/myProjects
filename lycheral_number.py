a = 89
while True:
    a_ = a
    for i in range(5_000):
        a_ = a_ + int(str(a_)[::-1])
        if str(a_) == str(a_)[::-1]:
            break
    else:
        print(a, 'is a lycheral number')
    a += 1