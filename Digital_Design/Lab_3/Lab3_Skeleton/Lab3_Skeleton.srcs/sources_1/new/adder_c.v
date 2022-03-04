`timescale 1ns / 1ps

module adder_c #(parameter SIZE = 4)
(
   	input [SIZE-1:0] a, b,
    output [SIZE-1:0] sum,
    input cin,
    output cout
);

  	assign {cout,sum} = a+b+cin;
  	
endmodule