"# Impact-Training" 

Problem Statement No. 2 :

There are ‘S’ seats divided into ‘M’ blocks in a Stadium. The first block of seats is dry, and each block after that alternates between dry and wet. There N number of people that need to be seated. Everyone wants to sit on a dry seat. But there are ‘k’ persons who can also sit on a wet seat. 
Your task is to seat N people to minimize the distance between the leftmost and the rightmost person. Also, there should not be any block of 15 or more unoccupied seats between the leftmost and rightmost person.

INPUT 
S = 100, N = 50, k = 5, M = 6
Seatblocks = [3, 10, 30, 5, 30, 22]

OUTPUT
49
Explanation
We can place 30 people in seats 14 to 43(in the dry block), 5 people ready to sit on a wet seat from 44 to 48 and the remaining 15 people can sit on 49 to 63. So the distance between the leftmost and the rightmost is 49.

