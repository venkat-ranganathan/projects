//~Meghana Jain, Binghamton University
//EECE 287, Sophomore Design Lab

`timescale 1ns / 1ps

module GPP_Circuit(
    input [11:0] sw,
    input clk,btn,
    output [7:0] led
    );
    
    wire sw_in;
    
    PushButton_Debouncer PushButton_Debouncer_MPP_Circuit(
        .clk(clk),
        .PB(btn),
        .PB_up(sw_in)
        );

    MPP MPP_Circuit(
        .Input(sw[7:0]),
        .clk(clk),
        .step(sw_in),
        .instruction(sw[11:8]),
        .Result(led[7:0])
        );
endmodule
