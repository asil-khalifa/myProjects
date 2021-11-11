import random
def shuffle(n):
    s = ''
    while n!='':
        b =random.randrange(0, len(n))
        s += n[b]
        n = n[:b]+n[b+1:]
    return s.capitalize()

#len(k) = word of length whose factorial you want to find
def fact(k):
    for i in range(1, 5):
        s = 0
        for j in range(10**i):
            a = 1
            while True:
                if shuffle(k) == k.capitalize():
                    s += a
                    break
                a+=1
        if i ==1:
          print(f'{s/j} is close to {len(k)}!')
        else:
          print(f'{s/j} is even close to {len(k)}!')
    print('Conclusion: ', len(k), '! = ', int(round(s/j, 0)), sep = '')  
    
    
fact('yess') #returns 4!