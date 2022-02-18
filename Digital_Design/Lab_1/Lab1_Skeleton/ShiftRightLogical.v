`timescale 1ns / 1ps

module ShiftRightLogical #(parameter SIZE=8)
(
	input [SIZE-1:0] in,
    output [SIZE-1:0] out
);

    assign out = {1'b0, in[SIZE-1:1]};
	
endmodule