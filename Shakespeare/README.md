Usage: ./bard <input_file> <output_file>

Description: Each line of the input file corresponds to a new query. 
The query is a pair of numbers: LENGTH RANK. The first number is the length of the word,
the second number is the rank, which starts from 0. The ranking is done in
decreasing order of frequency, and increasing lexicographic order. Thus, if two
words have the same frequency, then the word that is earlier lexicographically
has the smaller (earlier) rank. So, “7 0” refers to the most frequent word of length 7. 
Or, “9 3” refers to the fourth most frequent word of length 9.
