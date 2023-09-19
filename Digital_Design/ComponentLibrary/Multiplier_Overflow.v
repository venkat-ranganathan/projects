`timescale 1ns / 1ps

module Multiplier_Overflow #(parameter SIZE = 2)
(
    input [SIZE-1:0] a, b,
    output [SIZE-1:0] product, 
    output overflow //If # of bits in product >  SIZE; overflow = 1
);

    wire [SIZE*2-1:0] full_product;

    assign full_product = a*b;
    assign product = full_product [SIZE-1:0];
    assign overflow =| full_product [SIZE*2-1:SIZE];
	
endmodule