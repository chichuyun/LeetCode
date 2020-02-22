class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
# method(1) 不用split, 判断太多导致效率很低
        p = list()
        temp = ""
        for s in path+'/':
            if s == "/":
                if temp:
                    if temp == '..':
                        if len(p) > 0:
                            del p[-1]
                    elif temp != '.':
                        p.append(temp)              
                temp = ""
            else:
                temp += s

        return '/'+'/'.join(p)
# method(2) split
'''
        names = path.split('/')
        pt = 0
        res = []
        for name in names:
            if(len(name)==0):
                continue
            if(name=='.'):
                continue
            if(name=='..'):
                if(len(res)>0):
                    del res[-1]
                continue
            res.append(name)
        ans = '/'.join(res)
        return '/'+ans
'''
