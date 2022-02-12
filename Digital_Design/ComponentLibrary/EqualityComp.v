`timescale 1ns / 1ps

module EqualityComp #(parameter SIZE=2)
(
	input [SIZE-1:0] a,b,
    output equal,
	output less_than,
	output greater_than
);

    assign equal = (a==b);
	assign less_than = (a<b);
	assign greater_than = (a>b);
	
endmodule