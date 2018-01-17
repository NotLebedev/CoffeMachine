( 	CONSTRUCTION OF MEMORY BEFORE LIST
	BUFFER SIZE | HEAD OFFSET | LENGTH | BUFFER | WORD )

: LIST ( n -> )
		HERE OVER 3 + ( n -> n, here, buffer + 3 )
		ALLOT ( n, here, buffer + 3 -> n, here )
		OVER OVER ( n, here -> n, here, n, here )
		! ( n, here, n, here -> n, here )
		0 OVER 1 + !
		0 OVER 2 + !
		SWAP DROP ( n, here -> here )
		CREATE COMPILE LIT , -1 , ;
		

: PUSHBACK 	( n, list -> status ) 
			
			DUP @ OVER 2 + @ = 
			IF ( If buffer size equals length )
				
				DROP DROP 0 ( n, list -> failed )
				
			ELSE
			
				DUP @ ( n, list -> n, list, size )
				OVER DUP 1 + @ SWAP 2 + @ ( n, list, size -> n, list, size, head ofs, length )
				+ SWAP MOD 3 + ( n, list, size, head ofs, length -> n, list, empty ofs )
				OVER + ( n, list, empty ofs -> n, list, empty adr )
				ROT SWAP ( n, list, empty adr -> list, n, empty adr )
				! ( list, n, empty adr -> list )
				2 + ( list -> length adr )
				++! ( length adr -> )
				-1 ( -> succes )
			
			THEN ;
			
: POPFRONT ( list -> n, status / status )
			
			DUP 2 + @ 0= 
			IF ( If list is empty )
			
				DROP 0 ( list -> failed )
				
			ELSE
			
				DUP DUP ( list -> list, list, list )
				1 + @ ( list, list, list -> list, list, head ofs )
				+ 3 + @ SWAP ( list, list, head ofs - > n, list )
				DUP 1 + @ 1 + ( n, list -> n, list, new head )
				OVER @ MOD ( n, list, new head -> n, list, new head corrected )
				OVER 2 + ( n, list, new head corrected -> n, list, new head corrected, length adr )
				--! ( n, list, new head corrected, length adr -> n, list, new head corrected )
				SWAP 1 + ! ( n, list, new head corrected -> n )
				-1 ( n -> n, succes )
			
			THEN ;

11 LIST L

: PUSH L PUSHBACK . L 50 DUMP ;
: POP L POPFRONT . . L 50 DUMP ;

13 PUSH 13 PUSH 13 PUSH POP POP POP
1 PUSH
2 PUSH
3 PUSH
4 PUSH
			
