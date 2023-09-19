`timescale 1ns / 1ps

module Data_ALU(
    // Do not change input and output markers!
    input [7:0] A, B,
    input [2:0] Opsel,
    output [7:0] F
    );
    
wire [7:0] XOR, AND, OR, ADD, SUB, LSR, MUL; // need semicolon at end of wires
    
    mux8 mux8(
    .in0(B),
    .in1(XOR),
    .in2(AND),
    .in3(OR),
    .in4(ADD),
    .in5(SUB),
    .in6(LSR), // logical shift right
    .in7(MUL), // no comma on last one
    .sel(Opsel),
    .out(F)
    ); // closes function, need both parenthesis and semicolon
    
    BitXor2 BitXor2(
    .a(A),
    .b(B),
    .out(XOR)
    );
    
    BitAnd2 BitAnd2(
    .a(A),
    .b(B),
    .out(AND)
    ); 
    
    BitOr2 BitOr2(
    .a(A),
    .b(B),
    .out(OR)
    ); 
    
    adder Adder( // first name IS case-sensitive
    .a(A),
    .b(B),
    .cin(1'b0), // equivalent binary 0
    .cout(),
    .sum(ADD)
    ); 
    
    subtractor Subtractor( // first name IS case-sensitive
    .a(A),
    .b(B),
    .borrow(),
    .diff(SUB)
    ); 
    
    ShiftRightLogical LogicalShiftRight(
    .in(A),
    .out(LSR)
    ); 
    
    Multiplier Multiplier(
    .a(A),
    .b(B),
    .product(MUL)
    ); 
    
endmodule