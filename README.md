# Shortlisting_elligible_candidates-Trie-BST-File-Handling-OOPS-
*****This is a c++ program that gonna help to shortlist the applied candidates according to their CGPA******
Rules for selection
1) The student who comes first has some extra preference
2) The CGPA of the applicant should be at least 7.00 to get shortlisted
3) The rule says if an applicant has cgpa more than 7.5 then he would always be selected
4) There is a twist that if a candidate has less than 7.5 cgpa then we check for the current minimum value in the multimap, and if it is greter than current minimum then only we select
that candidate
5) If an applicant comes an apply but an applicant having more than or equal to CGPA already applied for the job then he won't be selected
6) There will be search options to check whether an applicant has been selected or not
7) There will be option if the user wants so print the list of applicants,the details of the students along with cgpa will be written on a word document(file handling)
8) There will be a certain no of shortlisted candidates let's say 20


Concepts used:
1) Object oriented programming for ease of implementation and easy understanding of the properties possessed by a candidate
1) self balancing binary search tree(Red black tree) which is included in map header file in C++(as there may be more than one  candidates with same name so we use a multimap)
2) File handling to write the applicants name into a word(or text) document
4) Trie data structure to check whether a student with a particular id applied before


**Explanation to "Why a trie data structure" has been used**:
we should take care that an applicant can not apply twice, so we provide an unique id number for each applicant.we store the id's on a trie data structure because the no of submitted applications may be very large so we can add the ids efficiently to a trie and
later on search for the same on an efficient manner. The id number consists of lowercase English letters(a-z)

How is Trie Implemented:
When we take id number as input we search in the trie whether it exists there or not , if doesn't exist then only we take input the further details and if already exists we don't proceed 
for further details of the candidate
