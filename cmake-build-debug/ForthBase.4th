5 31 !
70 32 !
79 33 !
82 34 !
84 35 !
72 36 !
0 37 !
-1 38 !
-1 39 !

1 40 !
58 41 !
1 42 !
31 43 !
18 44 !
0 45 !
1 46 !
0 47 !
2 48 !
10 49 !
-1 50 !

1 51 !
59 52 !
1 53 !
40 54 !

0 55 !
-1 56 !
0 57 !
3 58 !
9 59 !
10 60 !

0 61 !
0 62!
0 63 !
2 64 !
10 65 !
-1 66 !

66 3 !
51 0 !

: CONTEXT 0 ;
: BASE 1 ;
: STATE 2 ;
: HERE 3 @ ;

: DUP 0 PICK ;
: DROP -1 ! ;
: OVER 1 PICK ;
: ROT 2 ROLL ;
: SWAP 1 ROLL ;

: NEGATE -1 XOR 1 + ;
: - NEGATE + ;
: MOD OVER OVER 3 ROLL 3 ROLL / * - ;

: OR OVER OVER XOR ROT ROT AND XOR ;
: NOT -1 XOR ;
: <0 31 RSHIFT ;
: >0 DUP <0 SWAP 0= OR NOT ;

: ABS DUP 31 RSHIFT DUP ROT ROT XOR SWAP - ;

: 0! 0 SWAP ! ;

: IMMIDIATE CONTEXT @ DUP @ 1 + + 1 SWAP ! ;
: [ STATE 0! ; IMMIDIATE
: ] 2 STATE ! ;

: BINARY 2 BASE ! ;
: DECIMAL 10 BASE ! ;
: HEX 16 BASE ! ;

: ALLOT HERE + 3 ! ;

: , HERE 1 ALLOT ! ;

: IF COMPILE ?BRANCH HERE 1 ALLOT ; IMMIDIATE
: THEN HERE SWAP ! ; IMMIDIATE
: ELSE COMPILE BRANCH HERE 1 ALLOT HERE ROT ! ; IMMIDIATE

: LITERAL STATE @ IF COMPILE LIT , THEN ; IMMIDIATE

