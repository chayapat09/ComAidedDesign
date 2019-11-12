def find_match(operator,st):
    out = set()
    st_length = len(s)
    for i in operator:
        if len(i[0]) > st_length: continue
        if i[0][:st_length] == st:
            out.add(i)
    return out


def sep_string(s,var):
    operator = { ("sin(" , "(" )  ,
                 ("sinh(", "(" )  ,
                 ("cosh(", "(" )  ,
                 ("cos(" , "(" )  ,
                 ("("    , ""  )  ,
                 ("+"    , ""  )  ,
                 ("/"    , ""  )  ,
                 (var    , ""  ) }
    operand  = {'0','1','2','3','4','5','6','7','8','9','0','.'}
    out = []
    i = 0
    while i < len(s):# Add i++
        # 23.430
        if s[i] in operand:
            jood_count = 0
            for j in range(i+1,len(s)):
                if s[j] == '.':jood_count += 1
                if jood_count > 1:
                    raise ArithmeticError
                if s[j] not in operand:break
            out.append(s[i:j])
            i = j
            continue
        # sin(2x)
        match = operator # All are match
        for j in range(i+1,len(s)):
            next_match = find_match(s[i:j])
            if len(next_match) == 0:
                break
            match = next_match

        ''' lots bugs '''

def sep_string2(s): # fix var = x
    var = 'x'
    s = " " + s + " "
    operator = [ ("sinh(", " sinh ( " )  ,
                 ("sin(" , " sin ( "  )  ,
                 ("cosh(", " cosh ( " )  ,
                 ("cos(" , " cos ( "  )  ,
                 ("("    , " ( "      )  ,
                 (")"    , " ) "      )  ,
                 ("^"    , " ^ "      )  ,
                 ("+"    , " + "      )  ,
                 ("/"    , " / "      )  ,
                 ("*"    , " * "      )  ,
                 (var    , " " + var + " "  ) ]
    
    for i in operator:
        s = s.replace(i[0],i[1])
    return s.split()
    operand = {'0','1','2','3','4','5','6','7','8','9','.'}

print(sep_string2("2/sinh(s^2+(1))+cos(6)"))
print(sep_string2( "2sine(sinh(cosh(cosh(cos(2^x^x^x^cosh(32.33))))))" ) )
''' 
if ans[i] not corrected -> operator wrong
if ans[i] has multiple . -> numberic wrong
check in operator ?
if not operator -> check multiple .

'''