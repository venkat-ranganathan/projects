`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/21/2020 07:40:27 PM
// Design Name: 
// Module Name: sseg_mux
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


module sseg_mux(
    input clk,
    input [3:0] leftmost,
    input [3:0] left_center,
    input [3:0] right_center,
    input [3:0] rightmost,
    input leftmost_dp,
    input left_center_dp,
    input right_center_dp,
    input rightmost_dp,

    output [3:0] data_out,
    output dp_out,
    output [3:0] anode
    );

    //internal registers
    reg [17:0] cycle_count;
    reg [1:0] current_display;
    reg [3:0] anode_sig;
    reg [3:0] data_sig;
    reg dp_sig;
    reg dp_sig_inv;

    //drive outputs from internal registers
    assign anode = anode_sig;
    assign data_out = data_sig;
    assign dp_out = dp_sig;

    always @ (posedge clk) //use clock for counter
    begin
        cycle_count <= cycle_count + 1;
    end

    always @ (posedge cycle_count[17]) //clock divider (100MHz / 2^17)
    begin
        current_display <= current_display + 1; //0 to 3
    end

    always @ (*) //cycle anodes
    begin
        case (current_display)
            2'b00: anode_sig <= 4'b0111; //anodes are active low
            2'b01: anode_sig <= 4'b1011;
            2'b10: anode_sig <= 4'b1101;
            default: anode_sig <= 4'b1110;
        endcase

    end

    always @ (*) //select output data and dp
    begin
        case(current_display) //data select
            2'b00: data_sig <= leftmost;
            2'b01: data_sig <= left_center;
            2'b10: data_sig <= right_center;
            default: data_sig <= rightmost;
        endcase

        case(current_display) //dp select
            2'b00: dp_sig_inv <= leftmost_dp;
            2'b01: dp_sig_inv <= left_center_dp;
            2'b10: dp_sig_inv <= right_center_dp;
            default: dp_sig_inv <= rightmost_dp;
        endcase

        dp_sig <= !dp_sig_inv; //dp active on 0, so input dp must be inverted
    end

endmodule
