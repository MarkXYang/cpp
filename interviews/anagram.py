def insertCharAtEveryIdx(potentialAnaList, currChar):
    anaList = []
    for aword in potentialAnaList:
        for idx in range(len(aword) + 1):
            new_word = aword[:idx] + currChar + aword[idx:]
            anaList.append(new_word)
    return anaList

def findAnagrams(word): 
    if len(word) == 1:
        potentialAnaList = []
        potentialAnaList.append(word)
        return potentialAnaList
    
    #anagramList = []
    ch = word[0]
    substr = word[1:]
    potentialAnaList = findAnagrams(substr)
    anagramList = insertCharAtEveryIdx(potentialAnaList, ch)

    return anagramList

def main():
    test_words = ["cat", "dog", "hello"]
    for word in test_words:
        print(f"Anagrams of '{word}':")
        anagrams = findAnagrams(word)
        for anagram in anagrams:
            print(anagram)
        print()  # Empty line for better readability

if __name__ == "__main__":
    main()
