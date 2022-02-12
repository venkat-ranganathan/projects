//~Meghana Jain, Binghamton University
//EECE 287, Sophomore Design Lab

`timescale 1ns / 1ps

module Input_Select (
    input [7:0] Input, R_data_b,
    input use_input,
    output [7:0] B
    );
    
    assign B = use_input == 1 ? Input : R_data_b;
    
endmodule
