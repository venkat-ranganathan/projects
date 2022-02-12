`timescale 1ns / 1ps

//counts from 0 to maximum (allowed by data size) then rolls over 
//counts when count=1 and resets to 0 on next clock cycle when reset=1

module UpCounter #(parameter SIZE = 2)
(
    input clk,
    input en,
    input reset,
    output reg [SIZE-1:0] cur_count
);
	
	initial
		assign cur_count = {SIZE{1'b0}};

    always @ (posedge clk)
        if (reset)
            cur_count <= {SIZE{1'b0}};
		else if (en) 
            cur_count <= cur_count + 1;

endmodule
