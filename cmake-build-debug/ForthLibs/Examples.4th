
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


: TEST 13 . ;
