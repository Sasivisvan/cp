#Roll No: CH.SC.U4AIE24084
#Name: SASI VISVAN C

def mult(s1, s2):
    if s1 == "0" or s2 == "0":
        return "0"

    is_negative = False
    if s1[0] == '-':
        is_negative = not is_negative
        s1 = s1[1:]
    if s2[0] == '-':
        is_negative = not is_negative
        s2 = s2[1:]

    i = 0
    while i < len(s1) and s1[i] == '0':
        i += 1
    s1 = s1[i:]

    j = 0
    while j < len(s2) and s2[j] == '0':
        j += 1
    s2 = s2[j:]

    if not s1 or not s2:
        return "0"

    n1, n2 = len(s1), len(s2)
    res = [0] * (n1 + n2)

    for i in range(n1 - 1, -1, -1):
        for j in range(n2 - 1, -1, -1):
            # Using int() directly!
            val1 = int(s1[i])
            val2 = int(s2[j])

            mul = val1 * val2

            p1 = i + j
            p2 = i + j + 1

            total = mul + res[p2]

            res[p2] = total % 10
            res[p1] += total // 10

    ans = []
    for val in res:
        if not (len(ans) == 0 and val == 0):
            # Using str() directly!
            ans.append(str(val))

    result_str = "".join(ans)

    if is_negative:
        result_str = "-" + result_str

    return result_str

print(mult("0033", "2"))
