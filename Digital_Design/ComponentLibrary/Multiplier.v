`timescale 1ns / 1ps

module Multiplier #(parameter SIZE = 2)
(
	input [SIZE-1:0] a, b, 
    output [SIZE*2-1:0] product
);

    assign product = a*b;
	
endmodule