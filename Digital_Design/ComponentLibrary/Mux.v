`timescale 1ns / 1ps

module mux #(parameter SIZE=2, parameter NUM_OUTPUTS=1)
(
	input [(SIZE-1):0] in,
	input [$clog2(SIZE)-1:0] sel,
	output out
);
	
	reg [SIZE:0] D;
	
	always @* 
		D <= in;

	assign out = D[sel];

endmodule
