t = int(input())

for i in range(t):
    s = input()

    news=''
    news+=s[0]
    st=1
    
    while st<len(s) and int(s[st])-int(s[st-1])>=0:
        news+=s[st]
        st+=1
    
    if st<len(s):
        mini=s[st]
        
    while st<len(s):
        # 감소구간인데 증가
        if int(s[st])-int(s[st-1])>=0:
            news+=mini*(len(s)-st)
            st=len(s)
            
        else:
            # 감소
            if mini>s[st]:
                mini=s[st]
            news+=mini
            st+=1
            
    print(news)