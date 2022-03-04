`timescale 1ns / 1ps

// At the rising edge of the clk, if load = 1, loads d to q      
// If load = 1 and clr = 1, clears the register and sets the value to 0


module reg_4b #(parameter SIZE=4) // using 4bit register, so changed size to 4
(
    input clk,
    input load, clr,
    input [SIZE-1:0] d,
    output reg [SIZE-1:0] q
);

    always @ (posedge clk)
        if (load)
			if (clr) 
				q <= 0;
            else
			    q <= d;

endmodule
