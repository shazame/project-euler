/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 * 
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 20  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 * 
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * 
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 * 
 * Solution by: David
 * Answer: 669171001
 *
 * Comment : Pas de programme ici, résolution purement mathématique.
 *******************************/

Il suffit de remarquer que les nombres sur les diagonales peuvent être définis par récurrence :

Premier terme (centre de la spirale) : u(0) = 1

Diagonale bas droite :  u(n + 1) - u(n) = 2 + 8 * n  soit  u(n) = 2 * n + 1 + 4 * n * (n - 1)
Diagonale bas gauche :  u(n + 1) - u(n) = 4 + 8 * n  soit  u(n) = 4 * n + 1 + 4 * n * (n - 1)
Diagonale haut gauche : u(n + 1) - u(n) = 6 + 8 * n  soit  u(n) = 6 * n + 1 + 4 * n * (n - 1)
Diagonale haut droite : u(n + 1) - u(n) = 8 + 8 * n  soit  u(n) = 8 * n + 1 + 4 * n * (n - 1)

(n correspond au rayon de la spirale sur laquelle se trouve le nombre)
(0 correspond au nombre qui est au centre)

On fait alors la somme de ces nombres pour n de 1 à r
(où r est le rayon de la spiral, c'est-à-dire r=500 pour une spirale 1001*1001)
et on trouve la formule :
S(r) = 1 + 4*r + 2*r*(r+1) + 8/3*r*(r+1)*(2*r+1)

On peut vérifier que pour une spirale 5*5 :
S(2) = 101

Le résultat que l'on cherche est donc :
S(500) = 669171001
