'''
Thus, it can be conjectured that every positive integer n in base 10 of the form 999...9*k-m, 
such that 1 < k < 9, m = 4-j, and j > 1,
 where j is the number of 9's composing the form of n, is either a palindromic number or belongs to this sequence.
 Source: https://oeis.org/A023108
 (Proven wrong, To do so call method2(6) )
'''
def method1():
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

def lycheral(a):
    a_ = a
    for i in range(5_000):
        a_ = a_ + int(str(a_)[::-1])
        if str(a_) == str(a_)[::-1]:
            print('Not a lycheral')
            print('It took', i+1, 'rounds')
            break
    else:
        print('Lycheral number')

def lycheral_(a):
    a_ = a
    for i in range(5_000):
        a_ = a_ + int(str(a_)[::-1])
        if str(a_) == str(a_)[::-1]:
            return False
    else:
        return True

def method2(n):
    s = '99'
    for i in range(n):
        for k in range(2, 9):
            lych = int(s)*k-(4-len(s))
            if lycheral_(lych) == False:
                print(lych, 'disobeys law;', 's=', s, 'k=', k, 'm=', 4-len(s))
        s += '9'

method2(6)
