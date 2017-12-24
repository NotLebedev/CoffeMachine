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
3 62 !
9 63 !
0 64 !
1 65 !
4 66 !
0 67 !
3 68 !
10 69 !
0 70 !
0 71 !
0 72 !
2 73 !
10 74 !
-1 75 !

76 3 !
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
: 0< 31 RSHIFT ;
: 0> DUP 0< SWAP 0= OR NOT ;
: 0<> 0= NOT ;
: = - 0= ;
: <> - 0<> ;
: < - 0< ;
: > - 0> ;

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

: >MARK HERE 1 ALLOT ;
: >RESOLVE HERE SWAP ! ;

: <MARK HERE ;
: <RESOLVE , ;

: IF COMPILE ?BRANCH >MARK ; IMMIDIATE
: THEN >RESOLVE ; IMMIDIATE
: ELSE COMPILE BRANCH >MARK SWAP >RESOLVE ; IMMIDIATE

: BEGIN <MARK ; IMMIDIATE
: UNTIL COMPILE ?BRANCH <RESOLVE ; IMMIDIATE

: LITERAL STATE @ IF COMPILE LIT , THEN ; IMMIDIATE

: CONSTANT CREATE COMPILE LIT , -1 , ;
: VARIABLE HERE 1 ALLOT CREATE COMPILE LIT , -1 , ;

: ++! DUP @ 1 + SWAP ! ;
: --! DUP @ 1 - SWAP ! ;

: FOR <MARK ; IMMIDIATE
: DO COMPILE ?BRANCH >MARK ; IMMIDIATE
: LOOP COMPILE BRANCH SWAP <RESOLVE >RESOLVE ; IMMIDIATE

: SQRT  1 0
        FOR ROT DUP 0 > DO
            2 PICK -
            ROT 2 +
            ROT

            2 PICK 0 < IF
            ELSE

                1 +

            THEN

        LOOP
        DROP SWAP DROP ;




10 CONSTANT CR
32 CONSTANT BL
KEY " CONSTANT QUOTE

: WORD  HERE DUP 1 + ROT
        BEGIN

            KEY
            DUP
            2 PICK

            <> IF
                2 PICK !
                SWAP 1 + SWAP
                0
            ELSE
                DROP 1
            THEN
        UNTIL
        DROP OVER - 1 - OVER ! ;


: TYPE  DUP IF
            DUP @
            OVER + SWAP
            BEGIN

                1 +
                DUP @ EMIT

                OVER OVER =

            UNTIL
        THEN
        DROP DROP ;

: ( 41 WORD DROP ; IMMIDIATE

: " QUOTE WORD ; IMMIDIATE
: ." QUOTE WORD TYPE ;

: SIGN 0< IF 45 EMIT THEN ;
: DIGIT 10 MOD  48 + ;

VARIABLE DOTCOUNTER

: . DUP SIGN ABS
        0 DOTCOUNTER !
        BEGIN
            DUP
            DIGIT
            SWAP 10 /
            DOTCOUNTER ++!
            DUP 0=
        UNTIL
        DROP
        FOR DOTCOUNTER @ 0<> DO
            EMIT
            DOTCOUNTER --!
        LOOP
        BL EMIT ;

VARIABLE STRCOUNTER

: STR=
        OVER OVER @ SWAP @
        = IF

            DUP @ STRCOUNTER !

            BEGIN

                1 +
                SWAP
                1 +
                STRCOUNTER --!

                OVER OVER @ SWAP @ =
                STRCOUNTER @ 0<>
                AND NOT

            UNTIL

            STRCOUNTER @ 0= IF

                -1

            ELSE

                0

            THEN

        ELSE

        0

        THEN
        SWAP DROP SWAP DROP ;

: FIND  BL WORD
        CONTEXT @
        BEGIN

            OVER OVER
            STR= IF

                SWAP DROP -1

            ELSE

                DUP @ + 2 +

                @ DUP
                -1 = IF

                    SWAP DROP -1

                ELSE

                    0

                THEN

            THEN

        UNTIL ;

VARIABLE DUMPCOUNTER

: DUMP  0 DUMPCOUNTER !
        FOR DUP DUMPCOUNTER @ > DO

            OVER DUMPCOUNTER @ +

            @ .

            DUMPCOUNTER ++!

        LOOP ;

: FORGET    FIND
            DUP @ + 2 +
            @
            CONTEXT ! ;


( SOME EXAMPLES )


( AS THIS FORTH FEATURES RECURSION HERE IS RECURSIVE FIBONACHI EXAMPLE )
VARIABLE FIBTOP

10000 FIBTOP !

: FIBREC SWAP OVER + DUP FIBTOP @ < IF FIBREC THEN ;

: FIBONACHI_RECURSIVE 1 1 FIBREC SWAP DROP ;


( AND ITERATIVE WITH BRAND FOR DO LOOP LOOP )
VARIABLE I
VARIABLE T

: FIBONACHI_ITERATIVE T ! 0 I ! 1 1 FOR T @ I @ > DO SWAP OVER + I ++! LOOP SWAP DROP ;

( SOLUTION OF SQUARE EQUATIONS THREE DIGITS ON INPUT )

VARIABLE A
VARIABLE B
VARIABLE C

: SQSOLVE   C ! B ! A !
            A @ 0= IF ( bx + c = 0 )

                B @ 0<> IF ( c = 0 has no solutions )

                    C @ B @ / NEGATE

                THEN

            ELSE

                C @ 0<> IF ( ax^2 + bx + c = 0 )

                    B @ 0= IF ( ax^2 + c = 0 )

                        C @ A @ * 0 < IF ( NO SQRT FROM NEGATIVE NUMBERS )

                            C @ A @ / ABS SQRT

                            DUP NEGATE

                        THEN

                    ELSE ( ax^2 + bx + c = 0 )

                        B @ B @ * 4 A @ C @ * * - ( DESCRIMINANT )

                        DUP 0> IF

                            SQRT

                            DUP

                            B @ NEGATE +

                            A @ 2 * /

                            SWAP

                            B @ NEGATE SWAP -

                            A @ 2 * /

                        ELSE

                            DROP

                        THEN

                    THEN

                ELSE ( ax^2 + bx = 0 )

                    0

                    B @ A @ / NEGATE

                THEN

            THEN ;



