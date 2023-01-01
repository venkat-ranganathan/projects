`timescale 1ns / 1ps

module Parallel_Load_Reg_8 #(parameter DataSize = 8) (
    input clk,load,
    input  [DataSize-1:0] d,
    output [DataSize-1:0] q
    );
    
    reg [DataSize-1:0] q = {DataSize{1'b0}};

   always @ (posedge clk)
        if (load) 
            q <= d;
        
endmodule
