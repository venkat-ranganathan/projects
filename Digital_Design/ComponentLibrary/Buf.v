`timescale 1ns / 1ps

module Buf #(parameter SIZE=2) 
(
	input [SIZE-1:0] in,
    output [SIZE-1:0] out
);

    assign out = in;

endmodule