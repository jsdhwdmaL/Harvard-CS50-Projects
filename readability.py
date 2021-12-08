sentence = input("Text: ")
letternum = 0
wordnum = 0
sentencenum = 0;
for c in sentence:
    if c == ' ':
        wordnum = wordnum + 1
    elif c == '.' or c == '!' or c == '?':
        sentencenum = sentencenum + 1
    elif c.isupper() or c.islower():
        letternum = letternum + 1
wordnum = wordnum + 1
#print(wordnum)
#print(sentencenum)
#print(letternum)
tmp = 0.0588 * (letternum * 100 / wordnum) - 0.296 * (sentencenum * 100 / wordnum) - 15.8
index = int(tmp + 0.5)
if index >= 16:
    print("Grade 16+\n")
elif index < 1:
    print("Before Grade 1\n")
else:
    print("Grade ", end="")
    print(index)