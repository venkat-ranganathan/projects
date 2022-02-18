`timescale 1ns / 1ps

module BitAnd2 #(parameter SIZE=8) // changed to 8-bit
(
   	input [SIZE-1:0] a, b,
      output [SIZE-1:0] out
);

   assign out = a & b;

endmodule