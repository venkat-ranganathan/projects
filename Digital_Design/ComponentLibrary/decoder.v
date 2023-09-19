`timescale 1ns / 1ps

module decoder #(parameter SIZE=2)
(
	input en,
	input [(SIZE-1):0] in,
	output [((2**SIZE)-1):0] out
);

	assign out = (en<<in);

endmodule