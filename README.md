# Basic_Emulator
An emulator which performs basic operations on a stack of numbers through opcodes 

The machine understands the following actions:

-   Do nothing
-   Put a number on the stack
-   Remove the a number from the stack
-   Add the top  number to another
-   Subtract the top number with another
-   Jump to another place **if the top number is zero**
-   Jump to another place **no matter what**
-   Swap the top number on the stack with any other number on the stack

1. Do Nothing:
Opcode: 000
Info Bits: 5 (XXXXX)
In this operation the info bits are ignored. First the compiler sees the Opcode and
ignores the info bits. The info bits are just 00000.
2. Push a Number:
Opcode: 010
Info Bits: 5 (XXXXX)
In this operation the info bits will carry inside it a small number. This operation doesn’t
require any index as it just pushes the numbers it carries to the top of the stack. The info
bits can carry a number from 0 upto 31.
3. Remove a Number:
Opcode: 011
Info Bits: 5 (XXXXX)
In this operation the info bits are ignored again. The top number from the stack is
popped as soon as the compiler see the opcode. No other information is required.
4. Addition:
Opcode: 100
Info Bits: 5 (XXXXX)
In this operation the info bits store an index. This index accesses a number from the
stack and adds it to the top number of the stack.
5. Subtraction:
Opcode: 101
Info Bits: 5 (XXXXX)
In this operation the info bits store an index. This index accesses a number from the
stack and subtracts it from the top number of the stack.
6. Jump if Top is Zero:
Opcode: 110
Info Bits: 5 (XXXXX)
In this operation the info bits store an address. The operation checks if the top number
is 0. If true it jumps to the address mentioned in the info bits. Else it ignores the info bits.
7. Jump:
Opcode: 111
Info Bits: 5 (XXXXX)
In this operation the info bits store an address. The operation directly accesses the
index mentioned in the info bits and jumps to that address.
8. Swap:
Opcode: 001
Info Bits: 5 (XXXXX)
In this operation the info bits store a stack index. The operation accesses the number
stored in that index in the stack and swaps it with the number on the top of the stack. 

The emulator carries out the above operations. 
