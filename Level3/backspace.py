class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        S2 = ""
        T2 = ""

        for char in S:
            if char == '#' and len(S) != 0:
                S2 = S2[:-1]
            else:
                S2 = S2 + char

        for char in T:
            if char == '#' and len(T) != 0:
                T2 = T2[:-1]
            else:
                T2 = T2 + char

        return S2 == T2
