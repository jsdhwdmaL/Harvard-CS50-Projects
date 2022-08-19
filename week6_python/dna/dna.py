#match DNA sequence

import csv
import sys
import random

def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    #read database
    da = sys.argv[1]
    cnt = 0 #number of people in the data
    idx = 0 #number of dna sections
    section = []
    with open(da) as data:
        reader1 = csv.reader(data)
        for row1 in reader1:
            idx = len(row1)-1
            if cnt == 0:
                for idd in range(1, len(row1)):
                    section.append(row1[idd])
            cnt += 1
    cnt -= 1
    names = [[] * (idx+1) for i in range(cnt)]
    cnt = 0
    data.close()
    with open(da) as dat:
        reader = csv.reader(dat)
        next(reader)
        for row in reader:
            names[cnt].append(row[0])
            for i in range(1, len(row)):
                names[cnt].append(row[i])
            cnt += 1

    #read dna sequence
    dna = []
    seq = sys.argv[2]
    with open(seq) as sequence:
        reader2 = csv.reader(sequence)
        for row2 in reader2:
            dna.append(row2[0])

    dnacount = []
    for i in range(0, idx):
        dnacount.append(find(dna[0], section[i]))
        #print(section[i])
    #print(dna[0])

    signal = False
    for i in range(0, cnt):
        if check(names[i], idx, dnacount):
            signal = True
            print(names[i][0])
            break
    if signal == False:
        print("No match")


def find(DNA, STR):
    """returns the maximum number of times that the STR consecutively repeats"""
    maxi = 0
    tmp = 0
    slen = len(STR)
    for i in range(len(DNA)):
        for j in range(slen):
            #print(DNA[i+j])
            if (i+j) < len(DNA) and DNA[i+j] != STR[j]:
                if tmp > maxi:
                    maxi = tmp
                tmp = 0
                break
        tmp += 1
        i += slen
    if tmp > maxi:
        maxi = tmp
    return maxi


def check(names, idx, dnacount):
    """returns if the sequence matches the person"""
    for i in range(1, idx + 1):
        if int(names[i]) != dnacount[i-1]:
            return False
    return True


if __name__ == "__main__":
    main()