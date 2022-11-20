morse = { 
    '.-':'a','-...':'b','-.-.':'c','-..':'d','.':'e','..-.':'f',
    '--.':'g','....':'h','..':'i','.---':'j','-.-':'k','.-..':'l',
    '--':'m','-.':'n','---':'o','.--.':'p','--.-':'q','.-.':'r',
    '...':'s','-':'t','..-':'u','...-':'v','.--':'w','-..-':'x',
    '-.--':'y','--..':'z'
}

def solution(letter):
    letter_size = len(letter)
    i=0
    res = ""
    temp = ""
    
    while i < letter_size:
        if letter[i] != ' ':
            temp = temp + letter[i]
            i += 1
        else:
            for key, val in morse.items():
                if key == temp:
                    res = res + val
                    break
            i += 1
            temp = ""
    
    for key, val in morse.items():
        if key == temp:
            res = res + val
            break
                    
    return res
