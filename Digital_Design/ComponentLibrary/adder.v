`timescale 1ns / 1ps

module adder #(parameter SIZE = 2)
(
   	input [SIZE-1:0] a, b,
    output [SIZE-1:0] sum,
    input cin,
    output cout
);

  	assign {cout,sum} = a+b+cin;
  	
endmodule