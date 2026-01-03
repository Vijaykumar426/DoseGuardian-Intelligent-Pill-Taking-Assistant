/* File Name : bytedefines.h */

#define SETBIT(WORD,BP) WORD|=(1<<BP)                                       // set a specific bit in a word
#define CLRBIT(WORD,BP) WORD&=~(1<<BP)                                      // clear a specific bit in a word
#define CPLBIT(WORD,BP) WORD^=(1<<BP)                                       // toggle a specific bit in a word
#define WRITEBIT(WORD,BP,BIT) WORD=(WORD&(~(1<<BP)))|(BIT<<BP)              // write given bit value at bit position
#define WRITENIBBLE(WORD,SBP,NIBBLE) WORD=(WORD&~(0xf<<SBP))|(NIBBLE<<SBP)  // write 4-bit nibble at position
#define WRITEBYTE(WORD,SBP,BYTE) WORD=(WORD&~(0xff<<SBP))|(BYTE<<SBP)       // write 8-bit byte at position
