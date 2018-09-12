class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        list_str = []
        for x in range(1,n+1):
            if(x%15==0):
                list_str.append("FizzBuzz")
            elif(x%3==0):
                list_str.append("Fizz")
            elif(x%5==0):
                list_str.append("Buzz")
            else:
                list_str.append(str(x))
        return list_str
