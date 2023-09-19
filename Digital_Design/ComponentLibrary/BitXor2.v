`timescale 1ns / 1ps

module BitXor2 #(parameter SIZE=2)
(
	input [SIZE-1:0] a, b,
    output [SIZE-1:0] out
);

    assign out = a^b;
	
endmodule