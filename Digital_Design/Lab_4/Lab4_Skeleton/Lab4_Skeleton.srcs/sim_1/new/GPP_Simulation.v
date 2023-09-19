`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/02/2019 08:37:43 PM
// Design Name: 
// Module Name: GPP_Simulation
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module GPP_Simulation(

    );
    reg [7:0] sw;
    reg clk,btn;
    wire [10:0] led;
    GPP_circuit uut(
        .sw(sw),
        .clk(clk),
        .btn(btn),
        .led(led)
        );
        initial 
            begin
                sw = 0;
                clk = 0;
                btn = 0;
            end
        always clk = #10 ~clk;
        initial begin
            sw = 8'h01;
            #100
            btn = 1'h1;
            #50
            btn = 1'h0;
            #100
            btn = 1'h1;
            #50
            btn = 1'h0;
            #100
            btn = 1'h1;
            #50
            btn = 1'h0;
           end 
        
        
    
endmodule
