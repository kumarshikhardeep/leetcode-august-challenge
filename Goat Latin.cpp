class Solution:
    def toGoatLatin(self, S: str) -> str:
        res = ""
        words = S.strip().split(' ')
        # print (words)
        if words[0]=="":
            return ""
        a = "a"
        for word in words:
            
            c = word[0]
            if c=='a' or  c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or  c=='E' or c=='I' or c=='O' or c=='U':
                res += word + "ma" + a + ' '
                # print("a", res)
            else:
                res += word[1:] + word[0] + "ma" + a + ' '
                # print("b")
            a += "a"
            
        if res[-1] == ' ':
            return res[:-1]
        return res
