prime_numbers = [2]
n =int(input('Enter no. upto which search should be done:'))
s_ =3
def pn_add(s, s_):
    prime_numbers.append(i)
    if s== s_+2:
        print(s_, s)
        s_ = s
    else:
        s_ = s
    return s_, s
for i in range(3, n+1):
    if int(i**0.5)>prime_numbers[-1]:
        for j in range(2, int(i**0.5)):
            if i%j == 0:
                break
        else:
            s_, s = pn_add(i, s_)
    else:
        for pn in prime_numbers:
            if i%pn:
                break
        else:
            s_, s = pn_add(i, s_)
            
            
print(prime_numbers)