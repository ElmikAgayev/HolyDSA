from typing import List

def generateParenthesis(n: int) -> List[str]:
    result = []

    def backtrace(s: str, open_count: int, closed_count: int):
        if len(s) >= 2*n:
            result.append(s)
            return
        
        if open_count < n:
            backtrace(s + "(", open_count + 1, closed_count)
        
        if closed_count < open_count:
            backtrace(s + ")", open_count, closed_count + 1)
        
    backtrace("", 0, 0)
    return result

print(generateParenthesis(3))