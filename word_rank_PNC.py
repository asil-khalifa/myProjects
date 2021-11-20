def arrange(s):
    return ''.join(chr(ch) for ch in sorted([ord(var) for var in s.lower()]))
def unique(s):
    return ''.join(set([ch for ch in s]))
def fact(n):
    if n == 0:
        return 1
    else:
        return n*fact(n-1)
        
def rank(st, st_):
    rank = 0
    for ch in st_:  
        uniq_st = arrange(unique(st))
        for c in uniq_st[:uniq_st.find(ch)]:
            divisor = 1
            for chara in uniq_st:
                if chara !=c:
                    divisor *= fact(st.count(chara))
                else:
                    divisor *= fact(st.count(chara)-1)
            rank += fact(len(st) -1)/divisor
        st = st[:st.find(ch)]+st[st.find(ch)+1:]
    return int(rank+1)

st_ = input('Enter the word: ').lower()
st = arrange(st_)
print(rank(st, st_))